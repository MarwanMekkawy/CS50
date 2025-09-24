document.addEventListener("DOMContentLoaded", () => {
  const parts = document.querySelectorAll(".site-title .name-part");
  let index = 0;
  function step() {
    if (index < parts.length) {
      parts[index].classList.add("visible");
      index++;
      setTimeout(step, 700);
      return;
    }

    setTimeout(() => {
      parts.forEach(p => p.classList.remove("visible"));
      index = 0;
      setTimeout(step, 500);
    }, 800);
  }
  step();
});