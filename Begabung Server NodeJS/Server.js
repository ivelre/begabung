// http://ejohn.org/blog/ecmascript-5-strict-mode-json-and-more/
"use strict";

// Optional. You will see this name in eg. 'ps' or 'top' command
process.title = 'node-chat';

// Port where we'll run the websocket server
var webSocketsServerPort = 1337;

// websocket and http servers
var webSocketServer = require('websocket').server;
var http = require('http');
var clients = [ ];
var estadoFoco = false;
var datoGuardar = "";
var x=0,y=0,z=0,gx=0,gy=0,gz=0;
var header, value;

var file = "lectura_" + Math.floor((Math.random() * 10000) + 1);
/**
 * Helper function for escaping input strings
 */
function htmlEntities(str) {
    return String(str).replace(/&/g, '&amp;').replace(/</g, '&lt;')
                      .replace(/>/g, '&gt;').replace(/"/g, '&quot;');
}

var server = http.createServer(function(request, response) {
    // Not important for us. We're writing WebSocket server, not HTTP server
});
server.listen(webSocketsServerPort, function() {
    console.log((new Date()) + " Server is listening on port " + webSocketsServerPort);
});

/**
 * WebSocket server
 */
var wsServer = new webSocketServer({
    // WebSocket server is tied to a HTTP server. WebSocket request is just
    // an enhanced HTTP request. For more info http://tools.ietf.org/html/rfc6455#page-6
    httpServer: server
});

// This callback function is called every time someone
// tries to connect to the WebSocket server
wsServer.on('request', function(request) {
    console.log((new Date()) + ' Connection from origin ' + request.origin + '.');

    // accept connection - you should check 'request.origin' to make sure that
    // client is connecting from your website
    // (http://en.wikipedia.org/wiki/Same_origin_policy)
    var connection = request.accept(null, request.origin); 
    // we need to know client index to remove them on 'close' event
    var userName = false;
    var index = clients.push(connection) - 1;

    console.log((new Date()) + ' Connection accepted.');

    // user sent some message 
    connection.on('message', function(message) {
        if (message.type === 'utf8') { // accept only text
            if (userName === false) { // first message sent by user is their name
                // remember user name
                userName = htmlEntities(message.utf8Data);
                // get random color and send it back to the user
                console.log((new Date()) + ' User is known as: ' + userName);
                for (var i=0; i < clients.length; i++) {
                    clients[i].sendUTF(JSON.stringify({ type:'estatus', data: estadoFoco }));
                }

            } else { // log and broadcast the message
                console.log((new Date()) + ' Received Message from '
                            + userName + ': ' + message.utf8Data);
                if(datoGuardar != ""){
                    datosUniti(datoGuardar,message.utf8Data);
                    }else{
                        datoGuardar = message.utf8Data;
                    }
                }
                for (var i=0; i < clients.length; i++) {
                    clients[i].sendUTF(JSON.stringify({ type: header, data: value }));
                }
                fs = require('fs');
                fs.writeFile(file, header + ' ' + value +' ', function (err) {
                    if (err) 
                        return console.log(err);
                    console.log('Writed in file');
                });
                // we want to keep history of all sent messages
                var obj = {
                    time: (new Date()).getTime(),
                    text: htmlEntities(message.utf8Data),
                    author: userName
                };

            
        }
    });
    function datosUniti(h,v){
        header = h
        value = v
        datoGuardar = "";
    }
    // user disconnected
    connection.on('close', function(connection) {
        if (userName !== false ) {
            console.log((new Date()) + " Peer "
                + connection.remoteAddress + " disconnected.");
            // remove user from the list of connected clients
            clients.splice(index, 1);
        }
    });

});