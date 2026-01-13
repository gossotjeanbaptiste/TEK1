const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => {
  res.send('Hello World!')
})

app.get('/name/:name', (req, res) => {
    res.send(`Hello ${req.params.name} !`)
})

app.get('/date', (req, res) => {
    const currentDate = new Date();
    const formattedDate = `${currentDate.getFullYear()}-${currentDate.getMonth() + 1}-${currentDate.getDate()}`;
    res.send(`${formattedDate}`);
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
