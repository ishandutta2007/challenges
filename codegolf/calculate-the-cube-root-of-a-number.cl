; The goal of this code golf is to create a program or function that calculates and outputs the cube root of a number that's given as input.
; The rules:
;
;    No external resources
;    No use of built-in cube root functions.
;    No use of methods/operators that can raise a number to a power (that includes square root, 4th root, etc.).
;    Your function/program must be able to accept floating-point numbers and negative numbers as input.
;    If the cube root is a floating-point number, then round it to 4 numbers after the decimal point.
;    This is a code golf, the shortest code in bytes wins.
;
; Test cases:
;
; 27 --> 3
; 64 --> 4
; 1  --> 1
; 18.609625 --> 2.65
; 3652264 --> 154
; 0.001 --> 0.1
; 7  --> 1.9129
;
; You can use all test cases above to test negative numbers (-27 --> -3, -64 --> -4 ...)

(defun cbrt(x) (expt x 1/3))

(print (cbrt 27))
(print (cbrt 64))
(print (cbrt 1))
(print (cbrt 18.609625))
(print (cbrt 3652264))
(print (cbrt 0.001))
(print (cbrt 7))
