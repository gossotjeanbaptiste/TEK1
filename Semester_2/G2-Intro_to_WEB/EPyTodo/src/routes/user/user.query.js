
var all = require("../../config/db");
var bcrypt = require('bcryptjs');
var jwt = require('jsonwebtoken');

module.exports.is_existing = function(email, send_code) {
    all.db.query("select * from user where email = '"+ email +"'", function(err, result, fields) {
        if (err)
            return res.status(500).json({"msg": "Internal server error"});
		else if (result.length == 0) {
            send_code(1);
        } else {
            send_code(0);
        }
    });
};

module.exports.check_credentials = function(res, email, password) {
	all.db.query("select * from user where email = '"+ email +"'", (err, result, fields) => {
		if (err)
            return res.status(500).json({"msg": "Internal server error"});
		else if (result.length > 0) {
			if (bcrypt.compareSync(password, result[0]["password"])) {
				const user_info = {email: email, password: password};
                const token_ = jwt.sign(user_info, process.env.SECRET);
                return res.status(200).json({token: token_});
			} else {
				return res.status(403).json({"msg": "Invalid credentials"});
			}
		} else {
			return res.status(403).json({"msg": "Invalid credentials"});
		}
	});
};

module.exports.user_add = function(email, password, name, firstname, res) {
	var salt = bcrypt.genSaltSync(10);
	password = bcrypt.hashSync(password, salt);
	all.db.query("insert into user (email, password, name, firstname) value('"+ email +"', '"+ password +"', '"+ name +"', '"+ firstname+"')",
	function(err, results, fields) {
		if (err)
			return res.status(500).json({"msg" : "Internal server error"});
	});
};

module.exports.show_info = function(info, res) {
	all.db.query("select * from user where email = '"+ info +"'", (err, result, fields) => {
		if (err)
            return res.status(500).json({"msg": "Internal server error"});
		else if (result.length > 0) {
			return res.status(200).json(result[0]);
		} else {
			all.db.query("select * from user where id = "+ info +"", (err, results, fields) => {
				if (results.length > 0)
					return res.status(200).json(results[0]);
				else
					return res.status(400).json({"msg" : "Not found"});
			});
		}
	});
};

module.exports.change_info = function(email, password, name, firstname, id, res) {
	var salt = bcrypt.genSaltSync(10);
	password = bcrypt.hashSync(password, salt);
	all.db.query("update user set email = '"+ email+"', password = '"+password+"', name = '"+name+"', firstname = '"+ firstname+"' where id = "+id,
	function(err, results, fields) {
		if (err) {
			res.status(500).json({"msg" : "Internal server error"});
		} else {
			module.exports.show_info(id, res);
		}
	});
};

module.exports.get_id = function(email, id) {
	all.db.query("select * from user where email = '"+ email +"'", (err, result, fields) => {
		if (err)
			id (-500);
		else if (result.length > 0) {
			if (result[0]["email"] == email) {
				id(result[0]["id"]);
			}
		} else
			id (-1000);
	});
};

module.exports.delete_user = function(res, id) {
	all.db.query("delete from user where id = "+ id, (err, results, files) => {
		if (err)
			return res.status(500).json({"msg" : "Internal server error"});
		else if (results["affectedRows"] >= 1) {
			return res.status(200).json({"msg" : "Successfully deleted record number: " + id})
		} else
			return res.status(400).json({"msg": "Not found"});
	});
}

module.exports.show_tables = function(res) {
	all.db.query('select * from user', (err, result, fields) => {
		if (err)
			return res.status(500).json({"msg" : "Internal server error"});
		else if (result.length > 0) {
			return res.status(200).json(result);
		} else
			return res.status(400).json({"msg": "Not found"});
	});
};
