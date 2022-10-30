; Every year, Pumpkin Pete comes up with a couple of different Jack-O’-Lantern ideas for his annual Halloween special.
; He stacks them up on haystacks for everyone to enjoy and take pictures with.
; To make sure that there’s a wide variety of displays, he wants to make sure many possible Jack-O’-Lanterns designs are available.
; He has come up with many eye, nose, and mouth designs and would like to know how many unique designs are possible. He needs your help to set up the displays before the special kicks off!
;
; Input
;
; The input consists of one line which contains three integers.
; The first, N, indicates the number of eye designs.
; The second, T, indicates the number of nose designs
; The third, M, indicates the number of mouth designs.
; All three values are in the range [1,500].
;
; Output
; 
; Output a single line containing the number of different possible Jack-O’-Lantern designs.

(defun combinations (l)
  (reduce #'* l))

(assert (= (combinations '(3 4 5)) 60))
(assert (= (combinations '(2 2 2)) 8))
(assert (= (combinations '(3 1 5)) 15))
