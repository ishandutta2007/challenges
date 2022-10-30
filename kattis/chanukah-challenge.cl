; The Jewish holiday of Chanukah lasts for eight days and eight nights. On the evening before each day, candles are lit in a menorah. On the first evening, one candle is lit, on the second, two are lit, and so on.
; However, each evening, an extra candle, called the shammas, is also lit (in fact, this candle is used to light the other candles). Thus, for the entire holiday, 44 candles are necessary.
;
; But what if Chanukah lasted a different number of days? How many candles would be needed?
;
; For this problem, you will write a program that determines how many candles would be necessary for a Chanukah holiday lasting for a given number of days.
;
; Input
;
; The first line of input contains a single decimal integer P, (1≤P≤10000), which is the number of data sets that follow.
; Each data set should be processed identically and independently.
;
; Each data set consists of a single line of input. It contains the data set number, Kfollowed by a single space, followed by a single decimal integer N, (1≤N≤10000), which gives the number of days to assume for the holiday.
; The data set number K starts at 1 and is incremented by 1 for each data set.
;
; Output
;
; For each data set there is one line of output. The single output line consists of the data set number, K, followed by a space followed by the number of candles needed for an N-day Chanukah holiday.

(defun chanukah (k n)
  (values k (+ (/ (* n (+ n 1)) 2) n)))

(defun test (k n)
  (multiple-value-bind (x y) (chanukah k n)
	(format t "~d ~d~%" x y)))

(test 1 8)
(test 2 1)
(test 3 10)
