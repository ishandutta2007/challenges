; The English word “mile” derives from the Latin “mille passus”, meaning “a thousand paces”.
; A Roman mile was the distance a soldier would walk in 1000 paces (a pace being two steps, one with each foot).
;
; Over time, the actual distance referred to as a “mile” has changed. The modern English mile is 5280 (modern) feet.
; The Roman mile is believed to have been about 4854 (modern) feet. Therefore a distance of x English miles would correspond to 1000⋅5280/4854 Roman paces.
;
; Write a program to convert distances in English miles into Roman paces.
;
; Input
;
; Input will consist of a single line containing a single real number 0≤X≤1000 denoting a distance in English miles.
; The number X has at most 3 digits of precision after the decimal point.
;
; Output
;
; Print an integer denoting the closest number of Roman paces equivalent to X.
; Your answer should be rounded to the closest integer (with an exact .5 decimal part rounded up).

(defun paces (x)
  (round (/ (* x 1000 5280) 4854)))

(assert (= (paces 1.0) 1088))
(assert (= (paces 20.267) 22046))
