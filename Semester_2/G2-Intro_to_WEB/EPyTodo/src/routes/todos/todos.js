var middleware = require("../../middleware/auth");
var user = require("../user/user.query.js");
var all = require("./todos.query");

module.exports = function(app) {
    app.get("/todos", middleware, (req, res) => {
        all.all_todo(res);
    });
    app.get("/todos/:id", middleware, (req, res) => {
        var id = req.params.id;
        if (id == null)
            return res.status(404).json({"msg" : "Bad parameter"});
        else
            all.show_todo(id, res);
    });
    app.post("/todos", middleware, (req, res) => {
        var title = req.body["title"];
        var description = req.body["description"];
        var due_time = req.body["due_time"];
        var user_id = req.body["user_id"];
        var status = req.body["status"];
        if (title == null || description == null || due_time == null || user_id == null || status == null)
            return res.status(404).json({"msg" : "Bad parameter"});
        else
            all.create_todo(title, description, due_time, user_id, status, res);
    });
    app.delete("/todos/:id", middleware, (req, res) => {
        var id = req.params.id;
        all.delete_todo(res, id);
    });
    app.put("/todos/:id", middleware, (req, res) => {
        var title = req.body["title"];
        var description = req.body["description"];
        var due_time = req.body["due_time"];
        var user_id = req.body["user_id"];
        var status = req.body["status"];
        var id = req.params.id
        if (title == null || description == null || due_time == null || user_id == null || status == null || id == null)
            return res.status(404).json({"msg" : "Bad parameter"});
        else
            all.update_todo(title, description, due_time, user_id, status, id, res);
    });
};
