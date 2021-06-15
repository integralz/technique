const weather = document.querySelector(".js-weather");
const API_KEY = "2ba62f2971b11f95c708fb36ad522bfd";
var a, b;

function getweather(lat, lng){
    fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lng}&appid=${API_KEY}&units=metric`)
    .then(function(response){
        return response.json();
    })
    .then(function(json){
        const temperature = json.main.temp;
        const place = json.sys.country;
        const weather_description = json.weather[0].main;
        const image = json.weather[0].icon;
        weather.innerHTML = `<div>${temperature} @ ${weather_description} @ ${place}</div>`+
        `<img src = "http://openweathermap.org/img/wn/${image}@2x.png"/>`;
    });
}


function success(pos){
    var crd = pos.coords;
    a = crd.latitude;
    b = crd.longitude;
    getweather(a,b);
}
function error(err){
    alert(err.message);
}

function init(){
    navigator.geolocation.getCurrentPosition(success, error);  
}

init();