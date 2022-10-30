; A long time ago, the Egyptians figured out that a triangle with sides of length 3, 4, and 5 had a right angle as its largest angle.
; You must determine if other triangles have a similar property.
;
; Input
;
; Input represents several test cases (at most 1000), followed by a line containing 0 0 0. Each test case has three positive integers, at most 30000, denoting the lengths of the sides of a triangle.
;
; Output
;
; For each test case, a line containing “right” if the triangle is a right triangle, and a line containing “wrong” if the triangle is not a right triangle.

(defun right-triangle (a b c)
  (setq l (sort (list a b c) #'<))
  (setq x (car l))
  (setq y (cadr l))
  (setq z (caddr l))
  (if
    (= (+ (* x x) (* y y)) (* z z)) "right"
    "wrong"))

(assert (string= (right-triangle 6 8 10) "right"))
(assert (string= (right-triangle 25 52 60) "wrong"))
(assert (string= (right-triangle 5 12 13) "right"))
