; Alice, Bob, and Clara are eating at a new restaurant today.
; They’re having trouble deciding what to order, so Alice proposes that they each pick some items from the menu, and then they will order the items that everyone picked.
; The menu has m items, and Alice, Bob, and Clara will order a, b, and c items respectively.
; Is it possible for them to pick some items such that no item is picked by everyone?
;
; Input
;
; The input contains a single line with four integers, m, a, b, c, where 1≤m≤100,000, and 1≤a,b,c≤m.
;
; Output
;
; If it’s possible for Alice, Bob, and Clara to pick some item such that no item on the menu is picked by everyone, print “possible” (without quotes). Otherwise, print “impossible”.

(defun abundance (m a b c)
  (if (>= (* 2 m) (+ a b c)) "possible" "impossible"))

(assert (string= (abundance 6 2 2 2) "possible"))
(assert (string= (abundance 1 1 1 1) "impossible"))
