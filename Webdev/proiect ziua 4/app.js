var express = require("express");
var app = express();
var mysql = require("mysql");
var parser = require("body-parser");

var server = app.listen(process.env.PORT||8000, function(){
	console.log("CONNECTED TO PORT 8000");
});

app.use(parser.json());
app.use(parser.urlencoded({ extended: true }));

app.get("/login.html", function(req, res){
	res.sendFile(__dirname+"/login.html");
});

app.get("/register.html", function(req, res){
	res.sendFile(__dirname+"/register.html");
});

app.get("/quiz.html", function(req, res){
	res.sendFile(__dirname+"/quiz.html");
});

app.get("/leaderboards.html", function(req, res){
	res.sendFile(__dirname+"/leaderboards.html");
});


app.get("/selectall", function(req, res){
	conn.query("SELECT * FROM quiz", function(err, result){
		if(err) throw err;
		console.log(res);
		res.send(result);
	});
});

app.post("/update", function(req, res){
	var score = req.body.score;
	var id = req.body.id;
	var sql = "UPDATE quiz SET score = "+score+" WHERE id = "+id;
	conn.query(sql, function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});

var conn = mysql.createConnection({
	host: "localhost",
	user: "root",
	password: "rootpass",
	database: "mydb"
});

conn.connect(function(err){
	if(err)throw err;
	console.log("Connected to mysql");
});

app.post("/insert", function(req, res){
	var arr = [[req.body.user, req.body.pass]];
	conn.query("INSERT INTO quiz (username, password) VALUES ?", [arr], function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});

function exe(cod){
	conn.query(cod, function(err, res){
		if(err) throw err;
		console.log(res);
	});
}


exe('CREATE TABLE IF NOT EXISTS quiz(\
	id INT NOT NULL AUTO_INCREMENT,\
	username VARCHAR(20),\
	password VARCHAR(20),\
	score INT DEFAULT 0,\
	PRIMARY KEY (id))');

