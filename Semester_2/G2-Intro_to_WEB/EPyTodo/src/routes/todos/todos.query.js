var all = require("../../config/db");
var user = require("../user/user.query.js");
var bcrypt = require('bcryptjs');
var jwt = require('jsonwebtoken');

module.exports.user_todo = function(email, res) {
    user.get_id(email, id => {
        if (id != -1000) {
            all.db.query("select * from todo where user_id = "+ id, (err, result, fields) => {
                if (err)
                    return res.status(500).json({"msg": "Internal server error"});
                else if (result.length > 0)
                    return res.status(200).json(result);
                else
                    return res.status(200).json({"msg": "Not found"});
            });
        } else if (id == -1000)
            return res.status(400).json({"msg": "Not found"});
        else
            return res.status(500).json({"msg": "Internal server error"});
    });
};

module.exports.all_todo = function(res) {
    all.db.query("select * from todo", (err, result, fields) => {
        if (err)
            return res.status(500).json({"msg": "Internal server error"});
        else if (result.length > 0)
            return res.status(200).json(result);
        else
            return res.status(400).json({"msg": "Not found"});
    });
};

module.exports.show_todo = function(id, res) {
	all.db.query("select * from todo where id = "+ id, (err, result, fields) => {
        if (err)
            return res.status(500).json({"msg": "Internal server error"});
		else if (result.length > 0) {
			return res.status(200).json(result[0]);
		} else {
			return res.status(400).json({"msg" : "Not found"});
		}
	});
};

module.exports.create_todo = (title, description, due_time, user_id, status, res) => {
    all.db.query("insert into todo (title, description, due_time, user_id, status) value('"+ title +"', '"+ description +"', '"+ due_time +"', '"+ user_id+"', '"+ status+"')",
	function(err, results, fields) {
		if (err)
			res.status(500).json({"msg" : "Internal server error"});
        else {
            module.exports.show_todo(results["insertId"], res);
        }
	});
};

module.exports.update_todo = (title, description, due_time, user_id, status, id ,res) => {
    all.db.query("update todo set title = '"+title+"', description = '"+description+"', due_time = '"+due_time+"', user_id = '"+user_id+"', status = '"+status+"' where id = "+id, (err, results, fiels) => {
        if (err)
            return res.status(500).json({"msg" : "Internal server error"});
        else
            module.exports.show_todo(id, res);
    });
};

module.exports.delete_todo = (res, id) => {
    all.db.query("delete from todo where id = "+ id, (err, results, fields) => {
        if (err)
            return res.status(500).json({"msg" : "Internal server error"});
        else if (results["affectedRows"] >= 1) {
            return res.status(200).json({"msg" : "Successfully deleted record number: " + id})
        } else
            return res.status(400).json({"msg": "Not found"});
    });
};
