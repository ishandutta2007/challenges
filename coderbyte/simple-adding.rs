/*

Have the function SimpleAdding(num) add up all the numbers from 1 to num. For example: if the input is 4 then your program should return 10 because 1 + 2 + 3 + 4 = 10. For the test cases, the parameter num will be any number from 1 to 1000. 
*/

fn main() {
    println!("{}", simple_adding(4));
    println!("{}", simple_adding(12));
    println!("{}", simple_adding(140));
    println!("{}", simple_adding(1000));
}

fn simple_adding(n: isize) -> isize {
    n*(n+1)/2
}
