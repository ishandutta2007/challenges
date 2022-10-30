; It gets tiring, looking for all ways in which the word ‘problem’ can be used (and mis-used) in the news media.
; And yet, that’s been your job for several years: looking through news stories for that word.
; Wouldn’t it be better if you could automate the process?
;
; Input
;
; Each line of input is one test case. Lines are at most 80 characters long. There are at most 1000 lines of input. Input ends at end of file.
; Output
;
; For each line of input, print yes if the line contains ‘problem’, and no otherwise. Any capitalization of ‘problem’ counts as an occurrence.

(defun has-problem (s)
  (if (search "problem" s :test #'char-equal) "yes" "no"))

(assert (string= (has-problem "Problematic pair programming") "yes"))
(assert (string= (has-problem "\"There's a joke that pairs, like fish and house guests, go") "no"))
(assert (string= (has-problem "rotten after three days,\" said Zach Brock, an engineering") "no"))
(assert (string= (has-problem "manager.  Working out problems with a pairing partner can be") "yes"))
(assert (string= (has-problem "a lot like working out problems with a significant other.") "yes"))
(assert (string= (has-problem "During one recent rough patch, Jamie Kite, a developer, sat") "no"))
(assert (string= (has-problem "her partner down for a talk. \"Hey, it feels like we're") "no"))
(assert (string= (has-problem "driving in different directions,\" she recalls saying. \"It's") "no"))
(assert (string= (has-problem "like any relationship,\" Ms.  Kite said. \"If you don't talk") "no"))
(assert (string= (has-problem "about the problems, it's not going to work.\" When those") "yes"))
(assert (string= (has-problem "timeouts don't solve the problem, partners can turn to") "yes"))
(assert (string= (has-problem "on-staff coaches who can help with counseling.  \"People who") "no"))
(assert (string= (has-problem "have been pairing a while, they'll start acting like old") "no"))
(assert (string= (has-problem "married couples,\" said Marc Phillips, one of the coaches.") "no"))
(assert (string= (has-problem "People can be as much of a challenge as writing software.") "no"))
(assert (string= (has-problem "(Excerpted from \"Computer Programmers Learn Tough Lesson in") "no"))
(assert (string= (has-problem "Sharing\"; Wall Street Journal, August 27, 2012)") "no"))
