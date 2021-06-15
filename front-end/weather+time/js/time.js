const time = document.getElementById("time");

function gettime() {
    var now = new Date();
    var month = now.getMonth();
    var date = now.getDate();
    var day = now.getDay();
    var day_word = "";
    var hour = now.getHours();
    var minute = now.getMinutes();
    var second = now.getSeconds();
    
    if(day == 1){
        day_word = "일";
    }
    else if(day == 2){
        day_word = "월";
    }
    else if(day == 3){
        day_word = "화";
    }
    else if(day == 4){
        day_word = "수";
    }
    else if(day == 5){
        day_word = "목";
    }
    else if(day == 6){
        day_word = "금";
    }
    else{
        day_word = "토";
    }



    time.innerText = `${month + 1}월 ${date}일(${day_word})
    ${hour < 10? `0${hour}`: hour}:${minute < 10? `0${minute}`:minute}:${second < 10? `0${second}` : second}`;
}


function init() {
    setInterval(gettime, 1000);
}

init();
