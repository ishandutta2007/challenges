; You are given an integer N where N≤10. Consider any array A with length N where each element can either be 0, 1, or 2, we define f(A) as the number of extrema in A.
; You need to find the sum of f(A) over all possible arrays A.
;
; Note:
;
; In an array A, we consider Ai as an extremum if it is strictly greater than both of its neighbors (i.e. Ai>Ai−1 and Ai>Ai+1), or if it is strictly smaller than both of its neighbors (i.e. Ai<Ai−1 and Ai<Ai+1).
; Note that first and last elements are not counted as extremum.
; Extrema is the plural of extremum.
; 
; Input Format
;
; The first line of the input contains an integer T - the number of test cases. The test cases then follow.
; The only line of each test case contains one integer N.
; Output Format
;
; For each test case, output on a single the sum of f(A) over all possible arrays A.
;
; Constraints
; 1≤T≤10
; 1≤N≤10

(defun peaks (n)
  (if (< n 3) 0 (* 10 (- n 2) (expt 3 (- n 3)))))

(assert (= (peaks 1) 0))
(assert (= (peaks 3) 10))
(assert (= (peaks 5) 270))

