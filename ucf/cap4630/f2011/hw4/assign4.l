;; Implements backward chaining

;; to shut up warnings about setq
(defvar *rules*)
(defvar *dbf*)

;; this is to simulate forward declarations
;; to shut up warnings
(declaim (ftype (function (T) T) l1-or-tree))
(declaim (ftype (function (T) T) try-rule))
(declaim (ftype (function (T) T) prove))

;; the rules 
(setq *rules* '(
      (R1 (&and (a b c))   (x))
      (R2 (&and (a v c))   (y))
      (R3 (&and (a v m))   (y))
      (R4 (&and (a v m))   (x))
      (R5 (&and (t p))     (a))
      (R6 (&and (w  m))    (a))
      (R7 (&and (a b))     (c))))
   
;; the database of facts
(setq *dbf* '(b m w)) 

;; return all rules related to an atom, nil otherwise
(defun lookup-rule (v)
  (remove nil (mapcar 
                #'(lambda (x)
                    (cond
                       ((eq v (caaddr x)) 
                        (list (car x) (caadr x) (cadadr x)))
                       (T nil))) *rules*)))

;; generate an or tree of ands to see if
;; any satisfies a rule, if it is add it to the
;; database of facts
(defun l1-or-tree (r)
  (print (list 'l1-or-tree r))
  (cond
    ((null r) nil)
    (T 
      (dolist (x r)
        (if (try-rule x) 
         (return-from l1-or-tree T)))))
  nil)

;; try the rule to see if we can prove it
(defun try-rule (v)
  (print (list 'trying-rule v))
  (dolist (x (caddr v))
    (cond
      ((null (prove x)) 
       (progn
         (print (list 'fail v))
         (return-from try-rule nil)))))
  (print (list 'proved v))
  T)

;; prove a goal
(defun prove (g)
  (print (list 'proving-goal g))
  (cond
    ((member g *dbf*) 
     (progn
       (print (list g 'given))
       T))
    (T (l1-or-tree (lookup-rule g)))))
