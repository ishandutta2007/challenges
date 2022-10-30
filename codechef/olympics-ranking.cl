; In Olympics, the countries are ranked by the total number of medals won.
; You are given six integers G1, S1, B1, and G2, S2, B2, the number of gold, silver and bronze medals won by two different countries respectively.
; Determine which country is ranked better on the leaderboard. It is guaranteed that there will not be a tie between the two countries.
;
; Input Format
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
;
; The first and only line of each test case contains six space-separated integers G1, S1, B1, and G2, S2, B2.
;
; Output Format
;
; For each test case, print "1" if the first country is ranked better or "2" otherwise. Output the answer without quotes.
;
; Constraints
; 1≤T≤1000
; 0≤G1,S1,B1,G2,S2,B2≤30

(defun ranking (g1 s1 b1 g2 s2 b2)
  (if (> (+ g1 s1 b1) (+ g2 s2 b2)) 1 2))

(assert (= (ranking 10 20 30 0 29 30) 1))
(assert (= (ranking 0 0 0 0 0 1) 2))
(assert (= (ranking 1 1 1 0 0 0) 1))
