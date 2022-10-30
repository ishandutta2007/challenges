; Chef is playing Need For Speed. Currently, his car is running on a straight road with a velocity U metres per second and approaching a 90∘ turn which is S metres away from him.
; To successfully cross the turn, velocity of the car when entering the turn must not exceed V metres per second.
; The brakes of Chef's car allow him to slow down with a deceleration (negative acceleration) not exceeding A metres per squared second.
; Tell him whether he can cross the turn successfully. The velocity v when entering the turn can be determined from Newton's 2nd law to be v2=U2+2⋅a⋅S if the car is moving with a uniform acceleration a.
;
; Input
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains four space-separated integers U, V, A and S.
;
; Output
;
; For each test case, print a single line containing the string "Yes" if Chef can cross the turn successfully or "No" if he cannot (without quotes).
;
; You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
;
; Constraints
; 1≤T≤10^5
; 1≤U,V,A,S≤10^4

(defun crossable (u v a s)
  (if (<= (- (* u u) (* 2 a s)) (* v v)) "YES" "NO"))

(assert (string= (crossable 1 1 1 1) "YES"))
(assert (string= (crossable 2 1 1 1) "NO"))
(assert (string= (crossable 2 2 1 1) "YES"))
