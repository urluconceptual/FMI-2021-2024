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

setInterval(function() {
	p=document.getElementsByTagName("p");
	for(var i=0; i<12;i++) {
	const list = p[i].classList;
	list.add("bold");
	}
} , 3000);

setInterval(function () {
		p=document.getElementsByTagName("p");
		for(var i=0; i<12;i++) {
		const list = p[i].classList;
		list.remove("bold");
		}
	}, 9000)