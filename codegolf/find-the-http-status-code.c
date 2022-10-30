/*

Given the name of an HTTP status code, such as OK or Continue, output or return the corresponding number. Your code is limited to 200 bytes, and the winner is the answer that correctly finds the number for the most status codes.

For this challenge, the status codes your program should handle are:

100 Continue
101 Switching Protocols
200 OK
201 Created
202 Accepted
203 Non-Authoritative Information
204 No Content
205 Reset Content
206 Partial Content
300 Multiple Choices
301 Moved Permanently
302 Found
303 See Other
304 Not Modified
305 Use Proxy
307 Temporary Redirect
400 Bad Request
401 Unauthorized
402 Payment Required
403 Forbidden
404 Not Found
405 Method Not Allowed
406 Not Acceptable
407 Proxy Authentication Required
408 Request Timeout
409 Conflict
410 Gone
411 Length Required
412 Precondition Failed
413 Request Entity Too Large
414 Request-URI Too Long
415 Unsupported Media Type
416 Requested Range Not Satisfiable
417 Expectation Failed
500 Internal Server Error
501 Not Implemented
502 Bad Gateway
503 Service Unavailable
504 Gateway Timeout
505 HTTP Version Not Supported

Test cases:

Continue        -> 100
OK              -> 200
No Content      -> 204
Not Found       -> 404

For invalid status codes or ones not supported by your program, any behavior is fine. Input and output can be in any reasonable format. If there is a tie, the shortest program that can support that many status codes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
httpstatus(const char *s)
{
	static const struct {
		int status;
		const char *name;
	} tab[] = {
	    {100, "Continue"},
	    {101, "Switching Protocols"},
	    {200, "OK"},
	    {201, "Created"},
	    {202, "Accepted"},
	    {203, "Non-Authoritative Information"},
	    {204, "No Content"},
	    {205, "Reset Content"},
	    {206, "Partial Content"},
	    {300, "Multiple Choices"},
	    {301, "Moved Permanently"},
	    {302, "Found"},
	    {303, "See Other"},
	    {304, "Not Modified"},
	    {305, "Use Proxy"},
	    {307, "Temporary Redirect"},
	    {400, "Bad Request"},
	    {401, "Unauthorized"},
	    {402, "Payment Required"},
	    {403, "Forbidden"},
	    {404, "Not Found"},
	    {405, "Method Not Allowed"},
	    {406, "Not Acceptable"},
	    {407, "Proxy Authentication Required"},
	    {408, "Request Timeout"},
	    {409, "Conflict"},
	    {410, "Gone"},
	    {411, "Length Required"},
	    {412, "Precondition Failed"},
	    {413, "Request Entity Too Large"},
	    {414, "Request-URI Too Long"},
	    {415, "Unsupported Media Type"},
	    {416, "Requested Range Not Satisfiable"},
	    {417, "Expectation Failed"},
	    {500, "Internal Server Error"},
	    {501, "Not Implemented"},
	    {502, "Bad Gateway"},
	    {503, "Service Unavailable"},
	    {504, "Gateway Timeout"},
	    {505, "HTTP Version Not Supported"},
	    {0, NULL},
	};

	size_t i;

	for (i = 0; tab[i].status; i++) {
		if (!strcmp(tab[i].name, s))
			return tab[i].status;
	}

	return -1;
}

int
main(void)
{
	assert(httpstatus("Continue") == 100);
	assert(httpstatus("OK") == 200);
	assert(httpstatus("No Content") == 204);
	assert(httpstatus("Not Found") == 404);

	return 0;
}
