var express = require("express");
var app = express();
var mysql = require("mysql");

var server = app.listen(process.env.PORT||8000, function(){
	console.log("CONNECTED TO PORT 8000");
});

app.get("/", function(req, res){
	res.sendFile(__dirname+"/index.html");
});

app.get("/page.html", function(req, res){
	res.sendFile(__dirname+"/page.html");
});

app.get("/nota.html", function(req, res){
	res.sendFile(__dirname+"/nota.html");
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

function exe(cod){
	conn.query(cod, function(err, res){
		if(err) throw err;
		console.log(res);
	});
}

exe("CREATE TABLE IF NOT EXISTS elevcnrv\
	(id INT,\
	 nume VARCHAR(20),\
	 prenume VARCHAR(20),\
	 clasa INT,\
	 nota_info INT)");

//exe("INSERT INTO elevcnrv(id, nume, prenume, clasa, nota_info) VALUES (1, 'Popescu', 'Mihai', 11, 8)")

app.get("/selectall", function(req, res){
	conn.query("SELECT * FROM elevcnrv", function(err, result){
		if(err) throw err;
		console.log(res);
		res.send(result);
	});
});

app.get("/selectall/:nota", function(req, res){
	conn.query("SELECT * FROM elevcnrv WHERE nota_info >= ?", 
		req.params.nota,
		function(err, result){
			if(err) throw err;
			console.log(res);
			res.send(result);
		});
});

app.get("/delete/:nota_info", function(req, res){
	conn.query("DELETE FROM elevcnrv WHERE nota_info < ?", 
		req.params.nota_info,
		function(err, result){
			if(err) throw err;
			console.log(res);
			res.send(result);
		});
});

app.get("/update/:nota_info", function(req, res){
	conn.query("UPDATE elevcnrv SET nota_info = nota_info-1 WHERE nota_info = ?", 
		req.params.nota_info,
		function(err, result){
			if(err) throw err;
			console.log(res);
			res.send(result);
		});
});

/*exe("INSERT INTO elevcnrv(id, nume, prenume, clasa, nota_info) VALUES (2, 'Popa', 'Andrei', 11, 4)");
exe("INSERT INTO elevcnrv(id, nume, prenume, clasa, nota_info) VALUES (3, 'Popa', 'Matei', 11, 10)");
exe("INSERT INTO elevcnrv(id, nume, prenume, clasa, nota_info) VALUES (4, 'Popa', 'Cocarla', 11, 9)");
exe("INSERT INTO elevcnrv(id, nume, prenume, clasa, nota_info) VALUES (5, 'Popa', 'Popa', 11, 6)");*/
