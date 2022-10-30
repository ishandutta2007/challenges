from commpy.filters import *
import numpy as np

def raised_cosine(t, B, T, normalize):
    s = 1/T
    if not normalize:
        s = 1
    a = np.sinc(t/T)
    b = np.cos(np.pi*B*t/T)
    c = 1 - (2*B*t/T)**2
    if c == 0:
        return np.pi/(4*T) * np.sinc(1/(2*B))
    return s*a*(b/c)

def raised_root_cosine(t, B, T, normalize):
    if t == 0:
        s = 1/T
        a = 1
        b = B*(4/np.pi - 1)
        v = a + b
    elif abs(t) == T/(4*B):
        s = B/(T*np.sqrt(2))
        a = (1 + 2/np.pi) * np.sin(np.pi / (4*B))
        b = (1 - 2/np.pi) * np.cos(np.pi / (4*B))
        v = a + b
    else:
        s = 1/T
        a = np.sin(np.pi*t/T*(1-B))
        b = 4*B*t/T * np.cos(np.pi*t/T*(1 + B))
        c = np.pi*t/T * (1 - (4*B*t/T)**2)
        v = (a + b) / c

    if not normalize:
        s = 1
    return s*v

def test_equality(f, g, n, B, Ts, Fs):
    t, x = f(n, B, Ts, Fs)
    mi, ma = 1e6, -1e6
    for i in range(len(t)):
        # the commpy library does not normalize so the scale factor is 1 instead of the standard equation found in books,
        # so if we want to match for period Ts != 1, we have to make the scale factor equal to 1
        normalize = True
        if Ts != 1:
            normalize = False
        y = g(t[i], B, Ts, normalize)
        
        z = g(t[i], B, Ts, True)
        mi = min(mi, z)
        ma = max(ma, z)

        assert(abs(x[i] - y) < 1e-6)
    
    print("B={} Ts={} Fs={}".format(B, Ts, Fs))
    print("min [{:.3f}, {:.3f}] max [{:.3f} {:.3f}]".format(np.min(x), mi, np.max(x), ma))
    print()

def main():
    test_equality(rcosfilter, raised_cosine, 1000, 0.5, 1, 563) 
    test_equality(rcosfilter, raised_cosine, 103, 0.2, 1, 406) 
    test_equality(rcosfilter, raised_cosine, 103, 0.2, 45, 406) 
    test_equality(rcosfilter, raised_cosine, 10953, 0, 1, 4676) 

    test_equality(rrcosfilter, raised_root_cosine, 1000, 0.5, 1, 563) 
    test_equality(rrcosfilter, raised_root_cosine, 103, 0.2, 45, 406) 
    test_equality(rrcosfilter, raised_root_cosine, 10953, 0.4, 1, 4676) 

main()
