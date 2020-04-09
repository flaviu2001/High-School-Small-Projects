var mysql = require('mysql');

var conn = mysql.createConnection({
	host:'localhost',
	user:'root',
	password:'rootpass',
	database:'mydb'
});

conn.connect(function(err){
	if(err)
		throw err;
	console.log("connected");
});

function exe(cod){
	conn.query(cod, function(err, res){
		if(err) throw err;
		console.log(res);
	});
}

conn.query("CREATE TABLE IF NOT EXISTS scoala\
		(nume VARCHAR(50),\
		 mail VARCHAR(50),\
		 mate INT,\
		 info INT)",
	   function(err, res){
		if(err)throw err;
		console.log(res);
});

exe("INSERT INTO scoala (nume, mail, mate, info) VALUES ('Flaviu', 'ceva@gmail.com', 10, 10)");
exe("INSERT INTO scoala (nume, mail, mate, info) VALUES ('Adrian', 'altceva@gmail.com', 3, 6)");
exe("INSERT INTO scoala (nume, mail, mate, info) VALUES ('Mihaela', 'incaceva@gmail.com', 9, 2)");
exe("INSERT INTO scoala (nume, mail, mate, info) VALUES ('Daenerys', 'orice@gmail.com', 7, 6)");
exe("INSERT INTO scoala (nume, mail, mate, info) VALUES ('Tyrion', 'nimic@gmail.com', 5, 5)");
exe("SELECT nume FROM scoala WHERE mate >= 8");
exe("SELECT mail FROM scoala WHERE info < 5");
exe("DELETE FROM scoala WHERE mate = 3");
exe("UPDATE scoala SET info = info + 1 WHERE mate >= 6");
exe("SELECT * FROM scoala");
