; Last night when you went to sleep, you had a strange feeling that you may see the same day again.
; And your strange feeling came to bewhen you woke up, everyone seemed to think that it was yesterday morning! The same strange feeling came back in the evening.
;
; When this pattern continued for days, you looked for help from a time wizard. The wizard says he can break you out of the time loop, but you must chant his spell.
; The wizard gives you a magic number, and you must count up to that number, starting at 1 saying “Abracadabra” each time.
; 
; Input
;
; Input consists of a single integer N (1≤N≤100).
;
; Output
;
; Output the entire wizard’s spell by counting from 1 to N, giving one number and “Abracadabra” per line.


(defun timeloop(n)
  (dotimes(i n)
	(format t "~d Abracadabra~%" (+ i 1)))
  (terpri)
)

(timeloop 5)
(timeloop 10)
