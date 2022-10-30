; Recently, Devendra went to Goa with his friends. Devendra is well known for not following a budget.
;
; He had Rs. Z at the start of the trip and has already spent Rs. Y on the trip. There are three kinds of water sports one can enjoy, with prices Rs. A, B, and C. He wants to try each sport at least once.
;
; If he can try all of them at least once output YES, otherwise output NO.
;
; Input Format
;
; The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
; Each test case consists of a single line of input containing five space-separated integers Z,Y,A,B,C.
;
; Output Format
;
; For each test case, print a single line containing the answer to that test case — YES if Devendra can try each ride at least once, and NO otherwise.
;
; You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
;
; Constraints
; 1≤T≤10
; 10^4≤Z≤10^5
; 0≤Y≤Z
; 100≤A,B,C≤5000

(defun enjoy (z y a b c)
  (if (>= (- z y) (+ a b c)) "YES" "NO"))

(assert (string= (enjoy 25000 22000 1000 1500 700) "NO")) 
(assert (string= (enjoy 10000 7000 100 300 500) "YES")) 
(assert (string= (enjoy 15000 5000 2000 5000 3000) "YES")) 
