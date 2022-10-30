; Research often involves dealing with large quantities of data, and those data are often too massive to examine manually.
; Statistical descriptions of data can help humans understand their basic properties.
; Consider a sample of n numbers X=(x1,x2,…,xn). Of many statistics that can be computed on X, some of the most important are the following:
;
; min(X): the smallest value in X
;
; max(X): the largest value in X
;
; range(X): max(X)−min(X)
;
; Write a program that will analyze samples of data and report these values for each sample.
; Input
;
; The input contains between 1 and 10 test cases.
; Each test case is described by one line of input, which begins with an integer 1≤n≤30 and is followed by n integers which make up the sample to be analyzed.
; Each value in the sample will be in the range −1000000 to 1000000. Input ends at the end of file.
;
; Output
;
; For each case, display Case X:, where X is the case number, followed by the min, max, and range of the sample (in that order). Follow the format of the sample output.

(defun stat (l)
  (setq a (reduce #'min l))
  (setq b (reduce #'max l))
  (values a b (- b a)))

(defun test (n l)
  (multiple-value-bind (a b c) (stat l)
	(format t "Case ~d: ~d ~d ~d ~%" n a b c)))

(test 1 '(4 10))
(test 2 '(2 5 6 4 5 9 2 1 4))
(test 3 '(7 6 10 1 2 5 10 9))
(test 4 '(9))
