#!/usr/bin/env python

"""

The official release of the Nintendo 64 in North America was on September 29, 1996.[1] I figured that this anniversary deserved an ASCII art challenge. There's one small twist though, you have to output a different ASCII art for each of three different inputs.

If the input is 1, output this ASCII art of an N64 Controller: (source)

                 | |
             _,.-'-'-.,_
      ______|           |______
   ,-'      |  NINTENDO |      `-.
 ,'   _                          `.
/   _| |_                     (^)   \
|  |_   _|                  (<) (>) |
\    |_|         (S)     (B)  (v)   /
|`.              ___       (A)    ,'|
|  `-.______   ,' _ `.   ______,-'  |
|      |    `. | (_) | ,'    |      |
|      |      \`.___,'/      |      |
|      |      |       |      |      |
|      /      |       |      \      |
\     /       |       |       \     /
 `._,'        \       /        `._,'
               \     /
                `._,'
If the input is 2, output this ASCII art of the N64 logo:(source)

                  .-"-.
               .-"     "-.
              /"-.     .-|
             /    "-.-"  |
            /      /     |
   .-"-.   /      /      |       .-"-.
.-"     "-/      /       |    .-"     "-.
|-.     .-"\    /        |   /"-.     .-|
|  '-.-"    \  /         | /'    "-.-"  |
|     \      \/   .-"-.  /'        |    |
|      \      \.-"     "-.         |    |
|       \      |-.     .-"\        |    |
|        \     |  "-.-"    '\      |    |
|         \    |    |        '\    |    |
|    |\    \   |    |          '\  |    |
|    | \    \  |    |            '\|    |
|    |  \    \ |    |    :\.            |
|    |   \    \|    |    |  \.          |
|    |    \         |    |    \.        |
'-.  |  .-"\        |    |    '.\.    .-'
   "-|-"    \       |    |      "-\.-"
             \      |    |
              \     |    |
               "-.  |  .-'
                  "-|-"
Finally, if the input is 3, outout this ASCII art of a console and TV: (source)

              o
     o       /
      \     /
       \   /
        \ /
   ______________
  |.------------.|
  ||            ||
  ||            ||
  ||            ||
  ||            ||
  ||____________||_
  |OO ....... OO | `-.
  '------_.-._---' _.'
   _____||   ||___/_
  /  _.-|| N ||-._  \      .-._
 / -'_.---------._'- \    ,'___i-i___
/_.-'_  NINTENDO _'-._\  ' /_+  o :::\
|`-i /m\/m\|\|/=,/m\i-'| | || \ O / ||
|  |_\_/\_/___\_/'./|  | | \/  \ /  \/
`-'              '-.`-'  ,      V
                    `---'
Rules:
Input may be either as a number or a string/char.
You may have any amount of leading or trailing spaces and trailing or leading newlines. (Output must be aligned correctly though)
Your submission may be either a full program or a function.
No retrieving the ASCII art from the internet.
This is code-golf, so smallest byte count wins.

"""

import sys

art1 = """
                 | |
             _,.-'-'-.,_
      ______|           |______
   ,-'      |  NINTENDO |      `-.
 ,'   _                          `.
/   _| |_                     (^)   \\
|  |_   _|                  (<) (>) |
\    |_|         (S)     (B)  (v)   /
|`.              ___       (A)    ,'|
|  `-.______   ,' _ `.   ______,-'  |
|      |    `. | (_) | ,'    |      |
|      |      \`.___,'/      |      |
|      |      |       |      |      |
|      /      |       |      \      |
\     /       |       |       \     /
 `._,'        \       /        `._,'
               \     /
                `._,'
"""

art2 = """
                  .-"-.
               .-"     "-.
              /"-.     .-|
             /    "-.-"  |
            /      /     |
   .-"-.   /      /      |       .-"-.
.-"     "-/      /       |    .-"     "-.
|-.     .-"\    /        |   /"-.     .-|
|  '-.-"    \  /         | /'    "-.-"  |
|     \      \/   .-"-.  /'        |    |
|      \      \.-"     "-.         |    |
|       \      |-.     .-"\        |    |
|        \     |  "-.-"    '\      |    |
|         \    |    |        '\    |    |
|    |\    \   |    |          '\  |    |
|    | \    \  |    |            '\|    |
|    |  \    \ |    |    :\.            |
|    |   \    \|    |    |  \.          |
|    |    \         |    |    \.        |
'-.  |  .-"\        |    |    '.\.    .-'
   "-|-"    \       |    |      "-\.-"
             \      |    |
              \     |    |
               "-.  |  .-'
                  "-|-"
"""

art3 = """
              o
     o       /
      \     /
       \   /
        \ /
   ______________
  |.------------.|
  ||            ||
  ||            ||
  ||            ||
  ||            ||
  ||____________||_
  |OO ....... OO | `-.
  '------_.-._---' _.'
   _____||   ||___/_
  /  _.-|| N ||-._  \      .-._
 / -'_.---------._'- \    ,'___i-i___
/_.-'_  NINTENDO _'-._\  ' /_+  o :::\\
|`-i /m\/m\|\|/=,/m\i-'| | || \ O / ||
|  |_\_/\_/___\_/'./|  | | \/  \ /  \/
`-'              '-.`-'  ,      V
                    `---'

"""

def main():
    if len(sys.argv) < 2:
        print("usage: <selection>")
        sys.exit(2)

    choice = -1
    try:
        choice = int(sys.argv[1])
    except:
        pass

    if choice == 1:
        print(art1)
    elif choice == 2:
        print(art2)
    elif choice == 3:
        print(art3)
    else:
        print("Invalid input")

main()
