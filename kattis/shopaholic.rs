/*

Lindsay is a shopaholic.
Whenever there is a discount of the kind where you can buy three items and only pay for two, she goes completely mad and feels a need to buy all items in the store.
You have given up on curing her for this disease, but try to limit its effect on her wallet.

You have realized that the stores coming with these offers are quite selective when it comes to which items you get for free; it is always the cheapest ones.
As an example, when your friend comes to the counter with seven items, costing 400, 350, 300, 250, 200, 150, and 100 dollars, she will have to pay 1500 dollars.
In this case she got a discount of 250 dollars.
You realize that if she goes to the counter three times, she might get a bigger discount.
E.g. if she goes with the items that costs 400, 300 and 250, she will get a discount of 250 the first round.
The next round she brings the item that costs 150 giving no extra discount, but the third round she takes the last items that costs 350, 200 and 100
giving a discount of an additional 100 dollars, adding up to a total discount of 350.

Your job is to find the maximum discount Lindsay can get.

Input

The first line of input gives the number of items Lindsay is buying, 1≤n≤200000.
The next line gives the prices of these items, which are integers 1≤pi≤200000.

Output

Output one line giving the maximum discount Lindsay can get by selectively choosing which items she brings to the counter at the same time.

*/

fn main() {
    assert_eq!(max_discount(vec![400, 100, 200, 350, 300, 250]), 400);
}

fn max_discount(mut a: Vec<isize>) -> isize {
    a.sort_by(|x, y| y.cmp(x));

    let mut r = 0;
    let mut i = 2;
    while i < a.len() {
        r += a[i];
        i += 3;
    }
    r
}
