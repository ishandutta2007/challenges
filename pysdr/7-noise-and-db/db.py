import numpy as np

def val2db(x):
    return 10 * np.log10(x)

def db2val(x_db):
    return 10.0 ** (x_db / 10.0)

"""

Common dB errors

1) Using natural log instead of log base 10 because most programming language’s log() function is actually the natural log.
2) Forgetting to include the dB when expressing a number or labeling an axis. If we are in dB we need to identify it somewhere.
3) When you’re in dB you add/subtract values instead of multiplying/dividing, e.g.:

    Input -> Amp1 -> Amp2 -> Amp3 -> Output
        2      *   13       *    5    = 130x amplification
        3 dB   +   11.1dB   +    7 dB = 21.1 dB combined

"""

def main():
    # everytime there is a 10x increase/decrease, add/sub by 10 in db
    print(val2db(np.array([1e-3, 1e-2, 1e-1, 1e0, 1e1, 1e2, 1e3])))
    
    # everytime magnitude gets squared, double the original magnitude
    print(val2db(np.array([10, 10**2, 10**4, 10**8, 10**16])))
    
    # example above
    print(val2db(np.array([2, 13, 5])))
    print(db2val(val2db(2) + val2db(13) + val2db(5)))

    # common dbs to remember
    print(val2db(np.array([1, 2, 10, 0.5, 0.1, 100, 1000, 10000])))

main()
