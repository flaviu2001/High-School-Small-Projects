var mysql = require('mysql');

var conn = mysql.createConnection({
	host:'localhost',
	user:'root',
	password:'rootpass',
	database:'mydb'
});

conn.connect(function(err){
	if(err)throw err;
	console.log("connected");
});

/*conn.query("CREATE DATABASE mydb", function(err, res){
	if(err) throw err;
	console.log(res);
});*/

conn.query("CREATE TABLE IF NOT EXISTS elev\
		(ID INT,\
		 nume VARCHAR(20),\
		 prenume VARCHAR(20),\
		 clasa INT,\
		 nota_mate INT)",
	   function(err, res){
		if(err)throw err;
		console.log(res);
});

/*conn.query("INSERT INTO elev (ID, nume, prenume, clasa, nota_mate) VALUES (1, 'jon', 'snow', 10, 10)", function(err, res){
	if(err) throw err;
	console.log(res);
});*/

conn.query("SELECT * FROM elev", function(err, res){
		if(err)throw err;
		console.log(res);
});

