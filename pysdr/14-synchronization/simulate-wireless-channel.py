#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt
from scipy import signal
import math
import sys

# convert the stream of bits into +-1 pulses and pad it with 0s up to some length
# each bit will take up 8 symbol period by default
def modulate(bits, sps=8):
    pulses = np.array([])
    sps = 8
    for b in bits:
        p = np.zeros(sps)
        p[0] = 2*b - 1
        pulses = np.concatenate((pulses, p))
    return pulses

def rcosf(t, beta, Ts):
    return np.sinc(t/Ts) * np.cos(np.pi*beta*t/Ts) / (1 - (2*beta*t/Ts)**2)

def fractdelayf(delay, ntaps):
    # [-N/2 ... N/2] tap slots
    n = np.arange(-ntaps//2, ntaps//2)

    # generate the tap coefficients
    h = np.sinc(n - delay)

    # window the filter so it will decay to 0 on both sides
    h *= np.hamming(ntaps)
    
    # normalize to get unity gain so it doesn't change amplitude/power
    h /= np.sum(h)

    return h

def freqshift(n, fs, fo):
    Ts = 1/fs
    t = np.arange(0, Ts*n, Ts)
    return np.exp(1j*2*np.pi*fo*t)

def main():
    # generate a stream of bits to send
    nsym = 100
    bits = np.random.randint(0, 2, nsym)

    # modulate the signal to send
    pulses = modulate(bits)
    plt.plot(pulses, '.-')
    
    # use a raised cosine filter to shape the pulses
    # sampling rate is 1 hz, so the sample period is 1, the symbol period is 8
    ntaps = nsym + ((nsym & 1) ^ 1)
    beta = 0.35
    Ts = 8
    t = np.arange(-ntaps//2, ntaps//2 + 1)
    h = rcosf(t, beta, Ts)
    
    samples = np.convolve(pulses, h)
    plt.plot(samples, '.-')

    # if we just shift the indices around, it will delay for an integer period
    # to get a fractional delay use a filter 
    # apply a fractional delay filter (all pass filter that shift phase for all the frequencies)
    h = fractdelayf(0.4, 21)
    samples = np.convolve(samples, h)
    plt.plot(samples, '.-')

    # perform a frequency shift, this amounts to multiplying the signal by exp(2*pi*i*frequency_offset)
    # this adds a imaginary component to the real signal
    fo = freqshift(len(samples), 1e6, 13000)
    samples = samples * fo
    plt.plot(np.real(samples), '.-')
    plt.plot(np.imag(samples), '.-')
    
    plt.grid()
    plt.show()

main()
