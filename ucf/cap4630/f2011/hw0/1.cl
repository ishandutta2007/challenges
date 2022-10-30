;; add 2 natural numbers together
(defun m-plus (a b)
  (cond 
    ((eq a 0) b)
    (T (m-plus (1- a) (1+ b)))))

;; append 2 list together and return that list
(defun m-append (a b)
  (cond 
    ((null a) b)
    (T (cons (car a) (m-append (cdr a) b)))))

;; count occurence of an element in a list
(defun m-count (a b)
  (cond
    ((null b) 0)
    ((eq a (car b)) (+ 1 (m-count a (cdr b))))
    (T (m-count a (cdr b)))))

;; flatten a list
(defun m-flatten (l)
  (cond
    ((null l) nil)
    ((atom l) (list l))
    (T (m-append (m-flatten (car l))
                 (m-flatten (cdr l))))))
