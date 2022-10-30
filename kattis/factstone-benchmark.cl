; Amtel has announced that it will release a 128-bit computer chip by 2010, a 256-bit computer by 2020, and so on, continuing its strategy of doubling the word-size every ten years.
; (Amtel released a 64-bit computer in 2000, a 32-bit computer in 1990, a 16-bit computer in 1980, an 8-bit computer in 1970, and a 4-bit computer, its first, in 1960.)
;
; Amtel will use a new benchmark – the Factstone – to advertise the vastly improved capacity of its new chips.
; The Factstone rating is defined to be the largest integer n such that n! can be represented as an unsigned integer in a computer word.
;
; Given a year 1960≤y≤2160, what will be the Factstone rating of Amtel’s most recently released chip?
;
; Input
;
; There are several test cases. For each test case, there is one line of input containing y. A line containing 0 follows the last test case.
;
; Output
;
; For each test case, output a line giving the Factstone rating.

(defun triangular-number (n)
  (truncate (* n (+ n 1)) 2))

(defun factstone-rating (y)
  (setq n (truncate (- y 1940) 10))
  (+ 2 (triangular-number (- n 1))))

(assert (= (factstone-rating 1960) 3))
(assert (= (factstone-rating 1981) 8))
