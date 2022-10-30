; When someone calls Ivan lazy, he claims that it is his intelligence that helps him to be so.
; If his intelligence allows him to do something at less physical effort, why should he exert more?
; He also claims that he always uses his brain and tries to do some work at less effort; this is not his laziness, rather this is his intellectual smartness.
; Once Ivan was asked to cut a pizza into seven pieces to distribute it among his friends. (Size of the pieces may not be the same.
; In fact, his piece will be larger than the others.)
; He thought a bit, and came to the conclusion that he can cut it into seven pieces by only three straight cuts through the pizza with a pizza knife.
; Accordingly, he cut the pizza in the following way (guess which one is Ivan’s piece):
; One of his friends, who never believed in Ivan’s smartness, was startled at this intelligence. He thought, if Ivan can do it, why can’t my computer?
; So he tried to do a similar (but not exactly as Ivan’s, for Ivan will criticize him for stealing his idea) job with his computer.
; He wrote a program that took the number of straight cuts one makes through the pizza, and output a number representing the maximum number of pizza pieces it will produce.
; Your job here is to write a similar program. It is ensured that Ivan’s friend won’t criticize you for doing the same job he did.
;
; Input
;
; The input file will contain a single integer N (0 ≤ N ≤ 210000000) in each line representing the number ; of straight line cuts one makes through the pizza.
; A negative number terminates the input.
;
; Output
;
; Output the maximum number of pizza pieces the given number of cuts can produce.
; Each line should contain only one output integer without any leading or trailing space.
;
; Sample Input
;
; 5
; 10
; -100
; Sample Output
;
; 16
; 56

(defun pizza (n)
  (+ (floor (* n (+ n 1)) 2) 1))

(assert (= (pizza 5) 16))
(assert (= (pizza 10) 56))
