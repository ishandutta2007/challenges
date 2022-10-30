// Have the function CheckNums(num1,num2) take both parameters being passed and return the string true if num2 is greater than num1, otherwise return the string false.
// If the parameter values are equal to each other then return the string -1.

fn main() {
    println!("{}", check_nums(3, 122));
    println!("{}", check_nums(67, 67));
}

fn check_nums(x: isize, y: isize) -> String {
    if x < y {
        "true".to_string()
    } else if x > y {
        "false".to_string()
    } else {
        "-1".to_string()
    }
}
