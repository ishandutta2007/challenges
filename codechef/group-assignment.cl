; Chef's professor is planning to give his class a group assignment. There are 2N students in the class, with distinct roll numbers ranging from 1 to 2N. Chef's roll number is X.
;
; The professor decided to create N groups of 2 students each. The groups were created as follows: the first group consists of roll numbers 1 and 2N, the second group of roll numbers 2 and 2N−1, and so on, with the final group consisting of roll numbers N and N+1.
;
; Chef wonders who his partner will be. Can you help Chef by telling him the roll number of his partner?
;
; Input Format
;
; The first line of input will contain an integer T — the number of test cases. The description of T test cases follows.
; The first and only line of each test case contains two integers N and X, denoting the number of groups that will be formed, and Chef's roll number.
;
; Output Format
;
; For each test case, output the roll number of the student that will be Chef's partner.
;
; Constraints
; 1≤T≤10^3
; 1≤N≤10^8
; 1≤X≤2N

(defun roll-number (n x)
  (+ (- (* 2 n) x) 1))

(assert (= (roll-number 2 2) 3))
(assert (= (roll-number 3 1) 6))
(assert (= (roll-number 3 4) 3))
