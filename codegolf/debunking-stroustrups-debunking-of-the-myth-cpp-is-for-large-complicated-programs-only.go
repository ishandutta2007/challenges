/*

Stroustrup has recently posted a series of posts debunking popular myths about C++. The fifth myth is: “C++ is for large, complicated, programs only”. To debunk it, he wrote a simple C++ program downloading a web page and extracting links from it. Here it is:

#include <string>
#include <set>
#include <iostream>
#include <sstream>
#include <regex>
#include <boost/asio.hpp>

using namespace std;

set<string> get_strings(istream& is, regex pat)
{
    set<string> res;
    smatch m;
    for (string s; getline(is, s);)  // read a line
        if (regex_search(s, m, pat))
            res.insert(m[0]);              // save match in set
    return res;
}

void connect_to_file(iostream& s, const string& server, const string& file)
// open a connection to server and open an attach file to s
// skip headers
{
    if (!s)
        throw runtime_error{ "can't connect\n" };

    // Request to read the file from the server:
    s << "GET " << "http://" + server + "/" + file << " HTTP/1.0\r\n";
    s << "Host: " << server << "\r\n";
    s << "Accept: * /*\r\n";
    s << "Connection: close\r\n\r\n";

    // Check that the response is OK:
    string http_version;
    unsigned int status_code;
    s >> http_version >> status_code;

    string status_message;
    getline(s, status_message);
    if (!s || http_version.substr(0, 5) != "HTTP/")
        throw runtime_error{ "Invalid response\n" };

    if (status_code != 200)
        throw runtime_error{ "Response returned with status code" };

    // Discard the response headers, which are terminated by a blank line:
    string header;
    while (getline(s, header) && header != "\r")
        ;
}

int main()
{
    try {
        string server = "www.stroustrup.com";
        boost::asio::ip::tcp::iostream s{ server, "http" };  // make a connection
        connect_to_file(s, server, "C++.html");    // check and open file

        regex pat{ R"((http://)?www([./#\+-]\w*)+)" }; // URL
        for (auto x : get_strings(s, pat))    // look for URLs
            cout << x << '\n';
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
        return 1;
    }
}

Let's show Stroustrup what small and readable program actually is.

    Download http://www.stroustrup.com/C++.html

    List all links:

     http://www-h.eng.cam.ac.uk/help/tpl/languages/C++.html
     http://www.accu.org
     http://www.artima.co/cppsource
     http://www.boost.org
     ...

You can use any language, but no third-party libraries are allowed.
Winner

C++ answer won by votes, but it relies on a semi-third-party library (which is disallowed by rules), and, along with another close competitor Bash, relies on a hacked together HTTP client (it won't work with HTTPS, gzip, redirects etc.). So Wolfram is a clear winner. Another solution which comes close in terms of size and readability is PowerShell (with improvement from comments), but it hasn't received much attention. Mainstream languages (Python, C#) came pretty close too.
Comment on subjectivity

The most upvoted answer (C++) at the moment votes were counted was disqualified for not following the rules listed here in the question. There's nothing subjective about it. The second most upvoted question at that moment (Wolfram) was declared winner. The third answer's (Bash) "disqualification" is subjective, but it's irrelevant as the answer didn't win by votes at any point in time. You can consider it a comment if you like. Furthermore, right now the Wolfram answer is the most upvoted answer, the accepted one, and is declared winner, which means there's zero debate or subjectivity.

*/

package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
	"regexp"
)

func main() {
	err := debunk("https://www.stroustrup.com")
	if err != nil {
		log.Fatal(err)
	}
}

func debunk(url string) error {
	resp, err := http.Get(url)
	if err != nil {
		return err
	}

	buf, err := io.ReadAll(resp.Body)
	if err != nil {
		return err
	}

	re := regexp.MustCompile("((http://)?www([./#\\+-]\\w*)+)")
	matches := re.FindAll(buf, -1)
	for _, str := range matches {
		fmt.Printf("%s\n", str)
	}

	return nil
}
