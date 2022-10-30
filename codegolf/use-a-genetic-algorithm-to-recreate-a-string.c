/*

AKA: the most complex way to return a string I could think of.

Requirements:

*Edit: * @Griffin, You are correct, the goal is to use crossover/mutation of characters in a string to eventually come up with the same as input, although, "Hello World" was simply an example. Really, I just like to see what the others on the site can come up with.

Golf. Try to keep it short. Have fun, dag nabbit!

Preferences (not required): -Using a fixed seed on a random number generator would help others reproduce your results. -Bonus if you test for 'properties' of the string, such as the number of L's in "Hello World", instead of only correct characters (like mine).

Shortest code, or highest voted, wins. One exception: if you manage to create a working version in BrainF***, you win.

My take using Java:

import static java.lang.Math.*;import java.util.Arrays;import static java.lang.System.out;import java.util.Random;class G{static char[]c;static Random r;public static void main(String[]a){c=a[0].toCharArray();r=new Random(6);P w=new P(9);int n=0;while(!w.f){w.s();if(w.f)out.println(w.g[w.p].x()+"@gen "+n);n++;}}static class P{boolean f=false;int p=0;M[]g=null;P(int s){if(s>=9)g=new M[s];else g=new M[9];for(int i=0;i<g.length;i++)g[i]=new M(c.length);}void s(){f();if(!f){h();j();}}void f(){for(int i=0;i<g.length;i++){g[i].f(c);if(g[i].l==0){f=true;p=i;}}}void h(){Arrays.sort(g);}void j(){M[]b=new M[g.length];for(int i=0;i<g.length-1;i++){float k=r.nextInt(100);if(k<40)b[i]=new M(g[0],g[1]);else if((k<60)&&(k>40))b[i]=new M(g[0],g[2]);else if((k<80)&&(k>60))b[i]=new M(g[1],g[2]);else if((k<90)&&(k>80))b[i]=new M(g[2],g[3]);else if((k<95)&&(k>90))b[i]=new M(g[2],g[4]);else if((k<99)&&(k>95))b[i]=new M(g[0],g[r.nextInt(g.length)]);else b[i]=new M(g[0],new M(c.length));b[g.length-1]=g[0];}g=b;}}static class M implements Comparable {char[]a=null;int l=0;int q=0;int u=8;int o=20;public int compareTo(Object o){M t=(M)o;if(this.l<t.l)return-1;else if(this.l>t.l)return 1;return 0;}M(int s){a=new char[s];for(int i=0;i<a.length;i++)a[i]=(char)r.nextInt(255);}M(M m,M p){a=new char[m.a.length];for(int i=0;i<m.a.length;i++){a[i]=(r.nextInt(100)>2)?m.a[i]:p.a[i];int z=r.nextInt(100);if(z<u)a[i]=(char)r.nextInt(255);else if(z<o){int b=r.nextInt(6);a[i]=(char)(a[i]^(1<<b));}}}void f(char[]v){l=0;for(int i=0;i<a.length;i++){int d=abs(a[i]-v[i]);l+=d;}}String x(){return new String(a);}}}

Example output from my code:

Hello World!@gen 3352

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

typedef unsigned long long uvlong;
typedef long long vlong;

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return r % n;
}

vlong
fitness(const char *s, const char *t)
{
	vlong r;
	size_t i;

	r = 0;
	for (i = 0; s[i]; i++)
		r += (t[i] - s[i]) * (t[i] - s[i]);
	return r;
}

void
mutate(char *b, size_t n)
{
	size_t i;

	i = randn(n);
	b[i] += (1 - randn(3));
}

// https://www.electricmonk.nl/log/2011/09/28/evolutionary-algorithm-evolving-hello-world/
uvlong
recreate(const char *s, char *b)
{
	vlong v, m;
	uvlong i;
	char *t;
	size_t n;

	n = strlen(s);
	t = b + n + 1;
	b[n] = '\0';

	m = LLONG_MAX;
	for (i = 1;; i++) {
		strcpy(t, b);
		mutate(t, n);
		v = fitness(s, t);
		if (v < m) {
			strcpy(b, t);
			m = v;
		}
		if (v == 0)
			break;
	}
	return i;
}

void
test(const char *s, const char *t)
{
	char b[128];
	uvlong i;

	memset(b, 0, sizeof(b));
	strcpy(b, s);
	i = recreate(t, b);
	printf("%llu %s\n", i, b);
	assert(!strcmp(b, t));
}

int
main(void)
{
	srand(time(NULL));

	test("jiKnp4bqpmAbp", "Hello, World!");
	test("abcdef", "xyzwuv");
	test("cast", "dead");
	test("abcdefg", "ABCDEFG");
	test("", "RECREATION");
	test("USENIX", "WINDOWS");
	test("XZ", "ABCDEFGHI");
	test("ACIJV", "XZQWFD");
	test("", "jkfiojeghihwegiwhi");

	return 0;
}
