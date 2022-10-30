; You are given N identical squares, each with side length A.
; All the squares have their sides parallel to the x−axis and y−axis.
; That is, the squares are not tilted. You have to take several (possibly, zero or all) squares and rearrange them to obtain a mega square.
; The mega square can't have any gap in the enclosed region or have overlapping squares. Also, you cannot rotate any square.
;
; Output the side length of the largest mega square that you can obtain.
;
; Input Format
;
; The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains two space-separated integers N,A.
;
; Output Format
;
; For each test case, print a single line containing one integer - the side length of the largest square you can obtain.
;
; Constraints
; 1≤T≤100
; 1≤N≤10^5
; 1≤A≤10^4

(defun sidelength (n a)
  (* (floor (sqrt n)) a))

(assert (= (sidelength 3 2) 2))
(assert (= (sidelength 5 3) 6))
(assert (= (sidelength 16 18) 72))
(assert (= (sidelength 11 8) 24))
(assert (= (sidelength 8 6) 12))
