var express = require("express");
var app = express();
var mysql = require("mysql");
var parser = require("body-parser");

var server = app.listen(process.env.PORT||8000, function(){
	console.log("CONNECTED TO PORT 8000");
});

app.use(parser.json());
app.use(parser.urlencoded({ extended: true }));

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

app.get("/selectall", function(req, res){
	conn.query("SELECT * FROM laptop", function(err, result){
		if(err) throw err;
		console.log(res);
		res.send(result);
	});
});

app.get("/delete.html", function(req, res){
	res.sendFile(__dirname+"/delete.html");
});

app.get("/index.html", function(req, res){
	res.sendFile(__dirname+"/index.html");
});

app.get("/insert.html", function(req, res){
	res.sendFile(__dirname+"/insert.html");
});

app.get("/select.html", function(req, res){
	res.sendFile(__dirname+"/select.html");
});

app.get("/update.html", function(req, res){
	res.sendFile(__dirname+"/update.html");
});


function exe(cod){
	conn.query(cod, function(err, res){
		if(err) throw err;
		console.log(res);
	});
}

exe('CREATE TABLE IF NOT EXISTS laptop(\
	id INT NOT NULL AUTO_INCREMENT,\
	cpu VARCHAR(20),\
	gpu VARCHAR(20),\
	ram VARCHAR(20),\
	mem VARCHAR(20),\
	resx INT,\
	resy INT,\
	PRIMARY KEY (id))');

app.post("/insert", function(req, res){
	var arr = [[req.body.cpu, req.body.gpu, req.body.ram, req.body.mem, req.body.resx, req.body.resy]];
	conn.query("INSERT INTO laptop (cpu, gpu, ram, mem, resx, resy) VALUES ?", [arr], function(err, results){
		if(err)
			throw err;
		console.log(results);
	});
	res.end();
});
