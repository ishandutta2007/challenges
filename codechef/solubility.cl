; Suppose for a unit rise in temperature, the solubility of sugar in water increases by Bg100 mL.
;
; Chef does an experiment to check how much sugar (in g) he can dissolve given that he initially has 1 liter of water at X degrees and the solubility of sugar at this temperature is Ag100 mL.
; Also, Chef doesn't want to lose any water so he can increase the temperature to at most 100 degrees.
;
; Assuming no loss of water takes place during the process, find the maximum amount of sugar (in g) can be dissolved in 1 liter of water under the given conditions.
;
; Input
;
; The first line contains an integer T, the number of test cases. Then the test cases follow.
; The only line of each test case contains three integers X,A,B.
;
; Output
; For each testcase, output in a single line the answer to the problem.
;
; Constraints
; 1≤T≤1000
; 31≤X≤40
; 101≤A≤120
; 1≤B≤5

(defun amount (x a b)
  (* 10 (+ a (* (- 100 x) b))))

(assert (= (amount 40 120 1) 1800))
(assert (= (amount 35 120 2) 2500))
(assert (= (amount 40 115 3) 2950))
