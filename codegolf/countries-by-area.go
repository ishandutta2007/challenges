/*

Challenge

Given two non negative integers a < b, output all countries, from the below Top 100 Countries, where area is between a and b: a<= area <= b.
Example

147500,180000   --> uruguay, suriname, tunisia, bangladesh
1200000,1300000 --> peru, chad, niger, angola, mali, south africa
1234567,1256789 --> angola, mali

Top 100 Countries by Area (2017):

russia..........................17098250
canada...........................9984670
united states....................9831510
china............................9562911
brazil...........................8515770
australia........................7741220
india............................3287259
argentina........................2780400
kazakhstan.......................2724902
congo............................2686860
algeria..........................2381740
saudi arabia.....................2149690
mexico...........................1964380
indonesia........................1910931
sudan............................1879358
libya............................1759540
iran.............................1745150
mongolia.........................1564120
peru.............................1285220
chad.............................1284000
niger............................1267000
angola...........................1246700
mali.............................1240190
south africa.....................1219090
colombia.........................1141749
ethiopia.........................1104300
bolivia..........................1098580
mauritania.......................1030700
egypt............................1001450
tanzania..........................947300
nigeria...........................923770
venezuela.........................912050
namibia...........................824290
mozambique........................799380
pakistan..........................796100
turkey............................785350
chile.............................756096
zambia............................752610
myanmar...........................676590
afghanistan.......................652860
south sudan.......................644330
somalia...........................637660
central african republic..........622980
ukraine...........................603550
madagascar........................587295
botswana..........................581730
kenya.............................580370
france............................549087
yemen.............................527970
thailand..........................513120
spain.............................505940
turkmenistan......................488100
cameroon..........................475440
papua new guinea..................462840
sweden............................447420
uzbekistan........................447400
morocco...........................446550
iraq..............................435050
greenland.........................410450
paraguay..........................406752
zimbabwe..........................390760
norway............................385178
japan.............................377962
germany...........................357380
finland...........................338420
vietnam...........................330967
malaysia..........................330800
cote d'ivoire.....................322460
poland............................312680
oman..............................309500
italy.............................301340
philippines.......................300000
burkina faso......................274220
new zealand.......................267710
gabon.............................267670
ecuador...........................256370
guinea............................245860
united kingdom....................243610
uganda............................241550
ghana.............................238540
romania...........................238390
laos..............................236800
guyana............................214970
belarus...........................207600
kyrgyz............................199949
senegal...........................196710
syria.............................185180
cambodia..........................181040
uruguay...........................176220
suriname..........................163820
tunisia...........................163610
bangladesh........................147630
nepal.............................147180
tajikistan........................141376
greece............................131960
nicaragua.........................130370
north korea.......................120540
malawi............................118480
eritrea...........................117600
benin.............................114760

Names as separate list

russia
canada
united states
china
brazil
australia
india
argentina
kazakhstan
congo
algeria
saudi arabia
mexico
indonesia
sudan
libya
iran
mongolia
peru
chad
niger
angola
mali
south africa
colombia
ethiopia
bolivia
mauritania
egypt
tanzania
nigeria
venezuela
namibia
mozambique
pakistan
turkey
chile
zambia
myanmar
afghanistan
south sudan
somalia
central african republic
ukraine
madagascar
botswana
kenya
france
yemen
thailand
spain
turkmenistan
cameroon
papua new guinea
sweden
uzbekistan
morocco
iraq
greenland
paraguay
zimbabwe
norway
japan
germany
finland
vietnam
malaysia
cote d'ivoire
poland
oman
italy
philippines
burkina faso
new zealand
gabon
ecuador
guinea
united kingdom
uganda
ghana
romania
laos
guyana
belarus
kyrgyz
senegal
syria
cambodia
uruguay
suriname
tunisia
bangladesh
nepal
tajikistan
greece
nicaragua
north korea
malawi
eritrea
benin

Areas as separate lists

17098250
9984670
9831510
9562911
8515770
7741220
3287259
2780400
2724902
2686860
2381740
2149690
1964380
1910931
1879358
1759540
1745150
1564120
1285220
1284000
1267000
1246700
1240190
1219090
1141749
1104300
1098580
1030700
1001450
947300
923770
912050
824290
799380
796100
785350
756096
752610
676590
652860
644330
637660
622980
603550
587295
581730
580370
549087
527970
513120
505940
488100
475440
462840
447420
447400
446550
435050
410450
406752
390760
385178
377962
357380
338420
330967
330800
322460
312680
309500
301340
300000
274220
267710
267670
256370
245860
243610
241550
238540
238390
236800
214970
207600
199949
196710
185180
181040
176220
163820
163610
147630
147180
141376
131960
130370
120540
118480
117600
114760

Rules

    The input and output can be given in any convenient format.
    The output can be in any case.
    No need to handle invalid input values.
    Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
    If possible, please include a link to an on-line testing environment so other people can try out your code!
    Standard loopholes are forbidden.
    The code is not allowed to import the list from file or internet.
    This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(countries(147500, 180000))
	fmt.Println(countries(1200000, 1300000))
	fmt.Println(countries(1234567, 1256789))
}

func countries(a, b int) []string {
	tab := []struct {
		name string
		area int
	}{
		{"russia", 17098250},
		{"canada", 9984670},
		{"united states", 9831510},
		{"china", 9562911},
		{"brazil", 8515770},
		{"australia", 7741220},
		{"india", 3287259},
		{"argentina", 2780400},
		{"kazakhstan", 2724902},
		{"congo", 2686860},
		{"algeria", 2381740},
		{"saudi arabia", 2149690},
		{"mexico", 1964380},
		{"indonesia", 1910931},
		{"sudan", 1879358},
		{"libya", 1759540},
		{"iran", 1745150},
		{"mongolia", 1564120},
		{"peru", 1285220},
		{"chad", 1284000},
		{"niger", 1267000},
		{"angola", 1246700},
		{"mali", 1240190},
		{"south africa", 1219090},
		{"colombia", 1141749},
		{"ethiopia", 1104300},
		{"bolivia", 1098580},
		{"mauritania", 1030700},
		{"egypt", 1001450},
		{"tanzania", 947300},
		{"nigeria", 923770},
		{"venezuela", 912050},
		{"namibia", 824290},
		{"mozambique", 799380},
		{"pakistan", 796100},
		{"turkey", 785350},
		{"chile", 756096},
		{"zambia", 752610},
		{"myanmar", 676590},
		{"afghanistan", 652860},
		{"south sudan", 644330},
		{"somalia", 637660},
		{"central african republic", 622980},
		{"ukraine", 603550},
		{"madagascar", 587295},
		{"botswana", 581730},
		{"kenya", 580370},
		{"france", 549087},
		{"yemen", 527970},
		{"thailand", 513120},
		{"spain", 505940},
		{"turkmenistan", 488100},
		{"cameroon", 475440},
		{"papua new guinea", 462840},
		{"sweden", 447420},
		{"uzbekistan", 447400},
		{"morocco", 446550},
		{"iraq", 435050},
		{"greenland", 410450},
		{"paraguay", 406752},
		{"zimbabwe", 390760},
		{"norway", 385178},
		{"japan", 377962},
		{"germany", 357380},
		{"finland", 338420},
		{"vietnam", 330967},
		{"malaysia", 330800},
		{"cote d'ivoire", 322460},
		{"poland", 312680},
		{"oman", 309500},
		{"italy", 301340},
		{"philippines", 300000},
		{"burkina faso", 274220},
		{"new zealand", 267710},
		{"gabon", 267670},
		{"ecuador", 256370},
		{"guinea", 245860},
		{"united kingdom", 243610},
		{"uganda", 241550},
		{"ghana", 238540},
		{"romania", 238390},
		{"laos", 236800},
		{"guyana", 214970},
		{"belarus", 207600},
		{"kyrgyz", 199949},
		{"senegal", 196710},
		{"syria", 185180},
		{"cambodia", 181040},
		{"uruguay", 176220},
		{"suriname", 163820},
		{"tunisia", 163610},
		{"bangladesh", 147630},
		{"nepal", 147180},
		{"tajikistan", 141376},
		{"greece", 131960},
		{"nicaragua", 130370},
		{"north korea", 120540},
		{"malawi", 118480},
		{"eritrea", 117600},
		{"benin", 114760},
	}

	if a > b {
		a, b = b, a
	}

	var r []string
	for _, p := range tab {
		if a <= p.area && p.area <= b {
			r = append(r, p.name)
		}
	}
	return r
}
