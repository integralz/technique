//query로 받음 hello?namaeQuery=Kim이라면 req.query.nameQuery는 Kim
app.get('/hello', function (req, res) {
    res.render('hello', { name: req.query.nameQuery });
});
//:nameParam에 대해 값을 받음 hello/Kim이면 req.params.nameParam은 Kim
app.get('/hello/:nameParam', function (req, res) {
    res.render('hello', { name: req.params.nameParam });
});