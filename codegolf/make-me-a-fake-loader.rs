/*

Make a fake loader just like this :

Parameters :
Display loading (space) one of these cyclically-\|/ (space) (percentage counter from 0-100) then a %.
The percentage counter is supposed to increment by 1 every time the display changes.
The time taken by counter to jump to next iteration is random. Any kind of random will do as long as the function/method is capable of generating all random integers having probability > 0 in range 1<= ms <=750 here ms being time in milliseconds.
Start at loading - 0 %.
End at loading - 100 %.
NO INPUT is required.
submit a full program or function or whatever similar.
The code that I used :

C++
#include<stdio.h>
#include<time.h>
#include<windows.h>

int main()
{
    srand(time(NULL));
    char a[15],b[]="-\\|/";
    int i=0,j=0,ms;
    while(j<101)
    {
        (i<3)?i++:i=0;
        wsprintf(a,"loading %c %d ",b[i],j++);
        printf(a);puts("%");
            //This part is to make the output look cool
        switch(rand()%9)
        {
            case 0:ms=1;break;
            case 1:ms=2;break;
            case 2:ms=5;break;
            case 3:ms=10;break;
            case 4:ms=15;break;
            case 5:ms=20;break;
            case 6:ms=25;break;
            case 7:ms=50;break;
            case 8:ms=500;
        }
        Sleep(ms);  //Otherwise this is supposed to be random
        if(j<101)   //like this Sleep(rand()%750+1);
        system("cls");
    }
}

Winner

the code with least bytes wins.

*/

use std::thread::*;
use std::time::*;

fn main() {
    loader();
}

fn loader() {
    let dtab = [1, 2, 5, 10, 15, 20, 25, 50, 500];
    let stab = ['-', '\\', '|', '/'];

    let now = SystemTime::now();
    let epoch = now.duration_since(UNIX_EPOCH).unwrap();
    let seed = epoch.as_secs();

    let mut lcg = LCG::new();
    lcg.seed(seed);

    for i in 0..101 {
        print!("\x1b[2J\x1b[H");
        println!("loading {} {} %", stab[i % 4], i);
        let delay = dtab[(lcg.next() % 9) as usize];
        sleep(Duration::from_millis(delay));
    }
    println!();
}

struct LCG {
    seed: u64,
}

impl LCG {
    fn new() -> LCG {
        LCG { seed: 0 }
    }

    fn seed(&mut self, seed: u64) {
        self.seed = seed;
    }

    fn next(&mut self) -> u64 {
        self.seed = self.seed.wrapping_mul(6364136223846793005);
        self.seed = self.seed.wrapping_add(1);
        return self.seed >> 33;
    }
}
