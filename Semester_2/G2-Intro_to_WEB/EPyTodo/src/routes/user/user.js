var all = require("./user.query");
var todo = require("../todos/todos.query.js");
var middleware = require("../../middleware/auth");

module.exports = function(app) {
    app.get ("/user" , middleware, async (req, res) => {
        all.show_tables(res);
    });
    app.get("/user/todos" , middleware, (req, res) => {
        todo.user_todo(req.user_info["email"], res);
    });
    app.get("/user/:info", middleware, (req, res) => {
        all.show_info(req.params.info, res);
    });
    app.delete("/user/:id", middleware, (req, res) => {
        var id = req.params.id;
        all.delete_user(res, id)
    });
    app.put("/user/:id" , middleware, (req, res) => {
        var email = req.body["email"];
        var password = req.body["password"];
        var name = req.body["name"];
        var firstname = req.body["firstname"];
        var id  = req.params.id;
        if (email == null || password == null || name == null || firstname == null || id == null) {
            return res.status(500).json({"msg": "Bad parameter"});
        } else
            all.change_info(email, password, name, firstname, id, res);
    });
}
