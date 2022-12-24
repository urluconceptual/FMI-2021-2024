var tema="dark";

document.addEventListener("DOMContentLoaded", function(event) {
	var preferinta = (localStorage.getItem("data-theme") !== null);
    if(preferinta) {
		if (localStorage.getItem("data-theme")=="light") {
			var switchToTheme = "light";
			tema="light";
			document.documentElement.setAttribute("data-theme", switchToTheme);
		}
		
		if (localStorage.getItem("data-theme")=="dark") {
			var switchToTheme = "dark";
			tema="dark";
			document.documentElement.setAttribute("data-theme", switchToTheme);
		}
	}
	else {
    document.documentElement.setAttribute("data-theme", "dark");}
    var themeSwitcher1 = document.getElementById("light");
    var themeSwitcher2 = document.getElementById("dark");
    themeSwitcher1.onclick = function() {
    var switchToTheme = "light";
	tema="light";
    document.documentElement.setAttribute("data-theme", switchToTheme);
	localStorage.setItem("data-theme", tema);
  }
    themeSwitcher2.onclick = function() {
    var switchToTheme = "dark";
	tema="dark";
    document.documentElement.setAttribute("data-theme", switchToTheme);
	localStorage.setItem("data-theme", tema);
  }
})
/*
document.addEventListener('click', (event) => {
	alert("Treceti cursorul peste pozele cu personaje pentru a afla numele actorilor!");
	event.stopPropagation();
  }, false);
*/

document.onclick=function (event) {
	debugger;
	alert("Treceti cursorul peste pozele cu personaje pentru a afla numele actorilor!");
	event.stopPropagation();
	console.log("event");
	debugger;
}