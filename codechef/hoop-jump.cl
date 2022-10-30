; You and your friend are playing a game with hoops. There are N hoops (where N is odd) in a row. You jump into hoop 1, and your friend jumps into hoop N.
; Then you jump into hoop 2, and after that, your friend jumps into hoop N−1, and so on.
;
; The process ends when someone cannot make the next jump because the hoop is occupied by the other person. Find the last hoop that will be jumped into.
;
; Input
;
; The first line contains an integer T, the number of test cases. Then the test cases follow.
; Each test case contains a single line of input, a single integer N.
;
; Output
;
; For each testcase, output in a single line the answer to the problem.
;
; Constraints
; 1≤T≤10^5
; 1≤N<2⋅10^5
; N is odd

(defun last-hoop (n)
  (+ (floor n 2) 1))

(assert (= (last-hoop 1) 1))
(assert (= (last-hoop 3) 2))
