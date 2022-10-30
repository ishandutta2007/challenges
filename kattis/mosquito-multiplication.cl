; Have you ever wondered why there are so many mosquitoes in wet environments? One of the reasons is that adult female mosquitos can lay as many as hundreds of eggs.
; Even if most of them do not (fortunately!) survive, it is said that a single pair of mosquitoes can generate a population of thousands in just a couple of weeks. Let us have a closer look at these numbers.
;
; The mosquito life cycle includes four stages: egg, larva, pupa, and adult. For simplicity, we will make several assumptions that are not quite true in the nature: The egg stage lasts less than one day, and all the other stages are one week long.
; Each mosquito lives as a larva for the first week, the second week “hibernates” in the form of a pupa, and finally, the third week lives as an adult mosquito. At the end of its three-week life, each mosquito lays eggs and dies.
;
; To simplify things even further, we will assume that the transformation from one life stage into another always happens on Sunday. Each Sunday, the following things happen:
;
;    An adult mosquito lays E eggs and dies. Within a day, one larva hatches from each egg.
;
; Some of the larvae hatched from egg the last Sunday were not strong enough and died or got eaten. Only every R-th larva will transform into a pupa on Sunday.
;
; An adult mosquito emerges from every S-th pupa, all other pupae dry.
;
; For example, if there are 5 pupae and every 3-rd of them survives, there will be 1 mosquito left. Out of 6 pupae, two adult mosquitoes emerge.
;
; In the first week, there are M mosquitoes, P pupae and L larvae. Calculate how many mosquitoes will there be after N
;
; Sunday transformations. Of course, we are counting only living adult mosquitos, not the dry dead bodies.
;
; Input
;
; The input consists of several instances, each instance per one line.
; Each line contains seven integers M , P, L, E, R, S, N separated by space. M, P and L are the numbers of mosquitoes, pupae, and larvae, respectively, in the first week.
; You may assume that 0≤M,P,L≤100000, 0≤E≤100, 1≤R,S≤10, and 1≤N≤1000. E is the number of eggs laid by one mosquito, R and S specify the survival rates of larvae and pupae, and N is the number of weeks.
;
; Output
;
; For each input instance, output a single line containing an integer number C, giving the count of mosquitoes after the N-th Sunday.
;
; You may assume that the number of mosquitoes during each of the first N weeks will not exceed 1000000.

(defun multiply (M P L E R S N)
  (dotimes (number N)
	(setq Q P)
	(setq P (floor L R))
	(setq L (* E M))
	(setq M (floor Q S)))
  M)

(assert (= (multiply 10 20 40 4 2 2 10) 10))
(assert (= (multiply 144 55 8 0 1 9 4) 0))
(assert (= (multiply 10 10 10 2 3 2 6) 1))
(assert (= (multiply 10 20 40 86 9 9 999) 10))
