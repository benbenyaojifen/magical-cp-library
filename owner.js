(function () {
  "use strict";

  const loginCard = document.getElementById("login-card");
  const loginForm = document.getElementById("login-form");
  const loginStatus = document.getElementById("login-status");
  const passwordInput = document.getElementById("owner-password");
  const dashboard = document.getElementById("dashboard");
  const dashboardStatus = document.getElementById("dashboard-status");
  const rangeSelect = document.getElementById("range");
  const refreshButton = document.getElementById("refresh");
  const logoutButton = document.getElementById("logout");
  const numberFormat = new Intl.NumberFormat();
  const regionNames = typeof Intl.DisplayNames === "function"
    ? new Intl.DisplayNames([navigator.language || "en"], { type: "region" })
    : null;

  function setView(authenticated) {
    loginCard.hidden = authenticated;
    dashboard.hidden = !authenticated;
    if (!authenticated) window.requestAnimationFrame(() => passwordInput.focus());
  }

  function setDashboardStatus(message, isError) {
    dashboardStatus.textContent = message;
    dashboardStatus.classList.toggle("error", Boolean(isError));
  }

  function emptyElement(element) {
    while (element.firstChild) element.removeChild(element.firstChild);
  }

  function displayLabel(label, kind) {
    if (kind === "countries" && regionNames && /^[A-Z]{2}$/i.test(label)) {
      try { return regionNames.of(label.toUpperCase()) || label; } catch { return label; }
    }
    if (kind === "referrers" && (!label || label === "Unknown")) return "Direct / unknown";
    return label || "Unknown";
  }

  function renderRankedList(id, rows, kind) {
    const list = document.getElementById(id);
    emptyElement(list);
    if (!rows.length) {
      const item = document.createElement("li");
      const label = document.createElement("span");
      label.className = "empty-row";
      label.textContent = "No activity in this range";
      item.appendChild(label);
      list.appendChild(item);
      return;
    }
    rows.forEach((row) => {
      const item = document.createElement("li");
      const label = document.createElement("span");
      const count = document.createElement("strong");
      label.textContent = displayLabel(row.label, kind);
      label.title = label.textContent;
      count.textContent = `${numberFormat.format(row.visitors)} visitors`;
      item.append(label, count);
      list.appendChild(item);
    });
  }

  function renderPages(rows) {
    const body = document.getElementById("pages-list");
    emptyElement(body);
    if (!rows.length) {
      const row = document.createElement("tr");
      const cell = document.createElement("td");
      cell.colSpan = 3;
      cell.className = "empty-row";
      cell.textContent = "No page activity in this range";
      row.appendChild(cell);
      body.appendChild(row);
      return;
    }
    rows.forEach((entry) => {
      const row = document.createElement("tr");
      const page = document.createElement("td");
      const visitors = document.createElement("td");
      const views = document.createElement("td");
      page.textContent = entry.label;
      page.title = entry.label;
      visitors.textContent = numberFormat.format(entry.visitors);
      views.textContent = numberFormat.format(entry.pageviews);
      row.append(page, visitors, views);
      body.appendChild(row);
    });
  }

  function renderDashboard(data) {
    const visitors = Number(data.totals?.visitors) || 0;
    const pageviews = Number(data.totals?.pageviews) || 0;
    document.getElementById("metric-visitors").textContent = numberFormat.format(visitors);
    document.getElementById("metric-pageviews").textContent = numberFormat.format(pageviews);
    document.getElementById("metric-depth").textContent = visitors ? (pageviews / visitors).toFixed(1) : "0.0";
    renderPages(data.pages || []);
    renderRankedList("countries-list", data.countries || [], "countries");
    renderRankedList("referrers-list", data.referrers || [], "referrers");
    renderRankedList("devices-list", data.devices || [], "devices");
    renderRankedList("browsers-list", data.browsers || [], "browsers");
    document.getElementById("privacy-copy").textContent = data.privacy;
    document.getElementById("updated-at").textContent = `Updated ${new Date(data.generatedAt).toLocaleString()}`;
    setDashboardStatus(`Showing the last ${data.range} days.`, false);
  }

  async function loadAnalytics() {
    refreshButton.disabled = true;
    rangeSelect.disabled = true;
    setDashboardStatus("Loading activity…", false);
    try {
      const response = await fetch(`/api/owner-analytics?range=${encodeURIComponent(rangeSelect.value)}`, {
        credentials: "same-origin",
        headers: { Accept: "application/json" },
      });
      const body = await response.json();
      if (response.status === 401) {
        setView(false);
        loginStatus.textContent = "Your owner session expired. Sign in again.";
        return;
      }
      if (!response.ok) throw new Error(body.error || "Activity could not be loaded.");
      renderDashboard(body);
    } catch (error) {
      setDashboardStatus(error instanceof Error ? error.message : "Activity could not be loaded.", true);
    } finally {
      refreshButton.disabled = false;
      rangeSelect.disabled = false;
    }
  }

  async function checkSession() {
    try {
      const response = await fetch("/api/owner-auth", { credentials: "same-origin", headers: { Accept: "application/json" } });
      const body = await response.json();
      setView(Boolean(body.authenticated));
      if (body.authenticated) await loadAnalytics();
      else if (!body.configured) loginStatus.textContent = "Owner access is not configured yet.";
    } catch {
      setView(false);
      loginStatus.textContent = "Owner sign-in is temporarily unavailable.";
    }
  }

  loginForm.addEventListener("submit", async (event) => {
    event.preventDefault();
    const submitButton = loginForm.querySelector("button[type='submit']");
    submitButton.disabled = true;
    loginStatus.textContent = "Checking passphrase…";
    try {
      const response = await fetch("/api/owner-auth", {
        method: "POST",
        credentials: "same-origin",
        headers: { "Content-Type": "application/json", Accept: "application/json" },
        body: JSON.stringify({ password: passwordInput.value }),
      });
      const body = await response.json();
      if (!response.ok) throw new Error(body.error || "Sign-in failed.");
      passwordInput.value = "";
      loginStatus.textContent = "";
      setView(true);
      await loadAnalytics();
    } catch (error) {
      loginStatus.textContent = error instanceof Error ? error.message : "Sign-in failed.";
      passwordInput.select();
    } finally {
      submitButton.disabled = false;
    }
  });

  refreshButton.addEventListener("click", loadAnalytics);
  rangeSelect.addEventListener("change", loadAnalytics);
  logoutButton.addEventListener("click", async () => {
    await fetch("/api/owner-auth", { method: "DELETE", credentials: "same-origin" }).catch(() => {});
    setView(false);
    loginStatus.textContent = "Signed out.";
  });

  checkSession();
})();
