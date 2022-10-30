; Let's call a sequence good if the sum of all its elements is 0.
;
; You have a sequence of integers A1,A2,…,AN. You may perform any number of operations on this sequence (including zero).
; In one operation, you should choose a valid index i and decrease Ai by i. Can you make the sequence good using these operations?
;
; Input
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first line of each test case contains a single integer N.
; The second line contains N space-separated integers A1,A2,…,AN.
;
; Output
;
; For each test case, print a single line containing the string "YES" if it is possible to make the given sequence good or "NO" if it is impossible.

(defun good (l)
  (>= (reduce #'+ l) 0))

(assert (eq (good '(-1)) nil))
(assert (eq (good '(1 2)) t))
