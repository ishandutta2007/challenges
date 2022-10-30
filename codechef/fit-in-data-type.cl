; Chef wants to store some important numerical data on his personal computer.
; He is using a new data type that can store values only from 0 till N both inclusive.
; If this data type receives a value greater than N then it is cyclically converted to fit into the range 0 to N. For example:
;
; Value N+1 will be stored as 0.
; Value N+2 will be stored as 1.
; and so on…
;
; Given X, the value chef wants to store in this new data type. Determine what will be the actual value in memory after storing X.
;
; Input Format
;
; First line will contain T, number of testcases. Then the testcases follow.
; Each testcase contains a single line of input, two space separated integers N,X - the maximum value a data type can store and the value Chef wants to store in the data type respectively.
;
; Output Format
;
; For each testcase, output in a single line the value which will be actually stored in memory.
;
; Constraints
; 1≤T≤3000
; 1≤N≤50
; 0≤X≤50

(defun value (n x)
  (mod x (+ n 1)))

(assert (= (value 15 0) 0))
(assert (= (value 15 10) 10))
(assert (= (value 11 12) 0))
(assert (= (value 27 37) 9))
(assert (= (value 50 49) 49))
