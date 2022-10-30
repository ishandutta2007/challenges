; Some people say ‘The shortest distance between two points is a straight line.’ However, this depends on the distance metric employed. Between points (x1,y1) and (x2,y2), the Euclidean (aka straight-line) distance is
; sqrt((x1−x2)^2+(y1−y2)^2)
;
; However, other distance metrics are often useful. For instance, in a city full of buildings, it is often impossible to travel in a straight line between two points, since buildings are in the way.
; In this case, the so-called Manhattan (or city-block) distance is the most useful:
; |x1−x2|+|y1−y2|
;
; Both Euclidean and city-block distance are specific instances of what is more generally called the family of p-norms. The distance according to norm p
; is given by (|x1−x2|^p+|y1−y2|^p)^(1/p)
;
; If we look at Euclidean and Manhattan distances, these are both just specific instances of p=2 and p=1, respectively.
;
; For p<1 this distance measure is not actually a metric, but it may still be interesting sometimes. For this problem, write a program to compute the p-norm distance between pairs of points, for a given value of p.
;
; Input
;
; The input file contains up to 1000 test cases, each of which contains five real numbers, x1 y1 x2 y2 p, each of which have at most 10 digits past the decimal point.
; All coordinates are in the range (0,100] and p is in the range [0.1,10].
; The last test case is followed by a line containing a single zero.
;
; Output
;
; For each test case output the p-norm distance between the two points (x1,y1) and (x2,y2). Your answer may have absolute or relative error of at most 0.0001.

(defun p-norm (x1 y1 x2 y2 p)
  (expt (+ (expt (abs (- x1 x2)) p) (expt (abs (- y1 y2)) p)) (/ 1 p)))

(print (p-norm 1.0 1.0 2.0 2.0 2.0))
(print (p-norm 1.0 1.0 2.0 2.0 1.0))
(print (p-norm 1.0 1.0 20.0 20.0 10.0))
