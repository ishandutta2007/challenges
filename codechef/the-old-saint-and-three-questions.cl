; Once upon a time, there was a hero and an old saint. And like in any story with a hero and an old saint, the old saint asked the hero — three questions!
;
; But here's the twist: each question was a binary question, which means that the answer to each must be either a 'Yes' or a 'No', not none, not both.
; Our hero, who was not so wise in the ways of science, answered them arbitrarily and just hoped he is correct.
; The old saint, being so old, does not remember which answers were correct. The only thing that he remembers is - how many of them were 'Yes', and how many of them were 'No'.
; Our hero will pass the test if the old saint cannot distinguish his responses from the set of correct answers i.e. if the number of 'Yes' and 'No' in the responses matches that in the correct answers, regardless of their order.
;
; You are given the answers to each of the three questions, and the responses of the hero to the same. Find whether the hero will be able to pass the old saint's test.
;
; Input Format
;
; First line will contain T, the number of test cases. The description of the test cases follow.
; The first line of each test case consists of three space-separated integers A1 A2 A3, representing the correct answers to the first, second, and third question respectively (0 for 'No', 1 for 'Yes').
; The second line of each test case consists of three space-separated integers B1 B2 B3, representing the response of the hero to the first, second, and third question respectively (0 for 'No', 1 for 'Yes').
;
; Output Format
;
; For each test case, print "Pass" (without quotes) if the hero passes the old saint's test, "Fail" (without quotes) otherwise.
;
; Constraints
; 1≤T≤64
; 0≤Ai,Bi≤1

(defun query (a b)
  (if (= (reduce #'+ a) (reduce #'+ b)) "Pass" "Fail"))

(assert (string= (query '(1 0 1) '(1 1 0)) "Pass"))
(assert (string= (query '(0 0 0) '(1 1 1)) "Fail"))
(assert (string= (query '(0 0 1) '(1 0 0)) "Pass"))
