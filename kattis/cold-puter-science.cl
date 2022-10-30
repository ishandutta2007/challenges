; We’re not going to sugar-coat it: Chicago’s winters can be rough. The temperatures sometimes dip to uncomfortable levels and, after last year’s “polar vortex”, the University of Chicago Weather Service wants to find out exactly how bad the winter was.
; More specifically, they are interested in knowing the total number of days in which the temperature was below zero degrees Celsius.
;
; Input
;
; The input is composed of two lines. The first line contains a single positive integer n (1≤n≤100) that specifies the number of temperatures collected by the University of Chicago Weather Service.
; The second line contains n temperatures, each separated by a single space. Each temperature is represented by an integer t (−1000000≤t≤1000000)
;
; Output
;
; You must print a single integer: the number of temperatures strictly less than zero.

(defun cold (l)
  (reduce #'+ (map 'list #'(lambda (x) (if (< x 0) 1 0)) l)))

(assert (eq (cold '(5 -10 15)) 1))
(assert (eq (cold '(-14 -5 -39 -5 -7)) 5))
