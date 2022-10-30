import numpy as np

# generate some complex gaussian noise with some mean and standard deviation
def sim(n, mu, sd):
    x = (np.random.randn(n) + 1j*np.random.randn(n))*sd + mu
    mu_s = abs(np.mean(x))
    
    # the samples above were both multiplied with standard deviation in real and imaginary components
    # so the standard deviation have to be scaled by sqrt(2) here to match
    sd_s = np.std(x)/np.sqrt(2)

    # the noise power squared of a signal closely matches the variance:
    # noise power squared  | sum[x]**2 / N
    # variance             | sum[x-mean]**2 / N
    # if the mean is zero, then power squared matches variance
    # if we want unity power gain (noise power = 1) then we need to divide by the signal by the sqrt(raw variance)
    # when the mean is 0 and standard deviation is 1, the sqrt(raw variance) is sqrt(2)
    var = np.var(x-mu) / 2
    unity_power_1 = np.var((x+mu) / np.sqrt(np.var(x)))
    unity_power_2 = np.var(x / np.sqrt(np.var(x)))

    # these should match
    print("mean:          {} simulated {}".format(mu, mu_s))
    print("stddev:        {} simulated {}".format(sd, sd_s))
    print("variance:      {} simulated {}".format(var, sd_s**2))
    print("raw variance:  {}".format(np.var(x)))
    print("unity power:   {} {}".format(unity_power_1, unity_power_2))
    print()

def main():
    sim(100000, 50, 5)
    sim(100000, 0, 1)
    sim(1000000, 596, 2356)
    sim(1000, 59, 5)

main()
