const express = require('express');
const app = express();

//사용하기 위해서는 npm install --save mongoose
const mongoose = require("mongoose");

//기본적인 moongoose를 사용하기 위한 설정
mongoose.set('useNewUrlParser', true);
mongoose.set('useFindAndModify', false);
mongoose.set('useCreateIndex', true);
mongoose.set('useUnifiedTopology', true);
//내 어플리케이션 코드를 넣는다.
mongoose.connect('application code');
const db = mongoose.connection;
app.set('view engine', 'ejs');

//처음에 한번만 실행이 된다.(on)
db.once('open', function(){
    console.log('DB connected');
})

//계속하여 에러가 작동하면 에러메세지를 보낸다.(on)
db.on('error', function(err){
    console.log('DB ERROR :', err);
});


const port = 3001;
app.listen(port,function(){
    console.log('server on' + port);
});