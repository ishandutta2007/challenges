; Yesterday, Chef found K empty boxes in the cooler and decided to fill them with apples.
; He ordered N apples, where N is a multiple of K. Now, he just needs to hire someone who will distribute the apples into the boxes with professional passion.
;
; Only two candidates passed all the interviews for the box filling job.
; In one minute, each candidate can put K apples into boxes, but they do it in different ways: the first candidate puts exactly one apple in each box, while the second one chooses a random box with the smallest number of apples and puts K apples in it.
;
;
; Chef is wondering if the final distribution of apples can even depend on which candidate he hires. Can you answer that question?
;
; Note: The boxes are distinguishable (labeled), while the apples are not.
; Therefore, two distributions of apples are different if there is a box such that the number of apples in it when the first candidate finishes working can be different from the number of apples in it when the second candidate finishes working.
;
; Input
;
; The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains two space-separated integers N and K.
;
; Output
;
; For each test case, print a single line containing the string "YES" if the final distributions of apples can be different or "NO" if they will be the same (without quotes).
;
; Constraints
; 1≤T≤250
; 1≤N,K≤10^18
; N is divisible by K

(defun distributable (n k)
  (if (= (mod (floor n k) k) 0) "NO" "YES"))

(assert (string= (distributable 5 1) "NO"))
(assert (string= (distributable 4 2) "NO"))
(assert (string= (distributable 10 10) "YES"))
