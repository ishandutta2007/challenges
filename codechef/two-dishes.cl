; Chef will have N guests in his house today. He wants to serve at least one dish to each of the N guests.
; Chef can make two types of dishes. He needs one fruit and one vegetable to make the first type of dish and one vegetable and one fish to make the second type of dish.
; Now Chef has A fruits, B vegetables, and C fishes in his house. Can he prepare at least N dishes in total?
;
; Input Format
; First line will contain T, number of testcases. Then the testcases follow.
; Each testcase contains of a single line of input, four integers N,A,B,C.
;
; Output Format
;
; For each test case, print "YES" if Chef can prepare at least N dishes, otherwise print "NO". Print the output without quotes.
;
; Constraints
; 1≤T≤100
; 1≤N,A,B,C≤100

(defun prepare (n a b c)
  (if (and (>= (+ a c) n) (>= b n)) "YES" "NO"))

(assert (string= (prepare 2 1 2 1) "YES"))
(assert (string= (prepare 3 2 2 2) "NO"))
(assert (string= (prepare 4 2 6 3) "YES"))
(assert (string= (prepare 3 1 3 1) "NO"))
