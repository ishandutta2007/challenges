#!/usr/bin/env python

"""

Create a function (or closest equivalent, or full program) that takes an list of some datatype (your choice) that may be nested and a string (in either order), and generalizes the lisp c[ad]+r functions.

    Functions are provided which perform compositions of up to four car and cdr operations. Their names consist of a C, followed by two, three, or fourany positive number occurrences of A or D, and finally an R. The series of A's and D's in each function's name is chosen to identify the series of car and cdr operations that is performed by the function. The order in which the A's and D's appear is the inverse of the order in which the corresponding operations are performed.

(source: common lisp hyperspec)

The car and cdr operations will return the first element and all the other elements, respectively, for the purposes of this challenge. The string will hold the operation you should perform.
Examples:

   Array    ,  Accessor  =>  Result
===================================
     [0,1,2],      'cdr' => [1,2]
 [0,[1,2],3],     'cadr' => [1,2]
 [[[[[0]]]]],   'caaaar' => [0]
          [],      'cdr' => do not need to handle (no cdr)
          [],      'car' => do not need to handle (no car)
    anything, 'cr'/'asd' => do not need to handle (invalid command)
         [0],      'car' => 0
         [0],      'cdr' => []

Reference Implementation

Hide code snippet

{

  const inp = document.getElementById("inp");
  const out = document.getElementById("out");
  inp.onchange = () => {
    const data = JSON.parse(inp.value);
    var list = data.list;
    data.cmd.match(/^c([ad]+)r$/)[1]
      .split("").reverse().forEach(letter =>
        list = letter === "a" ? list[0] : list.slice(1));
    out.value = JSON.stringify(list);
  };
  inp.onchange();

}

<textarea id="inp" rows="2" cols="50">
{ "cmd": "cadadr",
  "list": [0,[1,[2,3],4],5] }
</textarea>
<br>
<textarea readonly id="out" rows="1" cols="50">
waiting, there seems to be a problem
</textarea>

"""

def la(op, l):
    n = len(op)
    if n < 3 or op[0] != 'c' or op[-1] != 'r':
        raise "invalid operation"
    
    i = n-2
    while i >= 1:
        if op[i] == 'a':
            if len(l) > 0:
                l = l[0]
        elif op[i] == 'd':
            if len(l) > 0:
                l = l[1:]
        else:
            raise "invalid operation"
        i -= 1

    return l

def test(op, l):
    try:
        print(la(op, l))
    except:
        print("invalid operation '{}'".format(op))

def main():
    test("cdr", [0, 1, 2])
    test("cadr", [0, [1, 2], 3])
    test("caaaar", [[[[[0]]]]])
    test("car", [])
    test("cdr", [])
    test("cr", [])
    test("asd", [])
    test("car", [])
    test("cdr", [])

main()
