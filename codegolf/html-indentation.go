/*

Given an inconsistently indented piece of html code your task is to return the same text but correctly indented

Indent space = 4
Assume input will be non-empty.
Input can be taken as string or array/list of lines
Opening and closing tags must be on the same line as long as there is not any other tag inside. <td></td>
Assume there will be only html tags, no text elements whatsoever
All opening tags that aren't self-closing will have closing tags, and will be given in the correct nesting order. Self-closing tags will be closed with />
Standard code-golf rules apply
Example and test-cases

Input
--------------
<table>
     <tr>
  <td>
</td>
      <td></td></tr></table>

Output
----------
<table>
    <tr>
        <td></td>
        <td></td>
    </tr>
</table>
Input
------------
<div>
              <ul>
<li></li><li></li></ul>
        <ul>
              <li></li>
<li></li>
</ul><div><table>

<tbody>
  <thead>
 <tr>
        <th></th>
          <th></th>
             </tr>
       </thead>
   <tbody>
<tr>
    <td></td>
    <td></td>
</tr>
<tr>
    <td></td>
    <td></td>
</tr>
</tbody></tbody></table>
       </div>
</div>

Output
--------------------
<div>
    <ul>
        <li></li>
        <li></li>
    </ul>
    <ul>
        <li></li>
        <li></li>
    </ul>
    <div>
        <table>
            <tbody>
                <thead>
                    <tr>
                        <th></th>
                        <th></th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td></td>
                        <td></td>
                    </tr>
                    <tr>
                        <td></td>
                        <td></td>
                    </tr>
                </tbody>
            </tbody>
        </table>
    </div>
</div>
Input
--------------
<div><img src=""/><p></p><input/><input/></div>

Output
-------------
<div>
    <img src=""/>
    <p></p>
    <input/>
    <input/>
</div>

*/

package main

import (
	"bytes"
	"fmt"
	"io"
	"strings"

	"golang.org/x/net/html"
)

func main() {
	fmt.Println(indent(h1))
	fmt.Println(indent(h2))
	fmt.Println(indent(h3))
}

func indent(s string) string {
	r := strings.NewReader(s)
	w := new(bytes.Buffer)
	p := newprinter(r, w)
	p.Do()
	return w.String()
}

type Printer struct {
	w           io.Writer
	lex         *html.Tokenizer
	tok, xtok   html.TokenType
	tag, xtag   string
	elem, xelem string
	inv, xinv   bool
	depth       int
}

func newprinter(r io.Reader, w io.Writer) *Printer {
	return &Printer{
		lex: html.NewTokenizer(r),
		w:   w,
	}
}

func (p *Printer) Do() {
	p.tok, p.tag, p.elem, p.inv = p.next()
	for {
		if p.inv {
			goto unsupported
		}

		p.xtok, p.xtag, p.xelem, p.xinv = p.next()
		switch p.tok {
		case html.ErrorToken:
			return
		case html.StartTagToken:
			p.opening(false)
		case html.EndTagToken:
			if !p.closing() {
				goto unsupported
			}
		case html.SelfClosingTagToken:
			p.opening(true)
		default:
			goto unsupported
		}
		p.tok, p.tag, p.elem, p.inv = p.xtok, p.xtag, p.xelem, p.xinv
	}
	return

unsupported:
	fmt.Fprintf(p.w, "\n\nERROR! UNSUPPORTED HTML DETECTED!\n\n")
}

func (p *Printer) next() (tok html.TokenType, tag, elem string, invalid bool) {
	for {
		tok = p.lex.Next()
		if tok != html.TextToken {
			break
		}

		elem = string(p.lex.Text())
		elem = strings.TrimSpace(elem)
		if elem != "" {
			invalid = true
			return
		}
	}

	name, attr := p.lex.TagName()
	tag = string(name)
	elem = tag
	for {
		if !attr {
			break
		}

		var key, val []byte
		key, val, attr = p.lex.TagAttr()
		elem += fmt.Sprintf(" %s=%q", key, val)
	}
	return
}

func (p *Printer) spaces(level int) string {
	return strings.Repeat(" ", level*4)
}

func (p *Printer) opening(selfclose bool) {
	fmt.Fprintf(p.w, "%s<%s", p.spaces(p.depth), p.elem)
	if selfclose {
		fmt.Fprintf(p.w, "/>\n")
		return
	}

	p.depth++
	fmt.Fprintf(p.w, ">")

	switch {
	case p.xtok == html.EndTagToken:
		if p.tag != p.xtag {
			fmt.Fprintf(p.w, "\n%s", p.spaces(p.depth))
		}
	default:
		fmt.Fprintf(p.w, "\n")
	}
}

func (p *Printer) closing() bool {
	if p.depth--; p.depth < 0 {
		return false
	}
	fmt.Fprintf(p.w, "</%s>\n", p.tag)
	if p.xtok == html.EndTagToken {
		fmt.Fprintf(p.w, "%s", p.spaces(p.depth-1))
	}
	return true
}

const h1 = `
<table>
     <tr>
  <td>
</td>
      <td></td></tr></table>
`

const h2 = `
<div>
              <ul>
<li></li><li></li></ul>
        <ul>
              <li></li>
<li></li>
</ul><div><table>

<tbody>
  <thead>
 <tr>
        <th></th>
          <th></th>
             </tr>
       </thead>
   <tbody>
<tr>
    <td></td>
    <td></td>
</tr>
<tr>
    <td></td>
    <td></td>
</tr>
</tbody></tbody></table>
       </div>
</div>
`

const h3 = `
<div><img src=""/><p></p><input/><input/></div>
`
