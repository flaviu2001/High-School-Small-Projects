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

app.get("/index.html", function(req, res){
	res.sendFile(__dirname+"/index.html");
});

app.get("/admin.html", function(req, res){
	res.sendFile(__dirname+"/admin.html");
});

app.get("/selectall", function(req, res){
	conn.query("SELECT * FROM users", function(err, result){
		if(err) throw err;
		console.log(res);
		res.send(result);
	});
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
	var arr = [[req.body.first, req.body.last, req.body.user, req.body.pass]];
	conn.query("INSERT INTO users (first_name, last_name, username, password) VALUES ?", [arr], function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});

app.post("/update", function(req, res){
	var arr = req.body.id;
	conn.query("UPDATE users SET conns = conns+1 WHERE id = ?", arr, function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});

app.post("/updatex", function(req, res){
	var arr = req.body.id;
	conn.query("UPDATE users SET conns = conns+? WHERE conns >= 5", arr, function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});

app.post("/updatepass", function(req, res){
	var cid = req.body.id;
	var cpass = req.body.pass;
	var sql = "UPDATE users SET password = '"+cpass+"' WHERE id = "+cid;
	console.log(sql);
	conn.query(sql, function(err, results){
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


exe('CREATE TABLE IF NOT EXISTS users(\
	id INT NOT NULL AUTO_INCREMENT,\
	first_name VARCHAR(20),\
	last_name VARCHAR(20),\
	username VARCHAR(20),\
	password VARCHAR(20),\
	conns INT DEFAULT 0,\
	PRIMARY KEY (id))');

