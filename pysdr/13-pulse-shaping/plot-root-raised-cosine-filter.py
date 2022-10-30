from commpy.filters import *
from scipy.signal import *
import matplotlib.pyplot as plt
import numpy as np

def plot_responses(Bs, n, Ts, Fs):
    fig, axs = plt.subplots(2, 2, figsize=(12, 8))
    for i in range(2):
        for B in Bs:
            if i == 0:
                t, x = rrcosfilter(n, B, Ts, Fs)
            else:
                t, x = rcosfilter(n, B, Ts, Fs)

            y = np.abs(np.fft.fftshift(np.fft.fft(x)) / len(x))

            axs[i, 0].plot(t, x, label='B={}'.format(B))
            axs[i, 0].set_xlim([np.min(t) - 1, np.max(t) + 1])
            axs[i, 0].set_ylim([np.min(x) - 1, np.max(x) + 1])
            axs[i, 0].grid(True)
            axs[i, 0].legend()

            axs[i, 1].plot(t, y, label='B={}'.format(B))
            axs[i, 1].set_xlim([np.min(t), np.max(t)])
            axs[i, 1].set_ylim([np.min(y) * 1.25, np.max(y) * 1.25])
            axs[i, 1].grid(True)
            axs[i, 1].legend()

        i += 1

    axs[0, 0].set_title('Root Raised Cosine Filter Impulse Response')
    axs[1, 0].set_title('Raised Cosine Filter Impulse Response')
    axs[0, 1].set_title('Root Raised Cosine Filter Frequency Response')
    axs[1, 1].set_title('Raised Cosine Filter Frequency Response')
    plt.show()

def main():
    plot_responses([0, 0.25, 0.5, 1], 150, 1, 10)

main()
