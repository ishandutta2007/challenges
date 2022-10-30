/*

Introduction
You must create a function to convert Arabic numerals into Greek numerals. The input will be an integer less than 1000 and more than 0.

Algorithm
Split number into digits (e.g. 123 -> 1, 2, 3)
Take each digit, and change to character found in table below, for letter symbol or letter name, (e.g. 123 -> 1, 2, 3 -> ΡΚΓ or RhoKappaGamma).

Specifications
No built-in number-system conversion
Result must be capitalized as in example.
Input will be in base 10.

Test Cases
123 -> RhoKappaGamma or ΡΚΓ
8 -> Eta or Η
777 -> PsiOmicronZeta or ΨΟΖ
100 -> Rho or Ρ
606 -> ChiDiGamma or ΧϜ

Table
Α = 1 = Alpha = 913 UTF-8
Β = 2 = Beta = 914 UTF-8
Γ = 3 = Gamma = 915 UTF-8
Δ = 4 = Delta = 916 UTF-8
Ε = 5 = Epsilon = 917 UTF-8
Ϝ = 6 = DiGamma = 988 UTF-8
Ζ = 7 = Zeta = 918 UTF-8
Η = 8 = Eta = 919 UTF-8
Θ = 9 = Theta = 920 UTF-8

Ι = 10 = Iota = 921 UTF-8
Κ = 20 = Kappa = 922 UTF-8
Λ = 30 = Lambda = 923 UTF-8
Μ = 40 = Mu = 924 UTF-8
Ν = 50 = Nu = 925 UTF-8
Ξ = 60 = Xi = 926 UTF-8
Ο = 70 = Omicron = 927 UTF-8
Π = 80 = Pi = 928 UTF-8
Ϙ = 90 = Koppa = 984 UTF-8

Ρ = 100 = Rho = 929 UTF-8
Σ = 200 = Sigma = 931 UTF-8
Τ = 300 = Tau = 932 UTF-8
Υ = 400 = Upsilon = 933 UTF-8
Φ = 500 = Phi = 934 UTF-8
Χ = 600 = Chi = 935 UTF-8
Ψ = 700 = Psi = 936 UTF-8
Ω = 800 = Omega = 937 UTF-8
Ϡ = 900 = SamPi = 992 UTF-8

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	test(123, "ΡΚΓ")
	test(8, "Η")
	test(100, "Ρ")
	test(606, "ΧϜ")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r string) {
	p := conv(n)
	fmt.Println(p)
	assert(p == r)
}

func conv(n int) string {
	ones := []string{"", "Α", "Β", "Γ", "Δ", "E", "Ϝ", "Ζ", "Η", "Θ"}
	tens := []string{"", "I", "Κ", "Λ", "M", "N", "Ξ", "Ο", "Π", "Ϙ"}
	hundreds := []string{"", "Ρ", "Σ", "Τ", "Υ", "Φ", "Χ", "Ψ", "Ω", "Ϡ"}

	if !(0 < n && n < 1000) {
		return ""
	}

	w := new(bytes.Buffer)
	if n >= 100 {
		fmt.Fprintf(w, "%v", hundreds[(n/100)%10])
	}
	if n >= 10 {
		fmt.Fprintf(w, "%s", tens[(n/10)%10])
	}
	fmt.Fprintf(w, "%v", ones[n%10])

	return w.String()
}
