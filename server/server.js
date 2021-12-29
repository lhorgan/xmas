var express = require('express')
var app = express()

STATUS = "WAITING";
ARMED = false;

// respond with "hello world" when a GET request is made to the homepage
app.get('/status', function (req, res) {
    res.send(STATUS);
})

app.get('/set_armed', function(req, res) {
    ARMED = true;
    res.send("armed");
})

app.get('/armed', function(req, res) {
    ARMED = true;
    res.send(ARMED);
})

app.get('/disarm', function(req, res) {
    STATUS = "WAITING";
    ARMED = false;
    res.send(false);
});

app.get('/set_play_song', function(req, res) {
    STATUS = "PLAY_SONG";
    res.send(STATUS);
});