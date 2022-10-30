; You are a person who is always fond of eating candies. Your friend gave you a candy of length N, to eat during the break period of your school.
;
; You start eating this candy from one of the ends. But as it is not your candy, your friend told you to eat exactly K unit length of candy during each bite. You will stop eating if the candy's length becomes 0. This means that you have eaten the entire candy.
;
; If at some point of time, the candy's length is positive, but less than K, you cannot take a bite thereafter.
;
; Can you eat the complete candy? If yes, print the number bites it will take, else print −1.
;
; Input Format
;
; First line will contain T, number of testcases. Then the testcases follow.
; Each testcase contains of two spaced integers N, K.
;
; Output Format
;
; For each testcase, print the minimum number of bites you need to eat the complete candy. Print −1 if it is not possible to do so.
;
; Constraints
; 1≤T≤10^5
; 0≤N≤10^6
; 1≤K≤10^6

(defun eat (n k)
  (if (= k 0)
	-1
	(if (= (mod n k) 0) (floor n k) -1)))

(assert (= (eat 3 1) 3))
(assert (= (eat 3 2) -1))
(assert (= (eat 0 3) 0))
(assert (= (eat 0 0) -1))
