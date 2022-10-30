; The current price of petrol is X rupees, and the current price of diesel is Y rupees.
; At the start of each month, the price of petrol increases by A rupees and the price of diesel increases by B rupees.
;
; Chef is curious to know which fuel costs less at the end of the Kth month.
; If petrol is cheaper than diesel at the end of Kth month, then print PETROL.
; If diesel is cheaper than petrol at the end of the Kth month, then print DIESEL.
; If both the fuels have the same price at the end of the Kth month, then print SAME PRICE.
;
; Input Format
;
; The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
; Each test case consists of a single line of input, containing five space-separated integers X,Y,A,B,K.
;
; Output Format
;
; For each test case,
;
; Print PETROL if petrol is cheaper than diesel.
; Print DIESEL if diesel is cheaper than petrol.
; Print SAME PRICE otherwise.
; Note: The output is case-insensitive. You can print each character in either lower-case or upper-case.
;
; Constraints
; 1≤T≤1000
; 1≤K≤1000
; 0≤X,Y,A,B≤1000

(defun cheap (x y a b k)
  (setq p (+ x (* k a)))
  (setq d (+ y (* k b)))
  (cond
	((< p d) "PETROL")
	((> p d) "DIESEL")
	(t "SAME PRICE")))

(assert (string= (cheap 1 1 1 1 1) "SAME PRICE"))
(assert (string= (cheap 2 1 2 1 2) "DIESEL"))
(assert (string= (cheap 2 2 1 1 2) "SAME PRICE"))
(assert (string= (cheap 0 2 1 1 0) "PETROL"))
