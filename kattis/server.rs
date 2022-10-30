/*

You are in charge of a server that needs to run some submitted tasks on a first-come, first-served basis.
Each day, you can dedicate the server to run these tasks for at most T minutes.
Given the time each task takes, you want to know how many of them will be finished today.

Consider the following example.
Assume T=180 and the tasks take 45,30,55,20,80, and 20 minutes (in order they are submitted).
Then, only four tasks can be completed. The first four tasks can be completed because they take 150 minutes, but not the first five, because they take 230 minutes which is greater than 180.
Notice that although there is enough time to perform the sixth task (which takes 20 minutes) after completing the fourth task, you cannot do that because the fifth task is not done yet.

Input

The input consists of a single test case. The first line contains two integers n and T where 1≤n≤50 is the number of tasks and 1≤T≤500.
The next line contains n positive integers no more than 100 indicating how long each task takes in order they are submitted.

Output

Display the number of tasks that can be completed in T minutes on a first-come, first-served basis.

*/

fn main() {
    assert_eq!(server(&[45, 30, 55, 20, 80, 20], 180), 4);
    assert_eq!(server(&[20, 7, 10, 8, 10, 27, 2, 3, 10, 5], 60), 5);
}

fn server(a: &[isize], t: isize) -> isize {
    let (mut u, mut c) = (0, 0);
    for v in a {
        u += v;
        if u > t {
            break
        }
        c += 1;
    }
    c
}
