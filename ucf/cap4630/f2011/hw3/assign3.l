;; Implements the minimax algorithm

;; this is to simulate forward declarations
;; to shut up warnings
(declaim (ftype (function (T) T) max-it))
(declaim (ftype (function (T) T) min-it))

;; helpers
;; check if a list contains just atoms
(defun is-atom-list (l)
  (not (member nil (mapcar 'atom l))))

;; find minimum and maximum element from
;; tuples of the form (index number) 
;; and return it in the tuple of the form
;; (index min) (index max)
(defun find-min-max (l)
  (let ((index 1) (maxi-index 1) (mini-index 1) 
        (mini (car (mapcar 'cadr l)))
        (maxi (car (mapcar 'cadr l))))

    (dolist (i (mapcar 'cadr l) 
        (list (list mini-index mini) (list maxi-index maxi)))

      (if (> i maxi) 
        (progn
          (setf maxi-index index) 
          (setf maxi i)))
    
      (if (< i mini) 
        (progn
          (setf mini-index index)
          (setf mini i)))

      (setf index (1+ index)))))

;; this returns the maximum value of the list
;; in the form of the tuple
;; the maximum part of minimax
(defun max-it (l)
  (cond
    ((null l) nil)
    ((atom l) (list 1 l))
    ((is-atom-list l) (cadr (find-min-max (mapcar 'max-it l))))
    (T (cadr (find-min-max (mapcar 'min-it l))))))

;; this returns the minimum value of the list
;; in the form of the tuple
;; the minimum part of minimax
(defun min-it (l)
  (cond
    ((null l) nil)
    ((atom l) (list 1 l))
    ((is-atom-list l) (car (find-min-max (mapcar 'min-it l))))
    (T (car (find-min-max (mapcar 'max-it l))))))

;; minimax algorithm
(defun minimax (l)
  (max-it l))

