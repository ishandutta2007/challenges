/*

My teacher gave me a simple problem which I should solve with a code tiny as possible. I should print all odd numbers from 0 to 100000 into a HTML document using javascript.

for(var y = 0; y < 100000; y++){
    if(!(y % 2 == 0)){
        document.write(y + " ");
    }
};

Is it possible to do that shorter?

*/

fn main() {
    print_odds(100000);
}

fn print_odds(n: isize) {
    let mut i = 1;
    while i <= n {
        println!("{}", i);
        i += 2;
    }
}
