import {serve} from 'bun' 

serve({
    fetch(request) {
        const url = new URL(request.url);
        if(url.pathname === '/') {
            return new Response('Hellow ice-tea', {status:200})
        } else if(url.pathname === '/ice-tea') {
            return new Response('Nice', {status:200})
        } else {
            return new Response('Get lost', {status:404})
        } 
    },
    port: 3001, // Change the port number here
    hostname: '127.0.0.1'
})