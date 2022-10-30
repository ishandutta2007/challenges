; A policeman wants to catch a thief. Both the policeman and the thief can only move on a line on integer coordinates between 0 and N (inclusive).
;
; Initially, the policeman is at a coordinate x and the thief is at a coordinate y. During each second, each of them must move to the left or right (not necessarily both in the same direction) by distance exactly equal to K.
; No one may go to the left of the coordinate 0 or to the right of N. Both the policeman and the thief move simultaneously and they cannot meet while moving, only at the end of each second.
;
; Will the policeman be able to catch the thief if they both move optimally? The thief is caught as soon as the policeman and thief meet at the same position at the same time.
;
; Input
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains four space-separated integers x, y, K and N.
;
; Output
;
; For each test case, print a single line containing the string "Yes" if the thief can be caught or "No" if the thief cannot be caught (without quotes).
;
; Constraints
; 1≤T≤1,000
; 1≤N≤10^9
; 1≤K≤N
; 0≤x,y≤N
; x≠y

(defun caught (x y k n)
  (if (= (mod (abs (- x y)) (* 2 k)) 0) "Yes" "No"))

(assert (string= (caught 0 1 1 1) "No"))
(assert (string= (caught 1 4 1 5) "No"))
(assert (string= (caught 4 2 1 7) "Yes"))
(assert (string= (caught 3 7 2 10) "Yes"))
(assert (string= (caught 8 2 3 15) "Yes"))
