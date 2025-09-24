document.addEventListener("DOMContentLoaded", () => {
  const logo = document.querySelector(".Site_logo");

  setInterval(() => {
    logo.style.visabilty = "opacity 0.7s ease";
    logo.style.opacity = logo.style.opacity === "0" ? "1" : "0";
  }, 600);
});