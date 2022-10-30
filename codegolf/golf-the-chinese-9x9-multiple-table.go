/*

Output the following table:

一一得一
一二得二 二二得四
一三得三 二三得六 三三得九
一四得四 二四得八 三四十二 四四十六
一五得五 二五一十 三五十五 四五二十 五五二十五
一六得六 二六十二 三六十八 四六二十四 五六三十 六六三十六
一七得七 二七十四 三七二十一 四七二十八 五七三十五 六七四十二 七七四十九
一八得八 二八十六 三八二十四 四八三十二 五八四十 六八四十八 七八五十六 八八六十四
一九得九 二九十八 三九二十七 四九三十六 五九四十五 六九五十四 七九六十三 八九七十二 九九八十一
Or you can use the first three letters in its English word, in case that some languages don't support Chinese characters:

OneOneGetOne
OneTwoGetTwo TwoTwoGetFou
OneThrGetThr TwoThrGetSix ThrThrGetNin
OneFouGetFou TwoFouGetEig ThrFouTenTwo FouFouTenSix
OneFivGetFiv TwoFivOneTen ThrFivTenFiv FouFivTwoTen FivFivTwoTenFiv
OneSixGetSix TwoSixTenTwo ThrSixTenEig FouSixTwoTenFou FivSixThrTen SixSixThrTenSix
OneSevGetSev TwoSevTenFou ThrSevTwoTenOne FouSevTwoTenEig FivSevThrTenFiv SixSevFouTenTwo SevSevFouTenNin
OneEigGetEig TwoEigTenSix ThrEigTwoTenFou FouEigThrTenTwo FivEigFouTen SixEigFouTenEig SevEigFivTenSix EigEigSixTenFou
OneNinGetNin TwoNinTenEig ThrNinTwoTenSev FouNinThrTenSix FivNinFouTenFiv SixNinFivTenFou SevNinSixTenThr EigNinSevTenTwo NinNinEigTenOne
You can output in any reasonable format, e.g. plain text separated with space/comma/tab and newline, 2D array where empty places are empty or don't exist (The 2*1 place is empty so there shouldn't be anything in the array).

Code golf, shortest code in bytes win. GBK encoding is allowed, where each Chinese character use 2 bytes.

Converting Table:

Character	Number
一	One
二	Two
三	Thr
四	Fou
五	Fiv
六	Six
七	Sev
八	Eig
九	Nin
十	Ten
得	Get

*/

package main

import "fmt"

func main() {
	fmt.Println(text)
}

const text = `
一一得一
一二得二 二二得四
一三得三 二三得六 三三得九
一四得四 二四得八 三四十二 四四十六
一五得五 二五一十 三五十五 四五二十 五五二十五
一六得六 二六十二 三六十八 四六二十四 五六三十 六六三十六
一七得七 二七十四 三七二十一 四七二十八 五七三十五 六七四十二 七七四十九
一八得八 二八十六 三八二十四 四八三十二 五八四十 六八四十八 七八五十六 八八六十四
一九得九 二九十八 三九二十七 四九三十六 五九四十五 六九五十四 七九六十三 八九七十二 九九八十一
`
