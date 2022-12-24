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

var myQuestions = [
	{
		question: "1. În ce an a avut loc premiera filmului Taxi Driver?",
		answers: {
			a: '1970',
			b: '1976',
			c: '1980',
     		d: '1986'
		},
		correctAnswer: 'b'
	},
	{
		question: "2. Cine îl joacă pe anti-eroul filmului?",
		answers: {
			a: 'Robert De Niro',
			b: 'Christian Bale',
			c: 'Marlon Brando',
    		d: 'Robin Williams'
		},
		correctAnswer: 'a'
	},
  {
		question: "3. Travis își exprimă dezgustul față de mizeria orașului. Despre ce oraș este vorba?",
		answers: {
			a: 'Washington',
			b: 'Los Angeles',
			c: 'New York',
    		d: 'Chicago'
		},
		correctAnswer: 'c'
	},
  {
		question: "4. De ce lucrează Travis ca taximetrist?",
		answers: {
			a: 'pentru bani',
			b: 'din cauza insomniilor',
			c: 'pentru Betsy',
    		d: 'pentru a ajunge presedinte'
		},
		correctAnswer: 'b'
	},
  {
		question: "5. Cu cine se află Travis în conflict?",
		answers: {
			a: 'cu toata lumea',
			b: 'Betsy',
			c: 'Palentine',
    		d: 'cu mizeria orașului și cauzele acesteia'
		},
		correctAnswer: 'd'
	},
	{
		question: "6. Ce gen de film a inspirat povestea și tehnicile cinematografice?",
		answers: {
			a: 'Western',
			b: 'Romance',
			c: 'Fantasy',
    		d: 'Horror'
		},
		correctAnswer: 'a'
	},
	{
		question: "7. Ce film din 2019 preia concepte din Taxi Driver?",
		answers: {
			a: 'Parasite',
			b: 'The Informer',
			c: 'Joker',
    		d: 'Once Upon a Time in Hollywood'
		},
		correctAnswer: 'c'
	}
];

var quizContainer = document.getElementById('quiz');
var resultsContainer = document.getElementById('results');
var submitButton = document.getElementById('submit');

function generateQuiz(questions, quizContainer, resultsContainer, submitButton){
	function showQuestions(questions, quizContainer){
		var output = [];
		var answers;
		for(var i=0; i<questions.length; i++){
			answers = [];
			for(letter in questions[i].answers){
				answers.push(
					'<label>'
						+ '<input type="radio" name="question'+i+'" value="'+letter+'">'
						+ letter + ') '
						+ questions[i].answers[letter]
						+'<br>'
					+ '</label>'
				);
			}
			output.push(
				'<div class="intrebare">' + questions[i].question + '</div>'
				+ '<div class="raspuns">' + answers.join('') + '</div>'
			);
		}
		quizContainer.innerHTML = output.join('');
	}

	showQuestions(questions, quizContainer);

	function showResults(questions, quizContainer, resultsContainer){
		var answerContainers = quizContainer.querySelectorAll('.raspuns');
		var userAnswer = '';
		var numCorrect = 0;
		for(var i=0; i<questions.length; i++){
			userAnswer = (answerContainers[i].querySelector('input[name=question'+i+']:checked')||{}).value;
			if(userAnswer===questions[i].correctAnswer){
				numCorrect++;
				console.log(numCorrect);
				answerContainers[i].style.color = 'lightgreen';
			} 
			else{
				answerContainers[i].style.color = 'red';
			}
		}
		var rezultat=numCorrect + ' din ' + questions.length;
		resultsContainer.append(rezultat);
	}

	submitButton.onclick = function(){
		showResults(questions, quizContainer, resultsContainer);
	}

}
generateQuiz(myQuestions, quizContainer, resultsContainer, submitButton);

var coloana=document.getElementById("colgalerie");
var imagini=coloana.getElementsByTagName("img");
console.log(imagini);

function setBg () {
	const randomColor = Math.floor(Math.random()*16777215).toString(16);
	document.body.style.backgroundColor = "#" + randomColor;
	color.innerHTML = "#" + randomColor;
  }

for(var i=0; i<imagini.length;i++) {
	imagini[i].onclick=function () {
		setBg();
	}
}

var facts=['Scriptul, scris de Paul Schrader, este semi-autobiografic', 'La vremea la care a fost filmat, De Niro era inca destul de necunoscut cat sa treaca drept un taximetrist anonim', 'Jodie Foster avea 12 ani la vremea filamrilor', 'Scorsese apare intr-un cadru al filmului, ca client al lui Travis', 'Costurile de productie ale filmului au fost de doar 1.3mil dolari']

document.addEventListener('keydown', (event) => {
	var name = event.key;
	if(name==='f') {
	alert(facts[Math.trunc(Math.random()*5)]);
	}
  }, false);