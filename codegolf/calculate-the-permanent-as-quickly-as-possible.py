#!/usr/bin/env python

"""

The challenge is to write the fastest code possible for computing the permanent of a matrix.

The permanent of an n-by-n matrix A = (ai,j) is defined as

enter image description here

Here S_n represents the set of all permutations of [1, n].

As an example (from the wiki):

enter image description here

In this question matrices are all square and will only have the values -1 and 1 in them.

Examples

Input:

[[ 1 -1 -1  1]
 [-1 -1 -1  1]
 [-1  1 -1  1]
 [ 1 -1 -1  1]]

Permanent:

-4

Input:

[[-1 -1 -1 -1]
 [-1  1 -1 -1]
 [ 1 -1 -1 -1]
 [ 1 -1  1 -1]]

Permanent:

0

Input:

[[ 1 -1  1 -1 -1 -1 -1 -1]
 [-1 -1  1  1 -1  1  1 -1]
 [ 1 -1 -1 -1 -1  1  1  1]
 [-1 -1 -1  1 -1  1  1  1]
 [ 1 -1 -1  1  1  1  1 -1]
 [-1  1 -1  1 -1  1  1 -1]
 [ 1 -1  1 -1  1 -1  1 -1]
 [-1 -1  1 -1  1  1  1  1]]

Permanent:

192

Input:

[[1, -1, 1, -1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1],
 [1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, 1, -1],
 [-1, -1, 1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, -1],
 [-1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1],
 [-1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1],
 [1, -1, 1, 1, -1, -1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1],
 [1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1],
 [1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1],
 [1, -1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1],
 [-1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1],
 [-1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1],
 [1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1],
 [-1, 1, 1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, 1, -1, 1],
 [1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1],
 [1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1],
 [1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1],
 [-1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1],
 [1, 1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1],
 [1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1],
 [-1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, -1]]

Permanent:

1021509632

The task

You should write code that, given an n by n matrix, outputs its permanent.

As I will need to test your code it would be helpful if you could give a simple way for me to give a matrix as input to your code, for example by reading from standard in.

Be warned that the permanent can be large (the all 1s matrix is the extreme case).

Scores and ties

I will test your code on random +-1 matrices of increasing size and stop the first time your code takes more than 1 minute on my computer. The scoring matrices will be consistent for all submissions in order to ensure fairness.

If two people get the same score then the winner is the one which is fastest for that value of n. If those are within 1 second of each other then it is the one posted first.

Languages and libraries

You can use any available language and libraries you like but no pre-existing function to compute the permanent. Where feasible, it would be good to be able to run your code so please include a full explanation for how to run/compile your code in Linux if at all possible.`

Reference implementations

There is already a codegolf question question with lots of code in different languages for computing the permanent for small matrices. Mathematica and Maple also both have permanent implementations if you can access those.

My Machine The timings will be run on my 64-bit machine. This is a standard ubuntu install with 8GB RAM, AMD FX-8350 Eight-Core Processor and Radeon HD 4250. This also means I need to be able to run your code.

Low level information about my machine

cat /proc/cpuinfo/|grep flags gives

    flags : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx mmxext fxsr_opt pdpe1gb rdtscp lm constant_tsc rep_good nopl nonstop_tsc extd_apicid aperfmperf pni pclmulqdq monitor ssse3 fma cx16 sse4_1 sse4_2 popcnt aes xsave avx f16c lahf_lm cmp_legacy svm extapic cr8_legacy abm sse4a misalignsse 3dnowprefetch osvw ibs xop skinit wdt lwp fma4 tce nodeid_msr tbm topoext perfctr_core perfctr_nb cpb hw_pstate vmmcall bmi1 arat npt lbrv svm_lock nrip_save tsc_scale vmcb_clean flushbyasid decodeassists pausefilter pfthreshold

I will ask a closely related follow up multi-language question that doesn't suffer from the big Int problem so lovers of Scala, Nim, Julia, Rust, Bash can show off their languages too.

Leader board

    n = 33 (45 seconds. 64 seconds for n = 34). Ton Hospel in C++ with g++ 5.4.0.
    n = 32 (32 seconds). Dennis in C with gcc 5.4.0 using Ton Hospel's gcc flags.
    n = 31 (54 seconds). Christian Sievers in Haskell
    n = 31 (60 seconds). primo in rpython
    n = 30 (26 seconds). ezrast in Rust
    n = 28 (49 seconds). xnor with Python + pypy 5.4.1
    n = 22 (25 seconds). Shebang with Python + pypy 5.4.1

Note. In practice the timings for Dennis and Ton Hospel's vary a lot for mysterious reasons. For example they seem to be faster after I have loaded a web browser! The timings quoted are the fastest in all the tests I have done.

"""

import numpy as np

# https://github.com/scipy/scipy/issues/7151
# https://en.wikipedia.org/wiki/Computing_the_permanent#Balasubramanian-Bax-Franklin-Glynn_formula
def permanent(m):
    M = np.array(m)
    n = M.shape[0]
    d = np.ones(n)
    j =  0
    s = 1
    f = np.arange(n)
    v = M.sum(axis=0)
    p = np.prod(v)
    while j < n-1:
        v = v - 2*d[j]*M[j]
        d[j] = -d[j]
        s = -s
        prod = np.prod(v)
        p += s*prod
        f[0] = 0
        f[j] = f[j+1]
        f[j+1] = j + 1
        j = f[0]
    
    return p / 2**(n-1)

def main():
    m1 = [[1, -1, -1, 1],
          [-1, -1, -1, 1],
          [-1,  1, -1, 1],
          [1, -1, -1, 1]]
    m2 = [[-1, -1, -1, -1],
          [-1, 1, -1, -1],
          [1, -1, -1, -1],
          [1, -1, 1, -1]]
    m3 = [[1, -1, 1, -1, -1, -1, -1, -1],
          [-1, -1, 1, 1, -1, 1, 1, -1],
          [1, -1, -1, -1, -1, 1, 1, 1],
          [-1, -1, -1, 1, -1, 1, 1, 1],
          [1, -1, -1, 1, 1, 1, 1, -1],
          [-1, 1, -1, 1, -1, 1, 1, -1],
          [1, -1, 1, -1, 1, -1, 1, -1],
          [-1, -1, 1, -1, 1, 1, 1, 1]]
    m4 = [[1, -1, 1, -1, -1, 1, 1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, 1, 1, -1],
          [1, -1, 1, 1, 1, 1, 1, -1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, 1, -1],
          [-1, -1, 1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, -1],
          [-1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1],
          [-1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, 1, 1, 1, 1],
          [1, -1, 1, 1, -1, -1, 1, -1, 1, 1, 1, 1, -1, 1, 1, -1, 1, -1, -1, -1],
          [1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1],
          [1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1],
          [1, -1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1],
          [-1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1],
          [-1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1],
          [1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1],
          [-1, 1, 1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, -1, -1, 1, -1, 1],
          [1, 1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1],
          [1, 1, 1, 1, 1, -1, -1, -1, 1, 1, 1, -1, 1, -1, 1, 1, 1, -1, 1, 1],
          [1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1],
          [-1, 1, 1, 1, -1, 1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1],
          [1, 1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1],
          [1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1],
          [-1, 1, 1, 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, -1]]

    print(permanent(m1))
    print(permanent(m2))
    print(permanent(m3))
    print(permanent(m4))

main()
