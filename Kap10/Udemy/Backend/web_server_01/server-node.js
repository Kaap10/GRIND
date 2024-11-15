const http =  require('http')
const hostname = '127.0.0.1';
const port = 3000;

const server = http.createServer((req, res) =>{
    if(req.url === '/') {
        res.statusCode = 200
        res.setHeader('Content-type', 'text/plain')
        res.end("hello, ice tea")
    }
    else if(req.url === '/ice-tea') {
        res.statusCode = 200
        res.setHeader('Content-type', 'text/plain')
        res.end("Thanks for odering ice-tea")
    } 
    else{
        res.statusCode = 404
        res.setHeader('Content-type', 'text/plain')
        res.end("Bad Gateway Error")
    }
})

server.listen(port, hostname, () => {
    console.log(`Server is running at http://${hostname}:${port}`)
})