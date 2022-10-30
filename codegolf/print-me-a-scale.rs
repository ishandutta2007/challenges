/*

Oh no! I have a theory test soon and I don't remember the scales yet! Help me remember my major scales by printing the following:

7♯ - C♯ D♯ E♯ F♯ G♯ A♯ B♯ C♯
6♯ - F♯ G♯ A♯ B  C♯ D♯ E♯ F♯
5♯ - B  C♯ D♯ E  F♯ G♯ A♯ B
4♯ - E  F♯ G♯ A  B  C♯ D♯ E
3♯ - A  B  C♯ D  E  F♯ G♯ A
2♯ - D  E  F♯ G  A  B  C♯ D
1♯ - G  A  B  C  D  E  F♯ G
0  - C  D  E  F  G  A  B  C
1♭ - F  G  A  B♭ C  D  E  F
2♭ - B♭ C  D  E♭ F  G  A  B♭
3♭ - E♭ F  G  A♭ B♭ C  D  E♭
4♭ - A♭ B♭ C  D♭ E♭ F  G  A♭
5♭ - D♭ E♭ F  G♭ A♭ B♭ C  D♭
6♭ - G♭ A♭ B♭ C♭ D♭ E♭ F  G♭
7♭ - C♭ D♭ E♭ F♭ G♭ A♭ B♭ C♭

This is code-golf, so shortest code wins. You may use # and b symbols instead of ♯ and ♭ respectively.

Edit: If you are using ♯ and ♭ signs, you only have to count them as a single byte each. This is to not give an unfair disadvantage.

*/

fn main() {
    let string = "7♯ - C♯ D♯ E♯ F♯ G♯ A♯ B♯ C♯
6♯ - F♯ G♯ A♯ B  C♯ D♯ E♯ F♯
5♯ - B  C♯ D♯ E  F♯ G♯ A♯ B
4♯ - E  F♯ G♯ A  B  C♯ D♯ E
3♯ - A  B  C♯ D  E  F♯ G♯ A
2♯ - D  E  F♯ G  A  B  C♯ D
1♯ - G  A  B  C  D  E  F♯ G
0  - C  D  E  F  G  A  B  C
1♭ - F  G  A  B♭ C  D  E  F
2♭ - B♭ C  D  E♭ F  G  A  B♭
3♭ - E♭ F  G  A♭ B♭ C  D  E♭
4♭ - A♭ B♭ C  D♭ E♭ F  G  A♭
5♭ - D♭ E♭ F  G♭ A♭ B♭ C  D♭
6♭ - G♭ A♭ B♭ C♭ D♭ E♭ F  G♭
7♭ - C♭ D♭ E♭ F♭ G♭ A♭ B♭ C♭";
    
    println!("{}", string);
}

