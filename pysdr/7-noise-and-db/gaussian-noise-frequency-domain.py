import numpy as np
import matplotlib.pyplot as plt

"""

Gaussian noise under a fourier transform is still a gaussian noise in the frequency domain.
This means in the frequency domain, all frequencies will have near the same strength plus some noise.

"""

# sample values from a gaussian distribution
N = 4096
x = np.random.randn(N)

# take the fourier transform and only keep the positive frequencies
X = np.fft.fftshift(np.fft.fft(x))
X = X[N//2:]

# the time and frequency plot should look the same due to the gaussian noise property
# if we want a flat plot in the frequency domain, take the log (turn it to db) and average them
plt.subplot(1, 2, 1)
plt.plot(x, '.-')
plt.subplot(1, 2, 2)
plt.plot(np.real(X), '.-')
plt.show()

