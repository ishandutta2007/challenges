;; helpers
;; check if a list contains just atoms
(defun is-atom-list (l)
  (cond
    ((null l) T)
    ((atom (car l)) (is-atom-list (cdr l)))
    (T nil)))

;; get one level deep in a list
(defun list-one-level (l)
  (cond 
    ((or (atom l) (null l)) nil)
    ((atom (car l)) (list-one-level (cdr l)))
    (T (append (car l) (list-one-level (cdr l))))))

;; max depth of tree implementation
(defun m-depth-impl (l a b)
  (cond
    ((null l) (max a b))
    ((atom l) (max a b))

    (T
      (let 
        ((c (m-depth-impl (car l) (+ 1 a) b)))
        (m-depth-impl (cdr l) a c)))))

;; functions

;; #1 get all atoms which are 
;; immediately followed by another atom.
;; Output to a flat list
(defun followed-by (l)
  (cond
    ((null l) nil)
    ((atom l) l)
    
    (T 
      (let
        ((e (followed-by (car l))))
        (cond
          ((atom e)
           (cond
             ((and (eq (car l) e) (not (null (cdr l))) (atom (cadr l)))
                (append (list e) (followed-by (cdr l))))
             (T (followed-by (cdr l)))))
          (T (append e (followed-by (cdr l)))))))))

;; #2 check if it is a well-formed formula
(defun wff (l)
  (cond
    ((null l) nil)
    ((atom l)
     (case l
       ((p q r s t u v w) T)))
    (T
      (let
        ((a (wff (nth 1 l)))
         (b (wff (nth 2 l)))
         (c (wff (nth 3 l)))
         (n (length l)))
      (case (car l)
        ((not)
         (cond
           ((and (eq a T) (eq n 2)) T)
           (T nil)))

        ((oor andd if)
         (cond
           ((and (eq a T) (eq b T) (eq n 3)) T)
           (T nil)))

        ((x3)
         (cond
           ((and (eq a T) (eq b T) (eq c T) (eq n 4)) T)
           (T nil))))))))

;; #3 returns an atom in the deepest level of the list
(defun m-deepest (l)
  (cond
    ((null l) nil)
    ((is-atom-list l) (car l))
    (T (m-deepest (list-one-level l)))))

;; #4 get depth of tree
(defun m-depth (l)
  (m-depth-impl l 0 0))
  
