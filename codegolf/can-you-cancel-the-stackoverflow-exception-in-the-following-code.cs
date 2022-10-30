/*

The following code will produce a run-time error, stackoverflow exception.

class Foo
{
    //static Foo foo = new Foo(); // you are not allowed using this approach
    //static readonly Foo foo = new Foo(); // you are not allowed using this approach
    Foo foo = new Foo();
}
class Program
{
    static void Main(string[] args)
    {
        new Foo();
    }
}

The objective is to cancel the exception without

    removing, modifying or commenting out the existing code,
    using the approaches mentioned (and their variants in access modifiers, public, private, etc) as the given comments,
    using try-catch-finally or its variants,
    using attributes,
    using compilation condition,

You are only allowed to add your own code inside the Foo class. How do you cancel the exception at run-time?

*/

class Foo
{
    static public readonly Foo foo = new Foo();
}

class Program
{
    static void Main(string[] args)
    {
        new Foo();
    }
}

