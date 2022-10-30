; Jessica wants to become a javelin thrower, moreover she wants to become a famous one. However, she doesn’t want to train 40
; hours a day. To avoid much training while still becoming famous, she has concocted a plan: make all her javelins gigantic.
;
; As a software developer by day, she knows she needs a minimum viable javelin for testing, but also that you can glue existing things hastily together and get something that works alright.
;
; She has a couple of steel rods next to her bed – as one does – and decides to go to the blacksmith apprentice Jack to get him to fuse them together.
;
; The good thing about Jack is that he’ll fuse the steel rods together for free. But Jack isn’t that good at fusing things together. When fusing two rods, the fused rod will lose 1 cm of their combined length.
;
; That’s not a problem for Jessica, but she wonders how big her javelin will become if Jack fuses all the rods together.
;
; Input
;
; The first line consist of an integer N, the number of steel rods she has. Then follows N lines, each containing a single integer li
;
; representing the length of the steel rod in cm.
;
; Output
;
; Print out the length of the jumbo javelin Jack has made for her.
; Limits
;
; 1<N≤100
;
; 1≤li≤50

(defun javelin (l)
  (- (reduce #'+ l) (- (length l) 1)))

(assert (= (javelin '(21 34 18 9)) 79))
(assert (= (javelin '(1 50 40)) 89))
