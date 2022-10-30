/*

Challenge

The challenge is simple, using http://isup.me, determine whether an inputted website is up or down.

If the site is up, you should return a truthy value and if the site is down, you should return a falsey value.
Rules

The input will be a web address such as stackexchange.com or google.co.uk. The input will never have http://, https:// etc. at the start of the string, but may have www. or codegolf. at start etc.

You should use the site isup.me/URL where URL is the input.

When a site is up, it will look like:

http://isup.me/codegolf.stackexchange.com

If a site is down, it will look like:

http://isup.me/does.not.exist

URL shorteners are disallowed apart from isup.me.
Example inputs

Probably up (depending on current circumstances):

google.de
codegolf.stackexchange.com
worldbuilding.meta.stackexchange.com
tio.run
store.nascar.com
isup.me

Will be down:

made.up.com
fake.com.us
why.why.why.delilah
store.antarcticrhubarbassociation.an

Winning

Shortest code in bytes wins.


*/

package main

import (
	"fmt"
	"io"
	"net/http"
)

func main() {
	fmt.Println(webstate("google.de"))
	fmt.Println(webstate("does.not.exist"))
}

func webstate(url string) string {
	url = fmt.Sprintf("http://isup.me/%s", url)
	resp, err := http.Get(url)
	if err != nil {
		return err.Error()
	}
	buf, err := io.ReadAll(resp.Body)
	if err != nil {
		return err.Error()
	}
	return string(buf)
}
