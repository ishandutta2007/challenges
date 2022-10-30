; You are given a range of integers {L,L+1,…,R}. An integer X is said to be reachable if it can be represented as a sum of two not necessarily distinct integers in this range.
; Find the number of distinct reachable integers.
;
; Input
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains two space-separated integers L and R.
;
; Output
;
; For each test case, print a single line containing one integer — the number of reachable integers.
;
; Constraints
; 1≤T≤10^5
; 1≤L≤R≤10^6

(defun reachable (l r)
  (+ (- (* 2 r) (* 2 l)) 1))

(assert (= (reachable 2 2) 1))
(assert (= (reachable 2 3) 3))
