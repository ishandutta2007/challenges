#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include <cmath>
#include <cerrno>
#include <getopt.h>
#include <cairo.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

#define deg2rad(x) ((x)*M_PI / 180)

struct Flags
{
	int width;
	int height;
	float linewidth;
	string output;
};

struct Turtle
{
	cairo_surface_t *surface;
	cairo_t *cr;

	vector<char> code;
	vector<size_t> stack;
	size_t pc;
	size_t sp;

	float x, y;
	float lw;
	float dir;
	bool pen;

	Turtle(int width, int height, float dir, float linewidth);
	~Turtle();
	bool compile(const string &src);
	void reset();
	void run();

private:
	int fetch();
	void forward(float val);
	void turn(float val);
};

Flags flags = {
	.width = 640,
	.height = 480,
	.linewidth = 2,
	.output = "logo.png",
};

void fatal(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	exit(1);
}

bool read_file(const string &name, string &output)
{
	ifstream file(name);
	if (!file.is_open())
		return false;

	stringstream buffer;
	buffer << file.rdbuf();
	output = buffer.str();
	return true;
}

void usage()
{
	cerr << "usage: [options] code.txt" << endl;
	cerr << "\t-w\tcanvas width (default: " << flags.width << ")" << endl;
	cerr << "\t-h\tcanvas height (default: " << flags.height << ")" << endl;
	cerr << "\t-l\tline width (default: " << setprecision(3) << flags.linewidth << ")" << endl;
	cerr << "\t-o\toutput to file (default: " << flags.output << ")" << endl;
	exit(2);
}

void parse_flags(int *argc, char ***argv)
{
	int c;

	while ((c = getopt(*argc, *argv, "h:l:o:w:")) != -1)
	{
		switch (c)
		{
		case 'h':
			flags.height = atoi(optarg);
			break;
		case 'l':
			flags.linewidth = atof(optarg);
			break;
		case 'o':
			flags.output = optarg;
			break;
		case 'w':
			flags.width = atoi(optarg);
			break;
		}
	}

	*argc -= optind;
	*argv += optind;

	if (*argc < 1)
		usage();

	if (flags.width <= 0 || flags.height <= 0)
		fatal("invalid canvas dimension %dx%d\n", flags.width, flags.height);
}

Turtle::Turtle(int width, int height, float dir, float linewidth)
{
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);
	x = width * 0.5;
	y = height * 0.5;
	this->dir = dir;
	lw = linewidth;
}

Turtle::~Turtle()
{
	cairo_surface_destroy(surface);
	cairo_destroy(cr);
}

bool Turtle::compile(const string &src)
{
	map<string, tuple<int, int> > xec = {
		{ "fd", make_tuple('f', 1) },
		{ "bd", make_tuple('b', 1) },
		{ "rt", make_tuple('r', 1) },
		{ "lt", make_tuple('l', 1) },
		{ "pu", make_tuple('u', 0) },
		{ "pd", make_tuple('d', 0) },
		{ "lw", make_tuple('w', 1) },
		{ "repeat", make_tuple('[', 1) },
		{ "]", make_tuple(']', 0) },
	};

	code.clear();

	char_separator<char> sep(" \t\n", "[]");
	tokenizer<char_separator<char> > tokens(src, sep);
	size_t brackets = 0;
	for (auto tok = tokens.begin(); tok != tokens.end(); tok++)
	{
		auto cmd = *tok;
		auto x = xec.find(cmd);
		if (x == xec.end())
			return false;

		auto op = get<0>(x->second);
		auto args = get<1>(x->second);

		code.push_back(op);
		if (args)
		{
			if (++tok == tokens.end())
				return false;
			code.push_back(stoi(*tok));
		}

		if (cmd == "repeat")
		{
			if (++tok == tokens.end() || *tok != "[")
				return false;
			brackets++;
		}
		else if (cmd == "]")
		{
			if (brackets == 0)
				return false;
			brackets--;
		}
	}

	return true;
}

void Turtle::reset()
{
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_paint(cr);
	cairo_identity_matrix(cr);
	cairo_translate(cr, x, y);
	cairo_move_to(cr, 0, 0);
	cairo_rotate(cr, dir);

	pc = 0;
	sp = 0;
}

int Turtle::fetch()
{
	if (pc >= code.size())
		return 0;
	return code[pc++];
}

void Turtle::forward(float val)
{
	if (pen)
	{
		cairo_set_source_rgb(cr, 1, 1, 1);
		cairo_set_line_width(cr, lw);
		cairo_line_to(cr, val, 0);
		cairo_stroke(cr);
	}
	cairo_move_to(cr, val, 0);
	cairo_translate(cr, val, 0);
}

void Turtle::turn(float angle)
{
	cairo_rotate(cr, angle);
}

void Turtle::run()
{
	for (;;)
	{
		auto op = fetch();
		auto val = 0;
		if (strchr("fbrlw[", op))
			val = fetch();

		switch (op)
		{
		case 'f':
			forward(val);
			break;
		case 'b':
			forward(-val);
			break;
		case 'r':
			turn(deg2rad(val));
			break;
		case 'l':
			turn(deg2rad(val));
			break;
		case 'u':
			pen = false;
			break;
		case 'd':
			pen = true;
			break;
		case 'w':
			lw = val;
			break;
		case '[':
			stack.push_back(pc);
			stack.push_back(val);
			sp += 2;
			break;
		case ']':
			if (sp < 2)
				return;
			if (stack[sp - 1] > 0)
			{
				pc = stack[sp - 2];
				stack[sp - 1] -= 1;
			}
			else
			{
				stack.pop_back();
				stack.pop_back();
				sp -= 2;
			}
			break;
		default:
			return;
		}
	}
}

int main(int argc, char *argv[])
{
	parse_flags(&argc, &argv);

	string src;
	if (!read_file(argv[0], src))
		fatal("Failed to read file: %s: %s", argv[0], strerror(errno));

	auto turtle = new Turtle(flags.width, flags.height, 0, flags.linewidth);
	if (!turtle->compile(src))
		fatal("Failed to compile code");
	turtle->reset();
	turtle->run();
	cairo_surface_write_to_png(turtle->surface, flags.output.c_str());
	delete turtle;

	return 0;
}
