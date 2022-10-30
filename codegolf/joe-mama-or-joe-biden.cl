; Randomly pick and print "Joe Mama" or "Joe Biden" in as little bytes as possible.
;
; Rules
;
;    No trailing lines, spaces, or anything else weird like that
;    No election fraud! Both "Joe Mama" and "Joe Biden" must have equal chaces of winning
;
; Prize
;
; The winner will get a spot in https://github.com/Sid220/joe-mama-or-joe-biden, even if that language is already there.

(defun random-joe ()
  (if (< (random 1.0 (make-random-state t)) 0.5) "Joe Mama" "Joe Biden"))

(dotimes (i 50)
  (print (random-joe)))
