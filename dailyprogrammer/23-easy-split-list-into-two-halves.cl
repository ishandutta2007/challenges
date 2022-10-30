; Input: a list
;
; Output: Return the two halves as different lists.
;
; If the input list has an odd number, the middle item can go to any of the list.
;
; Your task is to write the function that splits a list in two halves.

(defun split (l)
  (let ((n (ceiling (length l) 2)))
	(values (subseq l 0 n) (subseq l n nil))))

(defun test (l)
  (multiple-value-bind
	(x y) (split l)
	(format t "~d ~d~%" x y)))

(test '(1))
(test '(1 2 3))
(test '(1 2 3 4))
(test '(5 6 7 8 9))
