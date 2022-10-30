; Given n (n is even), determine the number of black cells in an n×n chessboard.
;
; Input Format
;
; The only line of the input contains a single integer n.
;
; Output Format
;
; Output the number of black cells in an n×n chessboard.
;
; Constraints
; 2≤n≤100
; n is even

(defun black-cells (n)
  (/ (* n n) 2))

(assert (= (black-cells 8) 32))
