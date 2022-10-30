#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

samples = np.fromfile('bpsk_in_noise.iq', np.complex64)

plt.plot(np.real(samples), np.imag(samples), '.')
plt.grid(True)
plt.show()
