#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef map<string, vector<char> > ngram_t;

int randn(int n)
{
	if (n == 0)
		return 0;

	int r;
	do
	{
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

string read_file(const char *name)
{
	string str = "";

	auto fp = fopen(name, "rb");
	if (!fp)
		return str;

	int c;
	while ((c = fgetc(fp)) != EOF)
		str += c;
	fclose(fp);

	return str;
}

ngram_t make_ngrams(const string &text, int order)
{
	ngram_t ngrams;
	ssize_t len = text.size() - order;
	for (ssize_t i = 0; i < len; i++)
	{
		auto gram = text.substr(i, order);
		ngrams[gram].push_back(text[i + order]);
	}
	return ngrams;
}

string markov(ngram_t &ngrams, const string &text, int order, int chains)
{
	auto gram = text.substr(0, order);
	auto res = gram;
	for (auto i = 0; i < chains; i++)
	{
		if (ngrams.find(gram) == ngrams.end())
			break;

		auto list = ngrams[gram];
		if (list.size() == 0)
			break;

		auto ch = list[randn(list.size()) - 1];
		res += ch;

		auto len = res.size();
		gram = res.substr(len - order, len);
	}
	return res;
}

void usage()
{
	fprintf(stderr, "usage: words.txt [order]\n");
	exit(2);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		usage();

	srand(time(NULL));
	auto text = read_file(argv[1]);
	auto order = 2;
	if (argc >= 3)
		order = atoi(argv[2]);

	auto ngrams = make_ngrams(text, order);
	auto result = markov(ngrams, text, order, 100);
	cout << result << endl;

	return 0;
}
