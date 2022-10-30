;; helpers

;; takes in an atom a and see
;; if it exist in the list b
(defun m-member (a b)
  (cond
    ((null b) nil)
    ((eq a (car b)) T)
    (T (m-member a (cdr b)))))

;; append 2 list together and return that list
(defun m-append (a b)
  (cond 
    ((null a) b)
    (T (cons (car a) (m-append (cdr a) b)))))

;; flatten a list
(defun m-flatten (l)
  (cond
    ((null l) nil)
    ((atom l) (list l))
    ((null (car l)) (cons nil (m-flatten (cdr l))))
    (T (m-append (m-flatten (car l))
                 (m-flatten (cdr l))))))

;; return a count of a list
(defun m-count (l)
  (cond
    ((null l) 0)
    (T (+ 1 (m-count (cdr l))))))

;; impl of m-delete that delets a car of
;; a list
(defun m-delete-impl (a l)
  (cond
    ((null l) nil)
    ((atom l) l)
    (T
      (let
        ((e (m-delete-impl a (car l))))
      
        (cond 
          ((eq a e) (m-delete-impl a (cdr l)))
          (T (cons e (m-delete-impl a (cdr l)))))))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;; problem 1
;; see if a is a subset of b
(defun m-subset (a b)
  (cond
    ((null a) T)
    ((null (m-member (car a) b)) nil)
    (T (m-subset (cdr a) b))))

;; problem 2
;; delete atom from list
;; preserving the structure of the list
(defun m-delete (a l)
  (cond
    ;; check to see if list is null first of all
    ((null l) nil)

    ;; then traverse the list
    (T 
      (let 
        ((e (m-delete-impl a (car l))))
        (cond
          ((eq a (car l)) (m-delete a (cdr l)))
          (T (cons e (m-delete a (cdr l)))))))))

;; problem 3
;; insert atom a into the list l before
;; the atom b
;; preserving the structure of the list
(defun m-insert (a b l)
  (cond
    ;; if null return null
    ((null l) nil)

    ;; if it is an atom, the leaves
    ;; just return that
    ((atom l) l)

    ;; else do a DFS
    (T 
      (let 
        ((e (m-insert a b (car l))))
        (cond 
          ((eq b (car l)) (cons a (cons b (m-insert a b (cdr l)))))
          (T (cons e (m-insert a b (cdr l)))))))))


;; problem 4
;; return number of atoms in each sublist
;; in a list
(defun s-count (l)
  (cond
    ((null l) nil)
    ((atom l) 1)
    (T (cons (m-count (m-flatten (car l))) (s-count (cdr l))))))

;; problem 5
;; return max value of the list
;; nil if empty
(defun m-maximum (l)
  (cond 
    ;; if list is empty return nil
    ((null l) nil)

    ;; use reduce to figure out which is 
    ;; the biggest element
    (T (reduce 
         #'(lambda (x y) 
             (cond ((> x y) x) 
                   (T y)))
         l))))

