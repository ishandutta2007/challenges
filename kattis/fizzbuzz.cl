; According to Wikipedia, FizzBuzz is a group word game for children to teach them about division. This may or may not be true, but this question is generally used to torture screen young computer science graduates during programming interviews.
;
; Basically, this is how it works: you print the integers from 1 to N, replacing any of them divisible by X with Fizz or, if they are divisible by Y, with Buzz. If the number is divisible by both X and Y, you print FizzBuzz instead.
;
; Check the samples for further clarification.
;
; Input
;
; Input contains a single test case. Each test case contains three integers on a single line, X, Y and N (1≤X<Y≤N≤100).
;
; Output
;
; Print integers from 1 to N in order, each on its own line, replacing the ones divisible by X with Fizz, the ones divisible by Y with Buzz and ones divisible by both X and Y with FizzBuzz.

(defun fizzbuzz (x y n)
  (loop for i from 1 to n do
	(cond
	  ((and (= (mod i x) 0) (= (mod i y) 0)) (format t "FizzBuzz~%"))
	  ((= (mod i x) 0) (format t "Fizz~%"))
	  ((= (mod i y) 0) (format t "Buzz~%"))
	  (t (format t "~d~%" i)))))

(fizzbuzz 2 3 7)
(fizzbuzz 2 4 7)
(fizzbuzz 3 5 7)
