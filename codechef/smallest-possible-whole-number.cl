; You are given two integers N and K. You may perform the following operation any number of times (including zero): change N to N−K, i.e. subtract K from N.
; Find the smallest non-negative integer value of N you can obtain this way.
;
; Input
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains two space-separated integers N and K.
;
; Output
;
; For each test case, print a single line containing one integer — the smallest value you can get.
;
; Constraints
; 1≤T≤10^5
; 1≤N≤10^9
; 0≤K≤10^9

(defun value (n k)
  (if (= k 0) n (mod n k)))

(assert (= (value 5 2) 1))
(assert (= (value 4 4) 0))
(assert (= (value 2 5) 2))
