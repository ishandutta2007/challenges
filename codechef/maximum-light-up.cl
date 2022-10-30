; Chef has allocated himself a budget of P rupees to buy Diwali crackers.
; There are only 3 types of crackers available in the market and each type of cracker can be bought any number of times.
;
; Fuljhari, where each costs a rupees
; Anar, where each costs b rupees
; Chakri, where each costs c rupees
; The crackers have the following interesting properties:-
;
; A Fuljhari can be lit on its own
; To light an Anar, you will need x Fuljharis
; To light a Chakri, you will need y Fuljharis
; What's the maximum total of Anars and Chakris that Chef can light up with his given budget.
;
; Input Format
;
; First line of input will contain T, the number of test cases. Then the test cases follow.
; Each test case contains of a single line of input, six integers P, a, b, c, x and y.
;
; Output Format
;
; For each test case, output in a single line the maximum total of Anars and Chakris Chef can light up.
;
; Constraints
; 1≤T≤10^5
; 1≤P,a,b,c,x,y≤10^9

(defun lights (P a b c x y)
  (floor P (min (+ b (* x a)) (+ c (* y a)))))

(assert (= (lights 100 5 5 10 4 8) 4))
(assert (= (lights 16 2 2 2 1 1) 4))
(assert (= (lights 55 1 2 3 4 5) 9))
