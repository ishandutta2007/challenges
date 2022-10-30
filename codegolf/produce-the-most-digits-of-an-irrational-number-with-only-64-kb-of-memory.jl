#!/usr/bin/env julia

#=

Constraints:

Calculate any notable irrational number such as pi, e, or sqrt(2) to as many decimal digits as possible. If using a number not mentioned in the list above, you must cite how and where this number is used.

The memory used to store data in variables that the program reads from at any time in its computation may not exceed 64 kilobytes (216 = 65 536 bytes).
However, the program may output as much data as it likes, provided it does not re-read the outputted data. (Said re-reading would count toward the 64 KB limit.)

The maximum size for code (either source or object code can be measured) is also 64 kilobytes. Smaller code is allowed, but does not provide more memory for computation or a better score.

The program must not accept any input.

Any format for output is allowed, as long as the digits are represented in decimal.
Only the fractional portion of the number will be taken into account, so both 3.14159... and 14159... are both equivalent answers, the latter one being represented as "the fractional part of pi".

The number of decimal digits past the decimal point that your program outputs is your score. Highest score wins.

=#

setprecision(64 * 1024)
println(sqrt(BigFloat(5)))

