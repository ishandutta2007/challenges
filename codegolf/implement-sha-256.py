#!/usr/bin/env python

"""

Given a sequence of bytes, output the SHA-256 hash value of the sequence.

The SHA-256 Algorithm
The following pseudocode is taken from the Wikipedia page for SHA-2.

Note 1: All variables are 32 bit unsigned integers and addition is calculated modulo 2^32
Note 2: For each round, there is one round constant k[i] and one entry in the message schedule array w[i], 0 ≤ i ≤ 63
Note 3: The compression function uses 8 working variables, a through h
Note 4: Big-endian convention is used when expressing the constants in this pseudocode,
    and when parsing message block data from bytes to words, for example,
    the first word of the input message "abc" after padding is 0x61626380

Initialize hash values:
(first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19):
h0 := 0x6a09e667
h1 := 0xbb67ae85
h2 := 0x3c6ef372
h3 := 0xa54ff53a
h4 := 0x510e527f
h5 := 0x9b05688c
h6 := 0x1f83d9ab
h7 := 0x5be0cd19

Initialize array of round constants:
(first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311):
k[0..63] :=
   0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2

Pre-processing:
append the bit '1' to the message
append k bits '0', where k is the minimum number >= 0 such that the resulting message
    length (modulo 512 in bits) is 448.
append length of message (without the '1' bit or padding), in bits, as 64-bit big-endian integer
    (this will make the entire post-processed length a multiple of 512 bits)

Process the message in successive 512-bit chunks:
break message into 512-bit chunks
for each chunk
    create a 64-entry message schedule array w[0..63] of 32-bit words
    (The initial values in w[0..63] don't matter, so many implementations zero them here)
    copy chunk into first 16 words w[0..15] of the message schedule array

    Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
    for i from 16 to 63
        s0 := (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3)
        s1 := (w[i-2] rightrotate 17) xor (w[i-2] rightrotate 19) xor (w[i-2] rightshift 10)
        w[i] := w[i-16] + s0 + w[i-7] + s1

    Initialize working variables to current hash value:
    a := h0
    b := h1
    c := h2
    d := h3
    e := h4
    f := h5
    g := h6
    h := h7

    Compression function main loop:
    for i from 0 to 63
        S1 := (e rightrotate 6) xor (e rightrotate 11) xor (e rightrotate 25)
        ch := (e and f) xor ((not e) and g)
        temp1 := h + S1 + ch + k[i] + w[i]
        S0 := (a rightrotate 2) xor (a rightrotate 13) xor (a rightrotate 22)
        maj := (a and b) xor (a and c) xor (b and c)
        temp2 := S0 + maj

        h := g
        g := f
        f := e
        e := d + temp1
        d := c
        c := b
        b := a
        a := temp1 + temp2

    Add the compressed chunk to the current hash value:
    h0 := h0 + a
    h1 := h1 + b
    h2 := h2 + c
    h3 := h3 + d
    h4 := h4 + e
    h5 := h5 + f
    h6 := h6 + g
    h7 := h7 + h

Produce the final hash value (big-endian):
digest := hash := h0 append h1 append h2 append h3 append h4 append h5 append h6 append h7
Reference implementation
Here is a reference implementation, in Python 3:

#!/usr/bin/env python3

import sys

# ror function modified from http://stackoverflow.com/a/27229191/2508324
def ror(val, r_bits):
   return (val >> r_bits) | (val << (32-r_bits)) % 2**32

h = [0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19]

k = [0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2]

s = sys.stdin.read().encode()
msg = [int(x,2) for c in s for x in '{:08b}'.format(c)]
msg.append(1)
while len(msg) % 512 != 448:
    msg.append(0)
msg.extend([int(x,2) for x in '{:064b}'.format(len(s) * 8)])

for i in range(len(msg)//512):
    chunk = msg[512*i:512*(i+1)] # sloth love chunk
    w = [0 for _ in range(64)]
    for j in range(16):
        w[j] = int(''.join(str(x) for x in chunk[32*j:32*(j+1)]),2)
    for j in range(16, 64):
        s0 = ror(w[j-15], 7) ^ ror(w[j-15], 18) ^ (w[j-15] >> 3)
        s1 = ror(w[j-2], 17) ^ ror(w[j-2], 19) ^ (w[j-2] >> 10)
        w[j] = (w[j-16] + s0 + w[j-7] + s1) % 2**32
    work = h[:]
    for j in range(64):
        S1 = ror(work[4], 6) ^ ror(work[4], 11) ^ ror(work[4], 25)
        ch = (work[4] & work[5]) ^ (~work[4] & work[6])
        temp1 = (work[7] + S1 + ch + k[j] + w[j]) % 2**32
        S0 = ror(work[0], 2) ^ ror(work[0], 13) ^ ror(work[0], 22)
        maj = (work[0] & work[1]) ^ (work[0] & work[2]) ^ (work[1] & work[2])
        temp2 = (S0 + maj) % 2**32
        work = [(temp1 + temp2) % 2**32] + work[:-1]
        work[4] = (work[4] + temp1) % 2**32
    h = [(H+W)%2**32 for H,W in zip(h,work)]

print(''.join('{:08x}'.format(H) for H in h))
Restrictions
The usage of builtins which compute SHA-256 hashes or otherwise trivialize the challenge is forbidden
The input and output may be in any reasonable format (encoded in a single-byte encoding, base64, hexadecimal, etc.)
Test cases
<empty string> -> e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
abc -> ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
Hello, World! -> c98c24b677eff44860afea6f493bbaec5bb1c4cbb209c6fc2bbb47f66ff2ad31
1234 -> 03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4

"""

import hashlib

def sha256sum(s):
    h = hashlib.sha256()
    h.update(s)
    return h.hexdigest()

def main():
    assert(sha256sum(b"") == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855")
    assert(sha256sum(b"abc") == "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad")
    assert(sha256sum(b"Hello, World!\n") == "c98c24b677eff44860afea6f493bbaec5bb1c4cbb209c6fc2bbb47f66ff2ad31")
    assert(sha256sum(b"1234") == "03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4")

main()
