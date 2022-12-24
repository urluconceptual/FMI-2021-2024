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

var coloana=document.getElementById("colgalerie");
var imagini=coloana.getElementsByTagName("img");
console.log(imagini);

function setBg () {
	const randomColor = Math.floor(Math.random()*16777215).toString(16);
	document.body.style.backgroundColor = "#" + randomColor;
  }

for(var i=0; i<imagini.length;i++) {
	imagini[i].onclick=function () {
		debugger;
		setBg();
		infoBg();
	}
}

function infoBg () {
	const element = document.getElementsByTagName("body")[0];
	const cssObj = window.getComputedStyle(element, null);
	let bgColor = cssObj.getPropertyValue("background-color");
	document.getElementById("culoare").innerHTML = "Culoarea fundalului actual este: "+bgColor;
}