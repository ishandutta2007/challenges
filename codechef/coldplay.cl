; Chef is a big fan of Coldplay. Every Sunday, he will drive to a park taking M minutes to reach there, and during the ride he will play a single song on a loop.
; Today, he has got the latest song which is in total S minutes long. He is interested to know how many times will he be able to play the song completely.
;
; Input
; The first line contains an integer T - the number of test cases. Then the test cases follow.
; The only line of each test case contains two space-separated integers M,S - the duration of the trip and the duration of the song, both in minutes.
;
; Output
;
; For each test case, output in a single line the answer to the problem.
;
; Constraints
; 1≤T≤1000
; 1≤M≤100
; 1≤S≤10

(defun cycle (m s)
  (floor m s))

(assert (= (cycle 10 5) 2))
(assert (= (cycle 10 6) 1))
(assert (= (cycle 9 10) 0))
