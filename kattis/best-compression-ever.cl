; Being educated in Computer Science and Mathematics is not always easy. Especially not if you have “friends” who repeatedly insist on showing you their new “proofs” that P equals NP, that the Riemann Hypothesis is true, and so on.
;
; One of your friends recently claims to have found a fantastic new compression algorithm. As an example of its amazing performance,
; your friend has told you that every file in your precious collection of random bit strings after compression would be at most b bits long!
; Naturally, you find this a bit hard to believe, so you want to determine whether it is even theoretically possible for this to be true.
;
; Your collection of random bit strings consists of N files, no two of which are identical, and each of which is exactly 1000 bits long.
;
; Input
;
; The input consists of two integers N (1≤N≤1015) and b (0≤b≤50), giving the number of files in your collection and the maximum number of bits a compressed file is allowed to have.
;
; Output
;
; Output a line containing either “yes” if it is possible to compress all the N
; files in your collection into files of size at most b bits, or “no” otherwise.

(defun compressible (n b)
  (if (<= n (expt 2 (+ b 1))) "yes" "no"))

(assert (string= (compressible 13 3) "yes"))
(assert (string= (compressible 1 0) "yes"))
(assert (string= (compressible 31415926535897 40) "no"))
