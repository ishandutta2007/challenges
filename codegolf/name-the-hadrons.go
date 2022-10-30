/*

Challenge
Given a quark composition of a particle as input, output the corresponding hadron's name.

Quarks will be represented by a capital letter and antiquarks by a lowercase letter.

The quarks may be in any order, not necessarily the order given below.

Built-in functions the access data about particles and/or quarks are disallowed.

The only quarks you will be given are U (up), u (antiup), D (down), d (antidown), S (strange), s (antistrange), C (charm), c (anticharm), B (bottom or beauty), b(antibottom or antibeauty).

List of Hadrons and their quark compositions
Note that although there are various other hadrons such as pentaquarks and glueballs etc., you only need to support the hadrons given in the following lists

Baryons (QQQ) and Antibaryons (qqq)
The names in brackets are alternative names for the particles. You may output either name.

Input - Output

UUU - delta++
uuu - antidelta++
UUD - delta+ (proton)
uud - antidelta+ (antiproton)
UDD - delta0 (neutron)
udd - antidelta0 (antineutron)
DDD - delta-
ddd - antidelta-
UUS - sigma+
uus - antisigma+
UDS - sigma0
uds - antisigma0
DDS - sigma-
dds - antisigma-
USS - xi0
uss - antixi0
DSS - xi-
dss - antixi-
SSS - omega-
sss - antiomega-

UUC - charmed sigma++
uuc - charmed antisigma++
UDC - charmed sigma+
udc - charmed antisigma+
DDC - charmed sigma0
ddc - charmed antisigma0
UUB - bottom sigma+
uub - bottom antisigma+
UDB - bottom sigma0
udb - bottom antisigma0
DDB - bottom sigma-
ddb - bottom antisigma-
USC - charmed xi+
usc - charmed antixi+
DSC - charmed xi0
dsc - charmed antixi0
UCC - double charmed xi++
ucc - double charmed antixi++
DCC - double charmed xi+
dcc - double charmed antixi+
USB - bottom xi0
usb - bottom antixi0
DSB - bottom xi-
dsb - bottom antixi-
UBB - double bottom xi0
ubb - double bottom antixi0
DBB - double bottom xi-
dbb - double bottom antixi-
UCB - charmed bottom xi+
ucb - charmed bottom antixi+
DCB - charmed bottom xi0
dcb - charmed bottom antixi0
SSC - charmed omega0
ssc - charmed antiomega0
SSB - bottom omega-
ssb - bottom antiomega-
SCC - double charmed omega+
scc - double charmed antiomega+
SCB - charmed bottom omega0
scb - charmed bottom antiomega0
SBB - double bottom omega-
sbb - double bottom antiomega-
CCB - double charmed bottom omega+
ccb - double charmed bottom antiomega+
CBB - charmed double bottom omega0
cbb - charmed double bottom antiomega0
CCC - triple charmed omega++
ccc - triple charmed antiomega++
BBB - triple bottom omega-
bbb - triple bottom antiomega-

Mesons (Qq)
Input - Output

Ud - pion+
Uu - pion0
Dd - pion0
Du - pion-
Us - kaon+
Ds - kaon0
Sd - antikaon0
Su - kaon-
Ss - phion0
Cd - D meson+
Dc - D meson-
Cu - D meson0
Uc - antiD meson0
Cs - strange D meson+
Sc - strange D meson-
Cc - psion0
Bu - B meson-
Ub - B meson+
Db - B meson0
Bd - antiB meson0
Sb - strange B meson0
Bs - strange antiB meson0
Bb - upsilon0

*/

package main

import "fmt"

func main() {
	fmt.Println(hadron("UUU"))
	fmt.Println(hadron("sss"))
}

func hadron(s string) string {
	m := map[string]string{
		// Baryons and Anti-Baryons
		"UUU": "delta++",
		"uuu": "antidelta++",
		"UUD": "delta+ (proton)",
		"uud": "antidelta+ (antiproton)",
		"UDD": "delta0 (neutron)",
		"udd": "antidelta0 (antineutron)",
		"DDD": "delta-",
		"ddd": "antidelta-",
		"UUS": "sigma+",
		"uus": "antisigma+",
		"UDS": "sigma0",
		"uds": "antisigma0",
		"DDS": "sigma-",
		"dds": "antisigma-",
		"USS": "xi0",
		"uss": "antixi0",
		"DSS": "xi-",
		"dss": "antixi-",
		"SSS": "omega-",
		"sss": "antiomega-",

		"UUC": "charmed sigma++",
		"uuc": "charmed antisigma++",
		"UDC": "charmed sigma+",
		"udc": "charmed antisigma+",
		"DDC": "charmed sigma0",
		"ddc": "charmed antisigma0",
		"UUB": "bottom sigma+",
		"uub": "bottom antisigma+",
		"UDB": "bottom sigma0",
		"udb": "bottom antisigma0",
		"DDB": "bottom sigma-",
		"ddb": "bottom antisigma-",
		"USC": "charmed xi+",
		"usc": "charmed antixi+",
		"DSC": "charmed xi0",
		"dsc": "charmed antixi0",
		"UCC": "double charmed xi++",
		"ucc": "double charmed antixi++",
		"DCC": "double charmed xi+",
		"dcc": "double charmed antixi+",
		"USB": "bottom xi0",
		"usb": "bottom antixi0",
		"DSB": "bottom xi-",
		"dsb": "bottom antixi-",
		"UBB": "double bottom xi0",
		"ubb": "double bottom antixi0",
		"DBB": "double bottom xi-",
		"dbb": "double bottom antixi-",
		"UCB": "charmed bottom xi+",
		"ucb": "charmed bottom antixi+",
		"DCB": "charmed bottom xi0",
		"dcb": "charmed bottom antixi0",
		"SSC": "charmed omega0",
		"ssc": "charmed antiomega0",
		"SSB": "bottom omega-",
		"ssb": "bottom antiomega-",
		"SCC": "double charmed omega+",
		"scc": "double charmed antiomega+",
		"SCB": "charmed bottom omega0",
		"scb": "charmed bottom antiomega0",
		"SBB": "double bottom omega-",
		"sbb": "double bottom antiomega-",
		"CCB": "double charmed bottom omega+",
		"ccb": "double charmed bottom antiomega+",
		"CBB": "charmed double bottom omega0",
		"cbb": "charmed double bottom antiomega0",
		"CCC": "triple charmed omega++",
		"ccc": "triple charmed antiomega++",
		"BBB": "triple bottom omega-",
		"bbb": "triple bottom antiomega-",

		// Mesons
		"Ud": "pion+",
		"Uu": "pion0",
		"Dd": "pion0",
		"Du": "pion-",
		"Us": "kaon+",
		"Ds": "kaon0",
		"Sd": "antikaon0",
		"Su": "kaon-",
		"Ss": "phion0",
		"Cd": "D meson+",
		"Dc": "D meson-",
		"Cu": "D meson0",
		"Uc": "antiD meson0",
		"Cs": "strange D meson+",
		"Sc": "strange D meson-",
		"Cc": "psion0",
		"Bu": "B meson-",
		"Ub": "B meson+",
		"Db": "B meson0",
		"Bd": "antiB meson0",
		"Sb": "strange B meson0",
		"Bs": "strange antiB meson0",
		"Bb": "upsilon0",
	}
	return m[s]
}
