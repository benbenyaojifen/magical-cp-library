(function () {
  "use strict";

  const PAGE_SIZE = 80;
  const savedKey = "magical-cp-community-saved";
  const themeKey = "magical-cp-theme";
  const list = document.getElementById("implementation-list");
  const search = document.getElementById("community-search");
  const summary = document.getElementById("result-summary");
  const loadMore = document.getElementById("load-more");
  const savedOnly = document.getElementById("saved-only");
  const sourceFilter = document.getElementById("source-filter");
  const languageFilters = document.getElementById("language-filters");
  const viewerEmpty = document.getElementById("viewer-empty");
  const viewerContent = document.getElementById("viewer-content");
  const sourceCode = document.getElementById("source-code");
  const numberFormat = new Intl.NumberFormat();
  const bundleCache = new Map();
  let manifest = null;
  let sourcesById = new Map();
  let filtered = [];
  let selected = null;
  let selectedCode = "";
  let language = "All";
  let visibleCount = PAGE_SIZE;
  let sourceController = null;
  let saved = readSaved();

  function currentTheme() {
    return document.documentElement.dataset.theme === "moon" ? "moon" : "day";
  }

  function updateThemeButton() {
    const button = document.getElementById("theme-toggle");
    const label = document.getElementById("theme-label");
    const isMoon = currentTheme() === "moon";
    button.setAttribute("aria-pressed", String(isMoon));
    button.setAttribute("aria-label", `Switch to ${isMoon ? "day" : "moon"} theme`);
    label.textContent = isMoon ? "Day" : "Moon";
    document.querySelector('meta[name="theme-color"]').setAttribute("content", isMoon ? "#10151f" : "#efe7d7");
  }

  function toggleTheme() {
    const next = currentTheme() === "moon" ? "day" : "moon";
    document.documentElement.dataset.theme = next;
    try { localStorage.setItem(themeKey, next); } catch { /* Preferences are optional. */ }
    updateThemeButton();
  }

  function readSaved() {
    try {
      const value = JSON.parse(localStorage.getItem(savedKey) || "[]");
      return new Set(Array.isArray(value) ? value.filter((item) => typeof item === "string") : []);
    } catch {
      return new Set();
    }
  }

  function writeSaved() {
    localStorage.setItem(savedKey, JSON.stringify(Array.from(saved)));
    document.getElementById("saved-count").textContent = numberFormat.format(saved.size);
  }

  function normalize(value) {
    return String(value || "").trim().toLowerCase();
  }

  function sourceFor(entry) {
    return sourcesById.get(entry.sourceId);
  }

  function sourceUrl(entry) {
    const source = sourceFor(entry);
    if (!source) return "#";
    const encodedPath = entry.sourcePath.split("/").map(encodeURIComponent).join("/");
    return `${source.repository}/blob/${source.commit}/${encodedPath}`;
  }

  function currentDayIndex(length) {
    const date = new Date();
    const key = `${date.getUTCFullYear()}-${date.getUTCMonth() + 1}-${date.getUTCDate()}`;
    let hash = 2166136261;
    for (const character of key) {
      hash ^= character.charCodeAt(0);
      hash = Math.imul(hash, 16777619);
    }
    return Math.abs(hash) % Math.max(1, length);
  }

  function setupFilters() {
    const counts = manifest.summary.languages;
    for (const [label, count] of Object.entries(counts).sort((a, b) => b[1] - a[1])) {
      const button = document.createElement("button");
      button.type = "button";
      button.dataset.language = label;
      button.append(document.createTextNode(`${label} `));
      const badge = document.createElement("span");
      badge.textContent = numberFormat.format(count);
      button.appendChild(badge);
      languageFilters.appendChild(button);
    }

    for (const source of manifest.sources) {
      const option = document.createElement("option");
      option.value = source.id;
      option.textContent = `${source.name} · ${numberFormat.format(source.implementationCount)}`;
      sourceFilter.appendChild(option);
    }
  }

  function renderCounts() {
    const data = manifest.summary;
    document.getElementById("implementation-count").textContent = numberFormat.format(data.implementations);
    document.getElementById("problem-count").textContent = numberFormat.format(data.problems);
    document.getElementById("language-count").textContent = numberFormat.format(Object.keys(data.languages).length);
    document.getElementById("source-count").textContent = numberFormat.format(data.sources);
    document.getElementById("all-count").textContent = numberFormat.format(manifest.entries.length);
    writeSaved();
    setupFilters();
  }

  function applyFilters() {
    const query = normalize(search.value);
    filtered = manifest.entries.filter((entry) => {
      const source = sourceFor(entry);
      if (language !== "All" && entry.language !== language) return false;
      if (sourceFilter.value !== "All" && entry.sourceId !== sourceFilter.value) return false;
      if (savedOnly.checked && !saved.has(entry.id)) return false;
      if (!query) return true;
      return [entry.title, entry.slug, entry.category, entry.language, source?.name, source?.author]
        .some((value) => normalize(value).includes(query));
    });
    visibleCount = PAGE_SIZE;
    renderList();
  }

  function renderList() {
    list.replaceChildren();
    const fragment = document.createDocumentFragment();
    filtered.slice(0, visibleCount).forEach((entry, index) => {
      const source = sourceFor(entry);
      const button = document.createElement("button");
      button.type = "button";
      button.className = `implementation-card${selected && selected.id === entry.id ? " selected" : ""}`;
      button.setAttribute("aria-current", selected && selected.id === entry.id ? "true" : "false");
      button.addEventListener("click", () => selectEntry(entry));

      const number = document.createElement("span");
      number.className = "implementation-number";
      number.textContent = String(index + 1).padStart(4, "0");
      const copy = document.createElement("span");
      copy.className = "implementation-copy";
      const title = document.createElement("strong");
      title.textContent = entry.title;
      const meta = document.createElement("small");
      meta.textContent = `${entry.language} · ${source?.name || "Community"}${saved.has(entry.id) ? " · saved" : ""}`;
      copy.append(title, meta);
      const arrow = document.createElement("span");
      arrow.className = "implementation-arrow";
      arrow.textContent = "→";
      button.append(number, copy, arrow);
      fragment.appendChild(button);
    });
    list.appendChild(fragment);
    summary.textContent = `${numberFormat.format(filtered.length)} implementations match`;
    loadMore.hidden = visibleCount >= filtered.length;
  }

  async function loadEntryCode(entry, signal) {
    if (!bundleCache.has(entry.bundle)) {
      const response = await fetch(entry.bundle, { signal });
      if (!response.ok) throw new Error("Source unavailable");
      bundleCache.set(entry.bundle, await response.json());
    }
    const code = bundleCache.get(entry.bundle)?.[entry.bundleKey];
    if (typeof code !== "string") throw new Error("Source unavailable");
    return code;
  }

  async function selectEntry(entry, updateHash = true) {
    selected = entry;
    selectedCode = "";
    const source = sourceFor(entry);
    renderList();
    viewerEmpty.hidden = true;
    viewerContent.hidden = false;
    document.getElementById("viewer-title").textContent = entry.title;
    document.getElementById("viewer-language").textContent = `${entry.language} · ${entry.kind}`;
    document.getElementById("viewer-meta").textContent = `${numberFormat.format(entry.lines)} lines · ${source?.name || "credited community source"}`;

    const problemLink = document.getElementById("open-problem");
    problemLink.hidden = !entry.problemUrl;
    if (entry.problemUrl) problemLink.href = entry.problemUrl;
    document.getElementById("open-source").href = sourceUrl(entry);
    document.getElementById("notice-source").href = source?.repository || "#";
    document.getElementById("notice-source").textContent = source?.name || "a credited source";
    document.getElementById("notice-author").textContent = source?.author || "its contributors";
    document.getElementById("notice-license").href = source ? `./${source.licensePath}` : "./provenance.json";
    document.getElementById("notice-license").textContent = `${source?.license || "source"} licence`;

    const saveButton = document.getElementById("save-entry");
    saveButton.setAttribute("aria-pressed", String(saved.has(entry.id)));
    saveButton.textContent = saved.has(entry.id) ? "Saved" : "Save";
    sourceCode.textContent = "Loading source…";
    if (updateHash) history.replaceState(null, "", `#${encodeURIComponent(entry.id)}`);

    if (sourceController) sourceController.abort();
    sourceController = new AbortController();
    try {
      selectedCode = await loadEntryCode(entry, sourceController.signal);
      sourceCode.textContent = selectedCode;
    } catch (error) {
      if (error.name !== "AbortError") sourceCode.textContent = "// This source file could not be loaded.";
    }

    if (window.matchMedia("(max-width: 980px)").matches) {
      viewerContent.scrollIntoView({ behavior: "smooth", block: "start" });
    }
  }

  function chooseRandom() {
    const pool = filtered.length ? filtered : manifest.entries;
    if (pool.length) selectEntry(pool[Math.floor(Math.random() * pool.length)]);
  }

  async function loadManifest() {
    try {
      const response = await fetch("manifest.json");
      if (!response.ok) throw new Error("Archive unavailable");
      manifest = await response.json();
      sourcesById = new Map(manifest.sources.map((source) => [source.id, source]));
      renderCounts();
      applyFilters();
      const requestedId = decodeURIComponent(location.hash.slice(1));
      const requested = manifest.entries.find((entry) => entry.id === requestedId);
      const daily = manifest.entries[currentDayIndex(manifest.entries.length)];
      if (requested || daily) await selectEntry(requested || daily, Boolean(requested));
    } catch {
      summary.textContent = "The community solution bank could not be loaded right now.";
      summary.classList.add("error");
    }
  }

  search.addEventListener("input", applyFilters);
  savedOnly.addEventListener("change", applyFilters);
  sourceFilter.addEventListener("change", applyFilters);
  languageFilters.addEventListener("click", (event) => {
    const button = event.target.closest?.("[data-language]");
    if (!button) return;
    language = button.dataset.language;
    languageFilters.querySelectorAll("[data-language]").forEach((item) => item.classList.toggle("active", item === button));
    applyFilters();
  });
  loadMore.addEventListener("click", () => {
    visibleCount += PAGE_SIZE;
    renderList();
  });
  document.getElementById("random-pick").addEventListener("click", chooseRandom);
  document.getElementById("theme-toggle").addEventListener("click", toggleTheme);
  document.getElementById("daily-pick").addEventListener("click", () => {
    if (manifest?.entries.length) selectEntry(manifest.entries[currentDayIndex(manifest.entries.length)]);
  });
  document.getElementById("save-entry").addEventListener("click", () => {
    if (!selected) return;
    if (saved.has(selected.id)) saved.delete(selected.id);
    else saved.add(selected.id);
    writeSaved();
    renderList();
    const button = document.getElementById("save-entry");
    button.setAttribute("aria-pressed", String(saved.has(selected.id)));
    button.textContent = saved.has(selected.id) ? "Saved" : "Save";
  });
  document.getElementById("copy-code").addEventListener("click", async (event) => {
    if (!selectedCode) return;
    await navigator.clipboard.writeText(selectedCode);
    event.currentTarget.textContent = "Copied";
    setTimeout(() => { event.currentTarget.textContent = "Copy code"; }, 1400);
  });
  document.getElementById("download-code").addEventListener("click", () => {
    if (!selected || !selectedCode) return;
    const url = URL.createObjectURL(new Blob([selectedCode], { type: "text/plain;charset=utf-8" }));
    const anchor = document.createElement("a");
    anchor.href = url;
    anchor.download = selected.fileName || "solution.txt";
    anchor.click();
    setTimeout(() => URL.revokeObjectURL(url), 0);
  });
  window.addEventListener("keydown", (event) => {
    if (event.key === "/" && document.activeElement !== search) {
      event.preventDefault();
      search.focus();
    }
  });

  updateThemeButton();
  loadManifest();
})();
