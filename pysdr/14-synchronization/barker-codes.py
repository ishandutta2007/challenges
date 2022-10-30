import numpy as np
import matplotlib.pyplot as plt

"""

https://www.radartutorial.eu/08.transmitters/Barker%20Code.en.html

Barker codes are a sequence of [-1, 1] of some length that has the property of minimizing autocorrelation with itself in the sidelobes while maximizing it at the center (the value equal to the length itself)
Useful for autocorrelation (apply correlation sequence to itself) to detect preambles in frame synchronization.

A small set of sequences satisfies this property, a brute force search for these codes only found a handful so far,
so to use them for long sequences, segment the pulses into subpulses where they can be applied,
this is known as the kronecker product of two barker codes.

"""
def barker_code(n):
    tab = {
        2: "+-",
        3: "++-",
        4: "++-+",
        5: "+++-+",
        7: "+++--+-",
        11: "+++---+--+-",
        13: "+++++--++-+-+",
    }

    l = []
    for c in tab[n]:
        if c == '+':
            l.append(1)
        else:
            l.append(-1)
    return l

def plot_barker_codes():
    for i in [2, 3, 4, 5, 7, 11, 13]:
        x = barker_code(i)
        y = np.correlate(x, x, 'same')

        print(i)
        print(x)
        print(y)
        print()

        plt.plot(y, '.-', label='n={}'.format(i))
    plt.legend()
    plt.grid()
    plt.show()

def main():
    plot_barker_codes()

main()
