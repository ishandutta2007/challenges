; Your friend has secretly picked N consecutive positive integers between 1 and 100, and wants you to guess if their sum is even or odd.
; If the sum must be even, output ‘Even’. If the sum must be odd, output ‘Odd’. If the sum could be even or could be odd, output ‘Either’.
;
; Input
;
; The input is a single integer N with 1≤N≤10.
;
; Output
;
; Output a single word. The word should be ‘Even’, ‘Odd’, or ‘Either’, according to the rules given earlier.

(defun sum-parity (n)
  (setq r (mod n 4))
  (cond
	((= r 0) "Even")
	((= r 2) "Odd")
	(t "Either")))

(assert (string= (sum-parity 1) "Either"))
(assert (string= (sum-parity 2) "Odd"))
