; In the United States of America, telephone numbers within an area code consist of seven digits: the prefix number is the first three digits and the line number is the last four digits.
; Traditionally, the 555 prefix number has been used to provide directory information and assistance as in the following examples:
;
;    555-1212
;
;    555-9876
;
;    555-5000
;
;    555-7777
;
; Telephone company switching hardware would detect the 555 prefix and route the call to a directory information operator. Nowadays, telephone switching is done digitally and somewhere along the line a computer decides where to route calls.
;
; For this problem, write a program that determines if a supplied seven-digit telephone number should be routed to the directory information operator, that is, the prefix number is 555.
;
; Input
;
; The single line of input contains a single integer n (1000000≤n≤9999999), which is a telephone number.
;
; Output
;
; Output a single integer, which is 1 if the number should be routed to the directory information operator, or 0 if the number should not be routed to the directory information operator.

(defun fyi (s)
  (setq i (search "555" s))
  (if (eq i 0) 1 0))

(assert (eq (fyi "5551212") 1))
(assert (eq (fyi "5519876") 0))
(assert (eq (fyi "5055555") 0))
(assert (eq (fyi "5550000") 1))
