"""

Description

I'm willing to bet most of you are familiar with HTTP, you're using it right now to read this content. If you've ever done any web programming you probably interacted with someone else's HTTP server stack - Flask, Apache, Nginx, Rack, etc.

For today's challenge, the task is to implement your own HTTP server. No borrowing your language's built in server (e.g. no, you can't just use Python's SimpleHTTPServer). The rules, requirements, and constraints:

    Your program will implement the bare basics of HTTP 1.0: GET requests required, any other methods (POST, HEAD, etc) are optional (see the bonus below).

    You have to write your own network listening code (e.g. socket()) and handle listening on a TCP port. Most languages support this, you have to start this low. Yep, learn some socket programming. socket() ... bind() ... listen() ... accept() ... and the like.

    Your server should handle static content only (e.g. static HTML pages or images), no need to support dynamic pages or even cgi-bin executables.

    Your server should support a document root which contains pages (and paths) served by the web server.

    Your server should correctly serve content it finds and can read, and yield the appropriate errors when it can't: 500 for a server error, 404 for a resource not found, and 403 for permission denied (e.g. exists but it can't read it).

    For it to display properly in a browser, you'll need to set the correct content type header in the response.

    You'll have to test this in a browser and verify it works as expected: content displays right (e.g. HTML as HTML, text as text, images as images), errors get handled properly, etc.

A basic, bare bones HTTP/1.0 request looks like this;

GET /index.html HTTP/1.0

That's it, no Host header required etc., and all other headers like user-agent and such are optional. (HTTP/1.1 requires a host header, in contrast.)

A basic, bare bones HTTP/1.0 response looks like this:

HTTP/1.0 200 OK
Content-type: text/html

<H1>Success!</H1>

The first line indicates the protocol (HTTP/1.0), the resulting status code (200 in this case means "you got it"), and the text of the status.
The next line sets the content type for the browser to know how to display the content. Then a blank line, then the actual content. Date, server, etc headers are all optional.

Here's some basics on HTTP/1.0: http://tecfa.unige.ch/moo/book2/node93.html

Once you have this in your stash, you'll not only understand what more fully-featured servers like Apache or Nginx are doing, you'll have one you can customize. For example, I'm looking at extending my solution in C with an embedded Lua interpreter.
Bonus

Support threading for multiple connections at once.

Support HEAD requests.

Support POST requests.

"""

from http.server import *
from socketserver import *

ADDR = ""
PORT = 8080

def main():
    with TCPServer((ADDR, PORT), SimpleHTTPRequestHandler) as httpd:
        print("Server started at localhost:" + str(PORT))
        httpd.serve_forever()

main()
