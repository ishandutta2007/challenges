/*

Background

Inspired by this Unix.SE question (and of course my own answer).

When an IP address is specified for an interface, it is often given in this dotted-decimal form:

a.b.c.d e.f.g.h

where a.b.c.d is the actual address and e.f.g.h is the netmask.

The netmask, when represented in binary, is basically a bunch of 1 bits followed by a bunch of 0 bits. When the netmask is bitwise ANDed against the given IP address,
result will be the network portion of the address, or simply the network address.
This will be programmed into the host's route table so that the host knows to send anything destined for this network out this interface.

The broadcast address for a network is derived by taking the network address (from above) and setting all the host-bits to 1. The broadcast address is used to send to all addresses within the given network.
Challenge

Given a dotted-decimal IP address and valid netmask as input, provide the network address and broadcast address as output, also in dotted-decimal format.

    Input must be address and mask as two strings in dotted-decimal format. You may pass this as 2 separate strings, as list or array of 2 string elements or a single string with the address and mask separated by some sensible separator.
    Output format is subject to the same constraints as input format.

Examples

Input                              Output

192.168.0.1 255.255.255.0          192.168.0.0 192.168.0.255
192.168.0.0 255.255.255.0          192.168.0.0 192.168.0.255
192.168.0.255 255.255.255.0        192.168.0.0 192.168.0.255
100.200.100.200 255.255.255.255    100.200.100.200 100.200.100.200
1.2.3.4 0.0.0.0                    0.0.0.0 255.255.255.255
10.25.30.40 255.252.0.0            10.24.0.0 10.27.255.255

*/

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint32_t
ip4(const char *s)
{
	unsigned b[4];

	memset(b, 0, sizeof(b));
	sscanf(s, "%u.%u.%u.%u", b, b + 1, b + 2, b + 3);
	return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}

char *
ip4s(uint32_t x, char *b)
{
	sprintf(b, "%u.%u.%u.%u", (x >> 24) & 0xff, (x >> 16) & 0xff, (x >> 8) & 0xff, x & 0xff);
	return 0;
}

void
test(const char *i, const char *m, const char *rn, const char *rb)
{
	uint32_t x, n;
	char b[2][128];

	x = ip4(i);
	n = ip4(m);
	ip4s(x & n, b[0]);
	ip4s(x | ~n, b[1]);

	printf("%s %s -> %s %s\n", i, m, b[0], b[1]);
	assert(!strcmp(b[0], rn));
	assert(!strcmp(b[1], rb));
}

int
main(void)
{
	test("192.168.0.1", "255.255.255.0", "192.168.0.0", "192.168.0.255");
	test("192.168.0.0", "255.255.255.0", "192.168.0.0", "192.168.0.255");
	test("192.168.0.255", "255.255.255.0", "192.168.0.0", "192.168.0.255");
	test("100.200.100.200", "255.255.255.255", "100.200.100.200", "100.200.100.200");
	test("1.2.3.4", "0.0.0.0", "0.0.0.0", "255.255.255.255");
	test("10.25.30.40", "255.252.0.0", "10.24.0.0", "10.27.255.255");

	return 0;
}
