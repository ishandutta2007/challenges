; There are three cities and thus three EVMs. An insider told Chef that his party got A,B,C votes respectively in these three cities according to the EVMs.
; Also, the total number of votes cast are P,Q,R respectively for the three cities.
;
; Chef, being the party leader, can hack at most one EVM so that his party wins. On hacking a particular EVM all the votes cast in that EVM are counted in favor of Chef's party.
;
; A party must secure strictly more than half of the total number of votes cast in order to be considered the winner. Can Chef achieve his objective of winning by hacking at most one EVM?
;
; Input Format
;
; The first line of input contains an integer T, denoting the number of test cases. The description of T test cases follows.
; Each test case consists of a single line of input, containing six space-separated integers — in order, A,B,C,P,Q,R.
;
; Output Format
;
; For each test case, output in a single line the answer — "YES", if Chef can win the stealable after hacking at most one EVM and "NO" if not.
;
; You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
;
; Constraints
; 1≤T≤5⋅10^3
; 0≤A<P≤100
; 0≤B<Q≤100
; 0≤C<R≤100

(defun stealable (a b c p q r)
  (setq d (max (- p a) (- q b) (- r c)))
  (if (> (+ a b c d) (floor (+ p q r) 2)) "YES" "NO"))

(assert (string= (stealable 1 1 1 3 3 3) "YES"))
(assert (string= (stealable 49 1 49 50 100 50) "YES"))
(assert (string= (stealable 0 0 0 1 1 1) "NO"))
