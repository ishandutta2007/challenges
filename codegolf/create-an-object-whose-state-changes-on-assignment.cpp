/*

I find it deeply weird that this is possible in Ruby (I won't immediately say how):

obj = #code redacted

print obj.state # Some value.

LValue = obj

print obj.state # Different value!
Your challenge is to create code roughly of this form. Create an object and assign it to a variable. It should have some defined attribute (or deterministic, idempotent method) like state above,
that changes after the object is assigned to a new identifier (LValue above), even if you still use the old identifier (obj above) to refer to it.

Edit for emphasis: state or the equivalent must be idempotent, so creating an accessor that modifies the value, or for any other reason returns different results when called several times in a row, isn't a valid solution.
Or, more simply, it has to be the assignment that changes the state.

Any language with assignment is eligible, although there are probably some where there's no fully legitimate solution. I'll post my Ruby answer if nobody else gets it after a few days, and accept highest-voted answers on a rolling basis.

*/

#include <cstdio>

using namespace std;

struct Object
{
	int state;

	Object()
	{
		state = 0;
	}

	Object(Object &obj)
	{
		state = obj.state++;
	}
};

int main()
{
	auto a = Object();
	printf("%d\n", a.state);

	auto b = a;
	printf("%d %d\n", a.state, b.state);

	auto c = a;
	printf("%d %d %d\n", a.state, b.state, c.state);

	return 0;
}
