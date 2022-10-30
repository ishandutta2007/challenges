/*

Write a function that adds two numbers. The catch, however, is that the numbers will be strings.

Notes

    If there are any non-numerical characters, return "-1".
    If one option is blank the code should still work.
    Your function should be able to add any size number.
    Your function doesn't have to add negative numbers.

*/

package main

import "math/big"

func main() {
	assert(add("4", "5") == "9")
	assert(add("abcdefg", "3") == "-1")
	assert(add("1", "") == "1")
	assert(add("1874682736267235927359283579235789257", "32652983572985729") == "1874682736267235927391936562808774986")
	assert(add("", "") == "0")
	assert(add("1", "01") == "2")
	assert(add("198547982570192857109283570192837509218375091283750192835710298357019237509125710925710923759012375901275901285701925712035712983571092562945875310962518235712385971230956127856123571209358712905610923587102395716258125612095710298", "510298570192857910827519027510982561875691857120958371029586187585198273501982573091857091875901875809175091659812750918275091875091857918265901265918659816591750981750981759817598175089175891720570129571098758901750917501975") == "198548492868763049967194397711865020200936966975607313794081327943206822707399212908284015616104251803151710460793585524786631258662967654803793576863784154372202562981937878837883388807533802081502644157231966815017027363013212273")
	assert(add("0000001", "020006") == "20007")
	assert(add("1325123515s238579875987", "38698592523525325") == "-1")
	assert(add("123456788654323456543456765432345678843234567150666666666666612735980127350918265309182653091635916258165871265087126121827562875835613875612875360182653127560192756012975608172560817653081760126578132617265192561923051397585261519826512951827401928470192864312873561298357120985710927561287356129857120851235612835712935612385971230598612035912635189273651289357120983571298035612836518237481235098172350891623508912375981206598127539128035619286350912836509123856710298560918236590138257013257219857182935681923569032656109851629851605109283560192863598126359125710982375918237598125091256012893570128357128935609128350192873501928365019283750129837401928374019283740189237401298374019823740912365012381075109823650912837501923561023650123659812375091862350912735", "1023570192835719836509165309156091653091875309312365123569182365123051235710298365109236501928365019283650291836501928365091256109823560921865091263509126509126350921568091265309128653091263590165309160912653809126510560165016501650650165016835610285172356137845623745623592835692836592837569283756832795693827564") == "123456788654323456543456765432345678843234567150666666666666612735980127350918265309182653091635916258165871265087126121827562875835613875612875360182653127560192756012975608172560817653081760126578132617265192561923051397585261519826512951827401928470192864312873561298357120985710927561287356129857120851235612835712935612385971230598612035912635189273651289357120983571298035612836518237481235098172350891623508912375981206598127539128035619286350913860079316692430135070083545746229910105132529169548059251105934155707345561928216714345785488557882881776650962212910741009493707948652177877984833637483638061960049918284138811057018110547340295146562841027828410250749402417800024669988757747975297553431247669274658461094759253860242961229096131924658044740299")
}

func add(a, b string) string {
	if a == "" {
		a = "0"
	}
	if b == "" {
		b = "0"
	}

	p := new(big.Int)
	q := new(big.Int)

	x, xok := p.SetString(a, 10)
	y, yok := q.SetString(b, 10)
	if !xok || !yok {
		return "-1"
	}
	x.Add(x, y)
	return x.String()
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
