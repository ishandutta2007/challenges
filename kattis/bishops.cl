; Yesterday was Sam’s birthday. The most interesting gift was definitely the chessboard. Sam quickly learned the rules of chess and defeated his father, all his friends, his little sister, and now no one wants to play with him any more.
;
; So he decided to play with another birthday gift – a Book of Math Problems for Young Mathematicians.
; He opened the book somewhere in the middle and read the following problem: "How many knights can be placed on a chessboard without threatening each other?"
; After a while he realized that this was trivial and moved on to the next problem: "How many bishops can be placed on a chessboard without threatening each other?".
; Sam is in trouble here. He is not able to solve this problem and needs your help.
;
; Task
;
; Sam’s chessboard has size N×N. A bishop can move to any distance in any of the four diagonal directions.
; A bishop threatens another bishop if it can move to the other bishop’s position. Your task is to compute the maximum number of bishops that can be placed on a chessboard in such a way that no two bishops threaten each other.
;
; Input
;
; The input file consists of several lines. The line number i contains a positive integer representing the size of the i-th chessboard.
; The size of each chessboard is at most 1000000.
;
; Output
;
; The output file should contain the same number of lines as the input file. The i-th line should contain one number – the maximum number of bishops that can be placed on i-th chessboard without threatening each other.

(defun bishops (n)
  (if
    (< n 2) n
    (* 2 (- n 1))))

(assert (= (bishops 2) 2))
(assert (= (bishops 3) 4))
