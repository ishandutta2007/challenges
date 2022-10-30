; You are given a standard 8×8 chessboard which has exactly 2 rooks on it and no other pieces.
; The rows are numbered 1 to 8 from bottom to top, and the columns are numbered 1 to 8 from left to right.
; The cell at the intersection of the i-th column and j-th row is denoted (i,j).
;
; Given the initial positions of the rooks in the form of coordinates (X1,Y1) and (X2,Y2), you need to tell whether the 2 rooks currently attack each other or not. Assume, each square can contain at most one piece.
;
; Rooks can only travel in straight lines along the row or column they are placed at, and can't jump over other pieces. For a more detailed explanation of the moves of rooks, along with images, please click here.
;
; Input Format
;
; The first line contains T - the number of test cases. Then the test cases follow.
; The first line of each test case contain four space-separated integers each X1,Y1,X2,Y2 - (X1,Y1) is the position of the first rook and (X2,Y2) is the position of the second rook.
;
; Output Format
;
; For each test case, output on a single line YES (without quotes) if the rooks attack each other, and NO otherwise.
;
; You may print each character of the string in uppercase or lowercase (for example, the strings YeS, YEs, yes and yeS will all be treated as identical).
;
; Constraints
; 1≤T≤5000
; 1≤X1,X2,Y1,Y2≤8
; (X1,Y1)≠(X2,Y2)

(defun attackable (x1 y1 x2 y2)
  (if (or (= x1 x2) (= y1 y2)) "YES" "NO"))

(assert (string= (attackable 1 2 5 2) "YES"))
(assert (string= (attackable 1 2 1 5) "YES"))
(assert (string= (attackable 1 1 8 8) "NO"))
