/*

Background

The Thousand Character Classic is a chinese poem written around the 4th Century CE in China, and memorized by large populations since then.
The name comes from not only its length, but its number of characters: each character occurs only once in the text.
It is commonly used to teach children chinese characters, and also, because of its commonness, as a means of enumerating the 1000 characters in the text.

The challenge

Here is a copy of the Thousand Character Classic, gotten from Wikipedia.

The Thousand Character Classic

Reproduce the entirety of the Thousand Character Classic in either UTF-8 or UTF-16, including punctuation, newlines, and heading numbers. Punctuation can be halfwidth or fullwidth, and the trailing newline is optional.

For those that want to analyze the unicode text for patterns, I've provided hexdumps of both encodings.

utf-8

utf-16

Rules

Because of the size of the text to reproduce, you may optionally supply a file for your submission to use as input. If this is done, add the byte length of the input file to the byte length of your code.

Otherwise, this is a standard issue code golf challenge, so standard loopholes apply, and shortest submission wins.

*/

#include <cstdio>

static const char8_t text[] = u8R"(1
天地玄黃，宇宙洪荒。 
日月盈昃，辰宿列張。 
寒來暑往，秋收冬藏。 
閏餘成歲，律呂調陽。 
雲騰致雨，露結為霜。 
金生麗水，玉出崑岡。 
劍號巨闕，珠稱夜光。 
果珍李柰，菜重芥姜。 
海咸河淡，鱗潛羽翔。 
2
龍師火帝，鳥官人皇。 
始制文字，乃服衣裳。 
推位讓國，有虞陶唐。 
弔民伐罪，周發殷湯。 
坐朝問道，垂拱平章。 
愛育黎首，臣伏戎羌。 
遐邇一體，率賓歸王。 
鳴鳳在竹，白駒食場。 
化被草木，賴及萬方。 
3
蓋此身髮，四大五常。 
恭惟鞠養，豈敢毀傷。 
女慕貞絜，男效才良。 
知過必改，得能莫忘。 
罔談彼短，靡恃己長。 
信使可覆，器欲難量。 
墨悲絲染，詩讚羔羊。 
景行維賢，克念作聖。 
德建名立，形端表正。 
空谷傳聲，虛堂習聽。 
禍因惡積，福緣善慶。 
尺璧非寶，寸陰是競。 
資父事君，曰嚴與敬。 
孝當竭力，忠則盡命。 
臨深履薄，夙興溫凊。 
似蘭斯馨，如松之盛。 
川流不息，淵澄取映。 
容止若思，言辭安定。 
篤初誠美，慎終宜令。 
榮業所基，藉甚無竟。 
學優登仕，攝職從政。 
存以甘棠，去而益詠。 
樂殊貴賤，禮別尊卑。 
上和下睦，夫唱婦隨。 
外受傅訓，入奉母儀。 
諸姑伯叔，猶子比兒。 
孔懷兄弟，同氣連根。 
交友投分，切磨箴規。 
仁慈隱惻，造次弗離。 
節義廉退，顛沛匪虧。 
性靜情逸，心動神疲。 
守真志滿，逐物意移。 
堅持雅操，好爵自縻。 
4
都邑華夏，東西二京。 
背邙面洛，浮渭據涇。 
宮殿盤郁，樓觀飛驚。 
圖寫禽獸，畫彩仙靈。 
丙舍傍啟，甲帳對楹。 
肆筵設席，鼓瑟吹笙。 
升階納陛，弁轉疑星。 
右通廣內，左達承明。 
既集墳典，亦聚群英。 
杜稿鍾隸，漆書壁經。 
府羅將相，路俠槐卿。 
戶封八縣，家給千兵。 
高冠陪輦，驅轂振纓。 
世祿侈富，車駕肥輕。 
策功茂實，勒碑刻銘。 
磻溪伊尹，佐時阿衡。 
奄宅曲阜，微旦孰營。 
桓公匡合，濟弱扶傾。 
綺回漢惠，說感武丁。 
俊乂密勿，多士寔寧。 
晉楚更霸，趙魏困橫。 
假途滅虢，踐土會盟。 
何遵約法，韓弊煩刑。 
起翦頗牧，用軍最精。 
宣威沙漠，馳譽丹青。 
九州禹跡，百郡秦并。 
岳宗泰岱，禪主云亭。 
雁門紫塞，雞田赤城。 
昆池碣石，鉅野洞庭。 
曠遠綿邈，岩岫杳冥。 
5
治本於農，務茲稼穡。 
俶載南畝，我藝黍稷。 
稅熟貢新，勸賞黜陟。 
孟軻敦素，史魚秉直。 
庶幾中庸，勞謙謹敕。 
聆音察理，鑒貌辨色。 
貽厥嘉猷，勉其祗植。 
省躬譏誡，寵增抗極。 
殆辱近恥，林皋幸即。 
兩疏見機，解組誰逼。 
索居閒處，沉默寂寥。 
求古尋論，散慮逍遙。 
欣奏累遣，慼謝歡招。 
渠荷的歷，園莽抽條。 
枇杷晚翠，梧桐蚤凋。 
陳根委翳，落葉飄搖。 
游鵾獨運，凌摩絳霄。 
6
耽讀玩市，寓目囊箱。 
易輶攸畏，屬耳垣牆。 
具膳餐飯，適口充腸。 
飽飫烹宰，飢厭糟糠。 
親戚故舊，老少異糧。 
妾御績紡，待巾帷房。 
紈扇圓潔，銀燭煒煌。 
晝眠夕寐，藍筍象床。 
弦歌酒宴，接杯舉觴。 
矯手頓足，悅豫且康。 
嫡後嗣續，祭祀烝嘗。 
稽顙再拜，悚懼恐惶。 
箋牒簡要，顧答審詳。 
骸垢想浴，執熱願涼。 
驢騾犢特，駭躍超驤。 
誅斬賊盜，捕獲叛亡。 
7
布射僚丸，嵇琴阮嘯。
恬筆倫紙，鈞巧任釣。
釋紛利俗，竝皆佳妙。
毛施淑姿，工顰妍笑。
年矢每催，曦暉朗曜。
璿璣懸斡，晦魄環照。
指薪修祜，永綏吉劭。
矩步引領，俯仰廊廟。
束帶矜庄，徘徊瞻眺。
孤陋寡聞，愚蒙等誚。
謂語助者，焉哉乎也。
)";

int main()
{
	for (auto ch : text)
		printf("%c", ch);
	
	return 0;
}
