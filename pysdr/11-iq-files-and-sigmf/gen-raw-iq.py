#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

# random bpsk signal
def gen_symbols(n, ns):
    # +-1 signal
    x = np.random.randint(0, 2, n)*2 - 1
    
    # generate awgn with unity power
    y = (np.random.randn(n) + 1j*np.random.randn(n)) / np.sqrt(2)

    # add noise to the signal with the strength of the passed noise power parameter
    r = x + y*np.sqrt(ns)

    return r.astype(np.complex64)

def main():
    fn = "bpsk_in_noise.iq"
    nsym = 10000
    ns = 1e-2

    r = gen_symbols(nsym, ns)
    r.tofile(fn)

    s = np.fromfile(fn, np.complex64)
    for i in range(len(r)):
        assert(np.equal(r[i], s[i]))

main()
