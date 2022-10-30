; Write a program, which takes an integer N and if the number is less than 10 then display "Thanks for helping Chef!" otherwise print "-1".
;
; Input
;
; The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer N.
;
; Output
;
; For each test case, output the given string or -1 depending on conditions, in a new line.
;
; Constraints
; 1 ≤ T ≤ 1000
; -20 ≤ N ≤ 20

(defun help (n)
  (if (< n 10) "Thanks for helping Chef!" -1))

(print (help 1))
(print (help 12))
(print (help -5))
