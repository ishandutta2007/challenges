; Chef and his friend is standing on the X-axis at the points X1 and X2 respectively.
;
; Chef moves one step forward each second (that is he moves to X1+1 after the 1st second, X1+2 after the 2nd second, and so on),
; whereas his friend moves 2 steps forward each second (that is he moves to X2+2 after the 1st second, X2+4 after the 2nd second, and so on).
;
; You need to determine if Chef will be able to meet his friend or not. You can assume that Chef and his friend both keep on moving for a long indefinite amount of time and also that they move simultaneously.
;
; Input Format
;
; The first line contains T - the number of test cases. Then the test cases follow.
; The first line of each test case contain two space-separated integers X1 and X2 - the position of Chef and his friend at the start respectively.
;
; Output Format
;
; For each test case, output on a single line YES (without quotes) if Chef can meet his friend, and NO otherwise.
;
; You may print each character of the string in uppercase or lowercase (for example, the strings YeS, YEs, yes and yeS will all be treated as identical).
;
; Constraints
; 1≤T≤10^5
; 1≤X1,X2≤10^9

(defun meetable (x1 x2)
  (if (<= x2 x1) "YES" "NO"))

(assert (string= (meetable 1 1) "YES"))
(assert (string= (meetable 1 7) "NO"))
(assert (string= (meetable 7 1) "YES"))
