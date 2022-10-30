; The mean of a population (x1,…,xn) is defined as x¯=1/n∑i=1 to n xi. The (uncorrected) standard deviation of the population is defined as sqrt(1/n*∑(xi−x¯)^2).
; It measures how dispersed the population is: a large standard deviation indicates that the values are far apart; a low standard deviation indicates that they are close. If all values are identical, the standard deviation is 0.
;
; Write a program or function which takes as input a (non-empty) list of non-negative integers, and outputs its standard deviation. But check the scoring rule, as this is not code golf!
; Input/Output
;
; Input/Output is flexible. Your answer must be accurate to at least 2 decimal places (either rounding or truncating). The input is guaranteed to contain only integers between 0 and 255, and to not be empty.
; Scoring
;
; To compute your score, convert your code to integer code points (using ASCII or whatever code page is standard for your language) and compute the standard deviation.
; Your score is the number of bytes in your code multiplied by the standard deviation. Lower score is better. You should therefore aim for code which at the same time (a) is short and (b) uses characters with close codepoints.
;
; Here is an online calculator to compute your score (assuming you use ASCII).
; Test cases
;
; Input              | Output
; 77 67 77 67        | 5
; 82                 | 0
; 73 73 73           | 0
; 83 116  97 116 115 | 13.336
;
; A word of caution about built-ins: if your language has a built-in, that's fine (and good for you if it only uses one character!). But make sure that it uses n
; and not n−1 as the denominator in the formula, or else your answer won't be valid.

(defun mean (xs)
  (/ (reduce #'+ xs) (length xs)))

(defun ustddev (xs)
  (setq xm (mean xs))
  (setq ys (map 'list (lambda (x) (* (- x xm) (- x xm))) xs))
  (sqrt (/ (reduce #'+ ys) (length ys))))

(print (ustddev '(77 67 77 67)))
(print (ustddev '(82)))
(print (ustddev '(73 73 73)))
(print (ustddev '(83 116 97 116 115)))
