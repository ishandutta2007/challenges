; Chef has N slippers, L of which are left slippers and the rest are right slippers.
; Slippers must always be sold in pairs, where each pair contains one left and one right slipper.
; If each pair of slippers cost X rupees, what is the maximum amount of rupees that Chef can get for these slippers?
;
; Input Format
;
; The first line contains T - the number of test cases. Then the test cases follow.
; The first line of each test case contains three space-separated integers N, L, and X - the total number of slippers, the number of left slippers, and the price of a pair of slippers in rupees.
;
; Output Format
;
; For each test case, output on one line the maximum amount of rupees that Chef can get by selling the slippers that are available.
;
; Constraints
; 1≤T≤10^3
; 0≤L≤N≤10^3
; 0≤X≤10^3

(defun rupees (n l x)
  (* (min l (- n l)) x))

(assert (= (rupees 0 0 100) 0))
(assert (= (rupees 10 1 0) 0))
(assert (= (rupees 1000 10 1000) 10000))
(assert (= (rupees 10 7 1) 3))
