/*

Introduction
You must create a function to convert Greek numerals into Arabic numerals. The input will be a Greek numeral less than 1000 and more than 0. This is the reverse of my previous challenge.

Algorithm
Split input into letters (e.g. ΡΚΓ -> Ρ, Κ, Γ)
Take each letter, and change to character found in table below, for letter symbol, (e.g. ΡΚΓ -> Ρ, Κ, Γ -> 100, 20, 3).
Add (e.g. ΡΚΓ -> Ρ, Κ, Γ -> 100, 20, 3 -> 123)

Specifications
No built-in number-system conversion
Input will be capitalized as in example.
Output must be in base 10.
ΡΡΡΡ will never happen. It will be Υ.

Test Cases
ΡΚΓ -> 123
Η -> 8
ΨΟΖ -> 777
Ρ -> 100
ΧϜ -> 606
ΡϘ -> 190
ΜΒ -> 42
Ν -> 50

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

func main() {
	assert(number("ΡΚΓ") == 123)
	assert(number("Η") == 8)
	assert(number("ΨΟΖ") == 777)
	assert(number("Ρ") == 100)
	assert(number("ΧϜ") == 606)
	assert(number("ΡϘ") == 190)
	assert(number("ΜΒ") == 42)
	assert(number("Ν") == 50)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func number(s string) int {
	m := map[rune]int{
		'Α': 1,
		'Β': 2,
		'Γ': 3,
		'Δ': 4,
		'Ε': 5,
		'Ϝ': 6,
		'Ζ': 7,
		'Η': 8,
		'Θ': 9,

		'I': 10,
		'Κ': 20,
		'Λ': 30,
		'Μ': 40,
		'Ν': 50,
		'Ξ': 60,
		'Ο': 70,
		'Π': 80,
		'Ϙ': 90,

		'Ρ': 100,
		'Σ': 200,
		'Τ': 300,
		'Υ': 400,
		'Φ': 500,
		'Χ': 600,
		'Ψ': 700,
		'Ω': 800,
		'Ϡ': 900,
	}

	v := 0
	for _, r := range s {
		v += m[r]
	}
	return v
}
