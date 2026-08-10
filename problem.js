(() => {
  const favoriteKey = "magical-cp-favorites";
  const recentKey = "magical-cp-recent";
  const themeKey = "magical-cp-theme";
  const progressKey = "magical-cp-progress";
  const solutionId = document.body.dataset.solutionId;
  const solutionPanel = document.querySelector("[data-solution-panel]");
  const learningPanel = document.querySelector("[data-learning-panel]");
  const practiceCard = document.querySelector("[data-practice-card]");
  const themeButton = document.querySelector("[data-theme-toggle]");
  const favoriteButton = document.querySelector("[data-favorite]");
  const progressSelect = document.querySelector("[data-progress-status]");
  const validStatuses = ["Not started", "Solving", "Solved", "Review"];

  const readList = (key) => {
    try {
      const value = JSON.parse(localStorage.getItem(key) || "[]");
      return Array.isArray(value) ? value.filter((item) => typeof item === "string") : [];
    } catch {
      return [];
    }
  };

  const readProgress = () => {
    try {
      const value = JSON.parse(localStorage.getItem(progressKey) || "{}");
      return value && typeof value === "object" && !Array.isArray(value) ? value : {};
    } catch {
      return {};
    }
  };

  const applyTheme = (theme) => {
    document.documentElement.dataset.theme = theme;
    document.querySelector('meta[name="theme-color"]')?.setAttribute("content", theme === "moon" ? "#10151f" : "#efe7d7");
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
    favoriteButton.textContent = saved ? "Saved" : "Save";
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

  if (progressSelect && solutionId) {
    const progress = readProgress();
    const currentStatus = progress[solutionId];
    progressSelect.value = validStatuses.includes(currentStatus) ? currentStatus : "Not started";
    progressSelect.addEventListener("change", () => {
      const nextStatus = validStatuses.includes(progressSelect.value) ? progressSelect.value : "Not started";
      const nextProgress = readProgress();
      if (nextStatus === "Not started") delete nextProgress[solutionId];
      else nextProgress[solutionId] = nextStatus;
      localStorage.setItem(progressKey, JSON.stringify(nextProgress));
    });
  }

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

  const runner = document.querySelector("[data-problem-runner]");
  if (runner) {
    const language = runner.querySelector("[data-runner-language]");
    const mode = runner.querySelector("[data-runner-mode]");
    const code = runner.querySelector("[data-runner-code]");
    const input = runner.querySelector("[data-runner-input]");
    const expected = runner.querySelector("[data-runner-expected]");
    const submit = runner.querySelector("[data-runner-submit]");
    const loadButton = runner.querySelector("[data-load-solution]");
    const status = runner.querySelector("[data-runner-status]");
    const timing = runner.querySelector("[data-runner-timing]");
    const stdout = runner.querySelector("[data-runner-stdout]");
    const stderr = runner.querySelector("[data-runner-stderr]");
    const traceList = runner.querySelector("[data-runner-trace]");
    const traceHelp = runner.querySelector("[data-trace-help]");
    let libraryCode = "";

    const normalizeOutput = (value) => value.replace(/\r\n/g, "\n").split("\n").map((line) => line.trimEnd()).join("\n").trimEnd();
    const loadLibrarySolution = async () => {
      const codeUrl = runner.dataset.codeUrl;
      if (!codeUrl) return;
      loadButton.disabled = true;
      try {
        const response = await fetch(codeUrl);
        if (!response.ok) throw new Error("Unable to load solution");
        libraryCode = await response.text();
        language.value = "cpp";
        code.value = libraryCode;
      } catch {
        status.textContent = "Solution could not be loaded";
      } finally {
        loadButton.disabled = false;
      }
    };
    const paintTrace = (events) => {
      traceList.replaceChildren();
      const visible = Array.isArray(events) ? events.slice(0, 120) : [];
      traceList.hidden = visible.length === 0;
      for (const event of visible) {
        const item = document.createElement("li");
        const line = document.createElement("strong");
        line.textContent = `Line ${event.line}${event.function ? ` · ${event.function}()` : ""}`;
        const values = document.createElement("span");
        const locals = event.locals && typeof event.locals === "object" ? Object.entries(event.locals).map(([name, value]) => `${name} = ${value}`) : Array.isArray(event.values) ? event.values : [];
        values.textContent = locals.length ? locals.join(" · ") : "Executed";
        item.append(line, values);
        traceList.append(item);
      }
    };
    mode.addEventListener("change", () => {
      traceHelp.hidden = mode.value !== "trace";
      submit.textContent = mode.value === "trace" ? "Build execution timeline →" : mode.value === "debug" ? "Run with checks →" : "Compile & run →";
    });
    language.addEventListener("change", () => { if (language.value === "cpp" && !code.value.trim()) code.value = libraryCode; });
    loadButton.addEventListener("click", loadLibrarySolution);
    submit.addEventListener("click", async () => {
      if (!code.value.trim() || submit.disabled) return;
      submit.disabled = true;
      status.textContent = "Running in isolation…";
      timing.textContent = "";
      stdout.textContent = "Waiting for output…";
      stderr.textContent = "Waiting for diagnostics…";
      paintTrace([]);
      try {
        const response = await fetch("/api/run", { method: "POST", headers: { "Content-Type": "application/json" }, body: JSON.stringify({ language: language.value, mode: mode.value, code: code.value, inputs: [input.value] }) });
        const result = await response.json();
        if (!response.ok) throw new Error(result.error || "The isolated runner could not start.");
        const labels = { finished: "Finished", compile_error: "Compile error", runtime_error: "Runtime error", time_limit: "Time limit exceeded" };
        const verdict = result.status === "finished" && expected.value.trim() ? normalizeOutput(result.stdout || "") === normalizeOutput(expected.value) ? "Accepted" : "Wrong answer" : labels[result.status] || result.status || "Finished";
        status.textContent = verdict;
        status.dataset.verdict = verdict === "Accepted" ? "pass" : verdict === "Wrong answer" || result.status !== "finished" ? "fail" : "neutral";
        timing.textContent = `${result.compileMs || 0} ms compile · ${result.runMs || 0} ms run`;
        stdout.textContent = result.stdout || "No output";
        stderr.textContent = result.stderr || (result.status === "finished" ? "No compiler or runtime errors." : "No diagnostics returned.");
        paintTrace(result.trace);
        window.va?.("event", { name: "problem_code_run", data: { solution: solutionId, language: language.value, mode: mode.value, status: result.status } });
      } catch (error) {
        status.textContent = "Runner unavailable";
        status.dataset.verdict = "fail";
        stdout.textContent = "No output";
        stderr.textContent = error instanceof Error ? error.message : "The isolated runner could not start.";
      } finally {
        submit.disabled = false;
      }
    });
    loadLibrarySolution();
  }
})();
