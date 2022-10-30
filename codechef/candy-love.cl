; Sammy and Simmy love candies and frequently visit the local candy shop.
; Sammy and Simmy have bought N candy packs. Packet i contains Ai candies.
; Sammy being the elder one is happy only if she has strictly more candies than Simmy.
; However Simmy, the more sensible one, is happy only if the difference between their number of candies is not more than 1.
;
; The shopkeeper, being a generous lady, agrees to help Sammy and Simmy by distributing the candies among them in a way that makes both of them happy.
; The shopkeeper can open the packs and distribute the candies even within a single pack to different people.
;
; Input:
;
; The first line will contain T, the number of testcases.
; The first line of every test case will contain N, the number of candy packs.
; The next line has N integers, the ith integer denoting Ai, the number of candies in the ith pack.
; 
; Output:
;
; Output "YES" if its possible for the shopkeeper to make both the sisters happy otherwise output "NO".
;
; Constraints
; 1≤T≤10^3
; 1≤N≤10^3
; 1≤Ai≤100

(defun feedable (l)
  (if (= (mod (reduce #'+ l) 2) 1) "YES" "NO"))

(assert (string= (feedable '(5 2)) "YES"))
