; Alice has a standard deck of 52 cards. She wants to play a card game with K−1 of her friends.
; This particular game requires each person to have an equal number of cards, so Alice needs to discard a certain number of cards from her deck so that she can equally distribute the remaining cards amongst her and her friends.
;
; Find the minimum number of cards Alice has to discard such that she can play the game.
;
; Note: It doesn't matter which person gets which card. The only thing that matters is that each person should have an equal number of cards.
;
; Input Format
;
; The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
; Each test case consists of a single line of input, containing a single integer K — the number of people playing the game (including Alice).
;
; Output Format
;
; For each test case, output in a single line the minimum number of cards Alice has to discard from her deck such that she can play the game with her friends.
;
; Constraints
; 1≤T≤51
; 2≤K≤52

(defun discard (k)
  (mod 52 k))

(assert (= (discard 3) 1))
(assert (= (discard 50) 2))
(assert (= (discard 2) 0))
(assert (= (discard 14) 10))
