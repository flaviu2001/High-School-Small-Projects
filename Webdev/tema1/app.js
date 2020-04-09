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
// nu merge sa pun primary_key, auto_increment si not null. le-am scos ca sa mearga
conn.query("CREATE TABLE IF NOT EXISTS animal\
		(ID INT,\
		 specie VARCHAR(20),\
		 nume VARCHAR(20),\
		 nr_picioare INT,\
		 nr_oameni INT)",
	   function(err, res){
		if(err)throw err;
		console.log(res);
});

exe("INSERT INTO animal (ID, specie, nume, nr_picioare, nr_oameni) VALUES (1, 'maimuta', 'speck', 2, 27)");
exe("INSERT INTO animal (ID, specie, nume, nr_picioare, nr_oameni) VALUES (2, 'panda', 'bob', 4, 1)");
exe("INSERT INTO animal (ID, specie, nume, nr_picioare, nr_oameni) VALUES (3, 'tigru', 'joe', 4, 0)");
exe("INSERT INTO animal (ID, specie, nume, nr_picioare, nr_oameni) VALUES (4, 'girafa', 'mark', 4, 9)");
exe("INSERT INTO animal (ID, specie, nume, nr_picioare, nr_oameni) VALUES (5, 'tarantula', 'terry', 20, 9999)");
exe("SELECT * FROM animal");
exe("SELECT * FROM animal WHERE nr_picioare = 4");
exe("SELECT specie FROM animal WHERE nr_oameni >= 2");
exe("DELETE FROM animal WHERE nr_oameni = 0");
exe("UPDATE animal SET nr_oameni = nr_oameni+1 WHERE nr_picioare = 2");
exe("SELECT * FROM animal");
