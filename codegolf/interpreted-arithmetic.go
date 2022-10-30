/*

A little known fact is that if you turn on enough language extensions (ghc) Haskell becomes a dynamically typed interpreted language! For example the following program implements addition.

{-# Language MultiParamTypeClasses, FunctionalDependencies, FlexibleInstances, UndecidableInstances #-}

data Zero
data Succ a

class Add a b c | a b -> c
instance Add Zero a a
instance (Add a b c) => Add (Succ a) b (Succ c)
This doesn't really look like Haskell any more. For one instead of operating over objects, we operate over types. Each number is it's own type. Instead of functions we have type classes. The functional dependencies allows us to use them as functions between types.

So how do we invoke our code? We use another class

class Test a | -> a
 where test :: a
instance (Add (Succ (Succ (Succ (Succ Zero)))) (Succ (Succ (Succ Zero))) a)
  => Test a
This sets the type of test to the type 4 + 3. If we open this up in ghci we will find that test is indeed of type 7:

Ok, one module loaded.
*Main> :t test
test :: Succ (Succ (Succ (Succ (Succ (Succ (Succ Zero))))))
Task
I want you to implement a class that multiplies two Peano numerals (non-negative integers). The Peano numerals will be constructed using the same data types in the example above:

data Zero
data Succ a
And your class will be evaluated in the same way as above as well. You may name your class whatever you wish.

You may use any ghc language extensions you want at no cost to bytes.

Test Cases
These test cases assume your class is named M, you can name it something else if you would like.

class Test1 a| ->a where test1::a
instance (M (Succ (Succ (Succ (Succ Zero)))) (Succ (Succ (Succ Zero))) a)=>Test1 a

class Test2 a| ->a where test2::a
instance (M Zero (Succ (Succ Zero)) a)=>Test2 a

class Test3 a| ->a where test3::a
instance (M (Succ (Succ (Succ (Succ Zero)))) (Succ Zero) a)=>Test3 a

class Test4 a| ->a where test4::a
instance (M (Succ (Succ (Succ (Succ (Succ (Succ Zero)))))) (Succ (Succ (Succ Zero))) a)=>Test4 a
Results
*Main> :t test1
test1
  :: Succ
       (Succ
          (Succ
             (Succ
                (Succ (Succ (Succ (Succ (Succ (Succ (Succ (Succ Zero)))))))))))
*Main> :t test2
test2 :: Zero
*Main> :t test3
test3 :: Succ (Succ (Succ (Succ Zero)))
*Main> :t test4
test4
  :: Succ
       (Succ
          (Succ
             (Succ
                (Succ
                   (Succ
                      (Succ
                         (Succ
                            (Succ
                               (Succ
                                  (Succ
                                     (Succ (Succ (Succ (Succ (Succ (Succ (Succ Zero)))))))))))))))))
Draws inspiration from Typing the technical interview

*/

package main

func main() {
	for x := 0; x <= 100; x++ {
		for y := 0; y <= 100; y++ {
			assert(x*y == value(mul(gen(x), gen(y))))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Nat *Nat

func zero() *Nat         { return nil }
func iszero(x *Nat) bool { return x == nil }

func add1(x *Nat) *Nat {
	r := new(Nat)
	*r = x
	return r
}

func sub1(x *Nat) *Nat {
	return *x
}

func add(x, y *Nat) *Nat {
	if iszero(y) {
		return x
	}
	return add(add1(x), sub1(y))
}

func mul(x, y *Nat) *Nat {
	if iszero(x) || iszero(y) {
		return zero()
	}
	return add(mul(x, sub1(y)), x)
}

func gen(n int) *Nat {
	if n > 0 {
		return add1(gen(n - 1))
	}
	return zero()
}

func value(x *Nat) int {
	if iszero(x) {
		return 0
	}
	return value(sub1(x)) + 1
}
