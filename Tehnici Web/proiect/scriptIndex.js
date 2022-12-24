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

const timeout=setTimeout(rez,10000);
var rezumat=document.getElementsByClassName("rezumat")[0];
console.log(rezumat);
function rez() {
    p=document.createElement("p");
    p.innerHTML="<b>Citesti rezumatul de mai mult de 10 secunde!</b>";
    console.log(p);
    rezumat.append(p);
}

var login=document.getElementById("login");
login.onclick=function() {
	document.getElementById('id01').style.display='block';}

var close=document.getElementById("close");
close.onclick=function() {
	document.getElementById('id01').style.display='none';}

	var modal = document.getElementById('id01');

window.onclick = function(event) {
  if (event.target == modal) {
    modal.style.display = "none";
  }
}