(() => {
  const favoriteKey = "magical-cp-favorites";
  const recentKey = "magical-cp-recent";
  const themeKey = "magical-cp-theme";
  const solutionId = document.body.dataset.solutionId;
  const solutionPanel = document.querySelector("[data-solution-panel]");
  const learningPanel = document.querySelector("[data-learning-panel]");
  const practiceCard = document.querySelector("[data-practice-card]");
  const themeButton = document.querySelector("[data-theme-toggle]");
  const favoriteButton = document.querySelector("[data-favorite]");

  const readList = (key) => {
    try {
      const value = JSON.parse(localStorage.getItem(key) || "[]");
      return Array.isArray(value) ? value.filter((item) => typeof item === "string") : [];
    } catch {
      return [];
    }
  };

  const applyTheme = (theme) => {
    document.documentElement.dataset.theme = theme;
    if (themeButton) themeButton.textContent = theme === "moon" ? "☀ Daylight" : "☾ Moonlit";
  };

  const initialTheme = localStorage.getItem(themeKey) === "moon" ? "moon" : "day";
  applyTheme(initialTheme);

  themeButton?.addEventListener("click", () => {
    const next = document.documentElement.dataset.theme === "moon" ? "day" : "moon";
    localStorage.setItem(themeKey, next);
    applyTheme(next);
  });

  if (solutionId) {
    const recent = [solutionId, ...readList(recentKey).filter((id) => id !== solutionId)].slice(0, 6);
    localStorage.setItem(recentKey, JSON.stringify(recent));
  }

  const paintFavorite = () => {
    if (!favoriteButton || !solutionId) return;
    const saved = readList(favoriteKey).includes(solutionId);
    favoriteButton.textContent = saved ? "★ Saved" : "☆ Save";
    favoriteButton.setAttribute("aria-pressed", String(saved));
  };

  favoriteButton?.addEventListener("click", () => {
    if (!solutionId) return;
    const current = readList(favoriteKey);
    const next = current.includes(solutionId)
      ? current.filter((id) => id !== solutionId)
      : [...current, solutionId];
    localStorage.setItem(favoriteKey, JSON.stringify(next));
    paintFavorite();
  });
  paintFavorite();

  const showPractice = (enabled) => {
    if (!practiceCard || !solutionPanel || !learningPanel) return;
    practiceCard.hidden = !enabled;
    solutionPanel.hidden = enabled;
    learningPanel.hidden = enabled;
    document.querySelector("[data-practice-toggle]")?.setAttribute("aria-pressed", String(enabled));
  };

  document.querySelector("[data-practice-toggle]")?.addEventListener("click", () => showPractice(true));
  document.querySelector("[data-reveal-solution]")?.addEventListener("click", () => showPractice(false));

  document.querySelector("[data-wrap-code]")?.addEventListener("click", (event) => {
    const pre = solutionPanel?.querySelector("pre");
    if (!pre) return;
    const wrapped = pre.classList.toggle("wrap-code");
    event.currentTarget.textContent = wrapped ? "No wrap" : "Wrap";
    event.currentTarget.setAttribute("aria-pressed", String(wrapped));
  });

  document.querySelector("[data-copy-code]")?.addEventListener("click", async (event) => {
    const path = event.currentTarget.dataset.codePath;
    if (!path) return;
    try {
      const response = await fetch(path);
      if (!response.ok) throw new Error("Unable to load code");
      await navigator.clipboard.writeText(await response.text());
      event.currentTarget.textContent = "Copied";
      window.setTimeout(() => { event.currentTarget.textContent = "Copy code"; }, 1500);
    } catch {
      event.currentTarget.textContent = "Copy failed";
    }
  });

  const closeFullscreen = () => {
    solutionPanel?.classList.remove("fullscreen");
    document.body.classList.remove("no-scroll");
    const button = document.querySelector("[data-fullscreen]");
    if (button) {
      button.textContent = "Full screen";
      button.setAttribute("aria-pressed", "false");
    }
  };

  document.querySelector("[data-fullscreen]")?.addEventListener("click", (event) => {
    const fullscreen = solutionPanel?.classList.toggle("fullscreen") ?? false;
    document.body.classList.toggle("no-scroll", fullscreen);
    event.currentTarget.textContent = fullscreen ? "Close" : "Full screen";
    event.currentTarget.setAttribute("aria-pressed", String(fullscreen));
  });

  document.addEventListener("keydown", (event) => {
    if (event.key === "Escape") closeFullscreen();
  });
})();
