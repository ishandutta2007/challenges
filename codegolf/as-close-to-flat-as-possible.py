"""

Write a program or function that fulfills the following

Scores less than 101 bytes under normal code-golf rules

Takes no input [1] and always outputs a single integer.

Every integer is a possible output.

Your score will be the probability of the most frequent integer occurring, with a lower scoring being the goal. That is sup{P(x)|x∈Z}.

Since a few of these properties are not program decidable, you should be ready to provide a proof that your answer is valid and obtains the score it claims.

1 You may optionally take a stream of random bits, or a subroutine which produces random bits on each call as an input to provide randomness. Each bit will be uniform and independent of other bits.

"""

counter = 0

def value():
    global counter
    val = counter
    counter += 1
    return val

def main():
    while True:
        print(value())

main()
