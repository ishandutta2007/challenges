/*

At some point, I bumped into an SO question asking how to implement Perl's trivial hash-of-hashes data structure in Java.

For those who don't know Perl, the hash value can be a scalar or another hash, or technically speaking hash reference.
Arbitrary depth. Additional feature offered by Perl is autovivification - assigning an element 4 layers deep will automatically create correct hashes with proper keys 4 levels deep,
without Java's need to assign hash object on level 1, then hash object on level 2 (being added to the first hash as a value) etc...

So, Perl code to assign a value to N-level hash at a known depth is

my $myHash; # initialization isn't required due to autovivification
$myHash->{$key1}->{$key2}->{$key3}->{$key4} = $value;
And to retrieve it

my $value = $myHash->{$key1}->{$key2}->{$key3}->{$key4};
The more generic code to assign a hash by arbitrary set of keys can be implemented by 5-10 line subroutine done properly; or 2-3 lines golf hack with eval.

Not being anywhere near a Java expert, my SO answer was ~30 lines of code that implemented a fixed-depth 3 level hash of hash of hashes.

Your mission, should you choose to accept it, is to produce the smallest code in a strongly typed language which implements Perl equivalent data structure which is a hashmap of hashmaps of ...; of arbitrary and non-uniform depth (basically, a tree);
with hasmap keys being of String type; and leaf-level values String or Integer. The code should support 100% of what the Perl hash-of-hashes code does, including:

Retrieving a value based on a list of keys

Assigning a value based on a list of keys

As part of this, you should be able to replace a scalar leaf level node with an internal hashmap node, if your list of keys leads to that.

E.g. set("val1","k1","k2");set("val2","k1","k2","k3") basically erases "val1" from existence after second call as it's replaced by a 3rd level hashmap.

The code should be resilient, e.g. no null exceptions etc... even for the bad input (simply return NULL)

You can use any strongly typed language other than Java, though I would personally prefer Java answers due to how/why this question originated.

Caveat: using some 3rd party library that implements equivalent of Perl hashes is NOT acceptable. 100% of the code must be using only the native core capabilities of the language.

*/

package main

func main() {
	h := make(Hashes)
	assert(h.Set("val1", "k1", "k2") == true)
	assert(h.Get("k1", "k2") == "val1")
	assert(h.Set("val2", "k1", "k2", "k3") == true)
	assert(h.Get("k1", "k2", "k3") == "val2")
	assert(h.Get("k1", "k2") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Hashes map[string]any

func (h Hashes) Set(value string, keys ...string) bool {
	return h.lookup(keys, value) != nil
}

func (h Hashes) Get(keys ...string) string {
	r := h.lookup(keys, nil)
	v, _ := r.(string)
	return v
}

func (h Hashes) lookup(keys []string, value any) any {
	n := len(keys)
	if n == 0 {
		return nil
	}

	m := h
	v := value
	for i := 0; i < n-1; i++ {
		k := keys[i]
		if v != nil {
			m[k] = make(Hashes)
		}

		l, _ := m[k].(Hashes)
		if l == nil {
			return nil
		}
		m = l
	}

	k := keys[n-1]
	if v != nil {
		m[k] = v
	}
	return m[k]
}
