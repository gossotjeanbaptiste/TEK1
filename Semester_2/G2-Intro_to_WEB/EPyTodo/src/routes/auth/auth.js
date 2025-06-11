var all = require("../user/user.query");
var jwt = require('jsonwebtoken');

module.exports = function(app) {
    app.post('/login', async function(req, res) {
        var email = req.body["email"];
        var password = req.body["password"];
        if (password == null || email == null)
            return res.status(403).json({"msg": "Bad parameter"});
        await all.check_credentials(res, email, password)
    });
    app.post('/register', async function(req, res) {
        var email = req.body["email"];
        var password = req.body["password"];
        var name = req.body["name"];
        var firstname = req.body["firstname"];
        if (email == null || password == null || name == null || firstname == null)
            return res.status(500).json({"msg": "Bad parameter"});
        await all.is_existing(email, code => {
            if (code != 1)
                return res.status(404).json({"msg": "Account already exists"});
            else {
                all.user_add(email, password, name, firstname);
                const user_info = {email: email, password: password};
                const token_ = jwt.sign(user_info, process.env.SECRET);
                return res.status(200).json({token: token_});
            }
        });
    });
}
