/*

Wild Roger is participating in a Western Showdown, meaning he has to draw (pull out and shoot) his gun faster than his opponent in a gun standoff.

Given two strings, p1 and p2, return which person drew their gun the fastest. If both are drawn at the same time, return "tie".

Examples

showdown(
  "   Bang!        ",
  "        Bang!   "
) ➞ "p1"

// p1 draws his gun sooner than p2

showdown(
  "               Bang! ",
  "             Bang!   "
) ➞ "p2"

showdown(
  "     Bang!   ",
  "     Bang!   "
) ➞ "tie"

Notes

Both strings are the same length.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
showdown(const char *a, const char *b)
{
	char *p, *q;

	p = strstr(a, "Bang!");
	q = strstr(b, "Bang!");
	if (!p || !q)
		return NULL;

	if (p - a < q - b)
		return "p1";
	if (p - a > q - b)
		return "p2";
	return "tie";
}

void
test(const char *a, const char *b, const char *r)
{
	const char *p;

	p = showdown(a, b);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("  Bang!     ", "     Bang!  ", "p1");
	test(" Bang!  ", "  Bang! ", "p1");
	test("          Bang!       ", "       Bang!          ", "p2");
	test("    Bang!    ", "    Bang!    ", "tie");
	test("       Bang!       ", "       Bang!       ", "tie");
	test(" Bang!      ", "      Bang! ", "p1");
	test(" Bang!  ", "  Bang! ", "p1");
	test("       Bang!      ", "      Bang!       ", "p2");
	test("         Bang!    ", "    Bang!         ", "p2");
	test("   Bang!        ", "        Bang!   ", "p1");
	test("      Bang! ", " Bang!      ", "p2");
	test("  Bang!          ", "          Bang!  ", "p1");
	test("        Bang!    ", "    Bang!        ", "p2");
	test("     Bang!     ", "     Bang!     ", "tie");
	test("       Bang!   ", "   Bang!       ", "p2");
	test("  Bang! ", " Bang!  ", "p2");
	test(" Bang!      ", "      Bang! ", "p1");
	test("  Bang!      ", "      Bang!  ", "p1");
	test(" Bang!       ", "       Bang! ", "p1");
	test("    Bang!  ", "  Bang!    ", "p2");
	test("      Bang!        ", "        Bang!      ", "p1");
	test("          Bang!      ", "      Bang!          ", "p2");
	test("       Bang!        ", "        Bang!       ", "p1");
	test("         Bang! ", " Bang!         ", "p2");
	test(" Bang!   ", "   Bang! ", "p1");
	test("  Bang!  ", "  Bang!  ", "tie");
	test("      Bang!          ", "          Bang!      ", "p1");
	test("      Bang!      ", "      Bang!      ", "tie");
	test("         Bang!         ", "         Bang!         ", "tie");
	test("       Bang! ", " Bang!       ", "p2");
	test(" Bang!    ", "    Bang! ", "p1");
	test("     Bang!   ", "   Bang!     ", "p2");
	test("   Bang!       ", "       Bang!   ", "p1");
	test("    Bang!       ", "       Bang!    ", "p1");
	test("         Bang!         ", "         Bang!         ", "tie");
	test("   Bang!      ", "      Bang!   ", "p1");
	test("   Bang!   ", "   Bang!   ", "tie");
	test("       Bang!    ", "    Bang!       ", "p2");
	test("  Bang!     ", "     Bang!  ", "p1");
	test("     Bang!  ", "  Bang!     ", "p2");
	test("   Bang! ", " Bang!   ", "p2");
	test("    Bang!   ", "   Bang!    ", "p2");
	test(" Bang! ", " Bang! ", "tie");
	test("       Bang!   ", "   Bang!       ", "p2");
	test("  Bang! ", " Bang!  ", "p2");
	test("        Bang!  ", "  Bang!        ", "p2");
	test("   Bang!   ", "   Bang!   ", "tie");
	test("       Bang! ", " Bang!       ", "p2");
	test("    Bang!        ", "        Bang!    ", "p1");
	test("  Bang!         ", "         Bang!  ", "p1");
	test("     Bang!     ", "     Bang!     ", "tie");
	test("         Bang!    ", "    Bang!         ", "p2");
	test("         Bang!         ", "         Bang!         ", "tie");
	test("  Bang!    ", "    Bang!  ", "p1");
	test("  Bang!        ", "        Bang!  ", "p1");
	test("     Bang!       ", "       Bang!     ", "p1");
	test("    Bang!       ", "       Bang!    ", "p1");
	test("        Bang!        ", "        Bang!        ", "tie");
	test("          Bang!   ", "   Bang!          ", "p2");
	test("  Bang!      ", "      Bang!  ", "p1");
	test("  Bang!    ", "    Bang!  ", "p1");
	test("    Bang!       ", "       Bang!    ", "p1");
	test("       Bang! ", " Bang!       ", "p2");
	test("  Bang!        ", "        Bang!  ", "p1");
	test("         Bang!          ", "          Bang!         ", "p1");
	test("         Bang!    ", "    Bang!         ", "p2");
	test("     Bang!  ", "  Bang!     ", "p2");
	test("       Bang!      ", "      Bang!       ", "p2");
	test("    Bang!          ", "          Bang!    ", "p1");
	test("         Bang!   ", "   Bang!         ", "p2");
	test("    Bang!        ", "        Bang!    ", "p1");
	test("      Bang!  ", "  Bang!      ", "p2");
	test("       Bang!          ", "          Bang!       ", "p1");
	test("    Bang!          ", "          Bang!    ", "p1");
	test("      Bang!      ", "      Bang!      ", "tie");
	test("     Bang!        ", "        Bang!     ", "p1");
	test("     Bang!         ", "         Bang!     ", "p1");
	test("    Bang!         ", "         Bang!    ", "p1");
	test(" Bang!          ", "          Bang! ", "p1");
	test("       Bang!  ", "  Bang!       ", "p2");
	test("        Bang!     ", "     Bang!        ", "p2");
	test("          Bang!      ", "      Bang!          ", "p2");
	test("    Bang!         ", "         Bang!    ", "p1");
	test("       Bang!         ", "         Bang!       ", "p1");
	test("   Bang!     ", "     Bang!   ", "p1");
	test("  Bang!  ", "  Bang!  ", "tie");
	test("    Bang!         ", "         Bang!    ", "p1");
	test("     Bang!         ", "         Bang!     ", "p1");
	test("     Bang!      ", "      Bang!     ", "p1");
	test("          Bang!  ", "  Bang!          ", "p2");
	test("     Bang!   ", "   Bang!     ", "p2");
	test(" Bang!    ", "    Bang! ", "p1");
	test(" Bang!   ", "   Bang! ", "p1");
	test("   Bang!          ", "          Bang!   ", "p1");
	test("    Bang!    ", "    Bang!    ", "tie");
	test("    Bang!    ", "    Bang!    ", "tie");
	test("        Bang!  ", "  Bang!        ", "p2");
	test("         Bang!       ", "       Bang!         ", "p2");
	test("       Bang!   ", "   Bang!       ", "p2");
	test("   Bang!   ", "   Bang!   ", "tie");

	return 0;
}
