; There are 3 problems in a contest namely A,B,C respectively. Alice bets Bob that problem C is the hardest while Bob says that problem B will be the hardest.
;
; You are given three integers SA,SB,SC which denotes the number of successful submissions of the problems A,B,C respectively. It is guaranteed that each problem has a different number of submissions. Determine who wins the bet.
;
; 1) If Alice wins the bet (i.e. problem C is the hardest), then output Alice.
;
; 2) If Bob wins the bet (i.e. problem B is the hardest), then output Bob.
;
; 3) If no one wins the bet (i.e. problem A is the hardest), then output Draw.
;
; Note: The hardest problem is the problem with the least number of successful submissions.
;
; Input Format
;
; The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains three space-separated integers SA,SB,SC, denoting the number of successful submissions of problems A,B,C respectively.
;
; Output Format
;
; For each test case, output the winner of the bet or print Draw in case no one wins the bet.
;
; Constraints
; 1≤T≤100
; 1≤SA,SB,SC≤100
; SA,SB,SC are all distinct.

(defun outcome (a b c)
  (cond
	((and (< c a) (< c b)) "Alice")
	((and (< b a) (< b c)) "Bob")
	(t "Draw")))

(assert (string= (outcome 1 4 2) "Draw"))
(assert (string= (outcome 16 8 10) "Bob"))
(assert (string= (outcome 14 15 9) "Alice"))
