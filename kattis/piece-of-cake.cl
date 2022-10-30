; It is Greg’s birthday! To celebrate, his friend Sam invites Greg and two other friends for a small party. Of course, every birthday party must have cake.
;
; Sam ordered a square cake. She makes a single horizontal cut and a single vertical cut. In her excitement to eat cake, Sam forgot to make these cuts through the middle of the cake.
;
; Of course, the biggest piece of cake should go to Greg since it is his birthday. Help Sam determine the volume of the biggest piece of cake that resulted from these two cuts.
;
; \includegraphics{cake.png}
; Input
;
; The input consists of a single line containing three integers n (2≤n≤10000), the length of the sides of the square cake in centimeters, h (0<h<n),
; the distance of the horizontal cut from the top edge of the cake in centimeters,
; and v (0<v<n), the distance of the vertical cut from the left edge of the cake in centimeters.
; This is illustrated in the figure above.
;
; Each cake is 4 centimeters thick.
;
; Output
;
; Display the volume (in cubic centimeters) of the largest of the four pieces of cake after the horizontal and vertical cuts are made.


(defun volume (n v h)
  (* (max v (- n v)) (* (max h (- n h)) 4)))

(assert (= (volume 10 4 7) 168))
(assert (= (volume 5 2 2) 36))
(assert (= (volume 4 2 1) 24))
