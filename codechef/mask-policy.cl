; A city has been infected by a contagious virus.
;
; In a survey, it was found that A out of the N people living in the city are currently infected. It has been observed that the only way for a person to get infected is if he comes in contact with an already infected person, and both of them are NOT wearing a mask.
;
; The mayor of the city wants to make a new Mask Policy and find out the minimum number of people that will be required to wear a mask to avoid the further spread of the virus. Help the mayor in finding this number.
;
; Note: The only aim of the mayor is to stop virus spread, not to mask every infected person.
;
; Input Format
;
; The first line contains T - number of test cases. Then the test cases follow.
; The first and only line of each test case contains two integers N and A - the total number of people living in the city and the number of people already affected by the virus respectively.
;
; Output Format
;
; For each test case, output the minimum number of people that will be required to wear a mask so as to curb the virus spread.
;
; Constraints
; 1≤T≤10^5
; 2≤N≤400
; 1≤A<N

(defun minimum-people (n a)
  (min (- n a) a))

(assert (= (minimum-people 2 1) 1))
(assert (= (minimum-people 3 2) 1))
(assert (= (minimum-people 3 1) 1))
