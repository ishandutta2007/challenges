/*

Your program is supposed to create a full red screen in MSDOS. The source of the binary (.com file) must be 5 bytes or less.
No wild assumptions, the binary must work in MsDos, DosBox, and FreeDos alike. For winning, you have to post x86 assembler code which can be assembled with NASM (FASM) or directly the hex code of the binary.
You can test you assembler code in an Online Dosbox.

Code Example (six bytes):

X les cx,[si]
inc sp
stosb
jmp short X+1

Try x86 asm code in an Online DosBox

Information on sizecoding for Msdos

"M8trix" might be helpful

Background information/ six bytes version

*/

#include <stdio.h>

int
main(void)
{
	// www.pouet.net
	unsigned char code[] = {0x56, 0xC4, 0x04, 0xAB, 0xC3};

	fwrite(code, sizeof(code), 1, stdout);
	return 0;
}
