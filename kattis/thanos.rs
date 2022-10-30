/*

Dr. Thanos, data scientist and self-described nihilist, recently published a paper titled The snapping point of the universe: why rates of population growth point towards imminent destruction.
In his paper, Thanos explains that in many planets, the increasing population count is leading to a diminished quality of life.
He is convinced that his findings will drive sweeping reforms in intergalactic law, leading to a better life for all organisms.

Thanos turns to you, his confidant, to do some investigation. He would like some concrete evidence for his findings to present to the Association of VENGE’s Research Society.
The society, one of the galatic leaders in egalitarianism and social justice, is holding a special panel to discuss Thano’s findings.
As this involves the chance of actual legislation being passed, Thanos is convinced that the panelists are going to be a tough sell.
He asks you to investigate several datasets and see if they could be potentially helpful in supporting his argument.

Thanos hands you the data for several planets. On each planet’s file, you read that: the planet currently has a population of P, its population grows by a factor of R times per year, and its annual food production F in tons.
All food produced in a year must be consumed that year; it cannot be saved. Assume that each individual consumes 1 ton of food per year, and that the population for each planet each year is always counted as a whole number, rounded down.
Given this information, your task is to find out the number of years a planet has remaining before its population is no longer sustainable by its food production.

Input

The first line of input consists of a single integer T (1≤T≤2000), the number of planets that need to be analyzed.
T lines follow, the ith of which consists of three space-separated integers P (1≤P≤109), R (1<R≤109), and F (1≤F≤109), the metrics of planet i as described above.

Output

Print T lines, the ith of which should consist of a single integer denoting the number of years the ith planet has before it is no longer sustainable.

*/

fn main() {
    assert_eq!(sustain(1, 3, 9), 3);
    assert_eq!(sustain(2, 2, 16), 4);
    assert_eq!(sustain(5, 2, 11), 2);
}

fn sustain(mut p: usize, r: usize, f: usize) -> usize {
    let mut c = 0;
    if r == 0 {
        return 0;
    }
    if r == 1 {
        return usize::MAX;
    }
    while p <= f {
        p *= r;
        c += 1;
    }
    return c;
}
