/*

Implement the following JavaScript method as short as possible:

function same_subnet(ip_a,ip_b,sn_mask)
{

}
It should get 2 IP addresses and a subnet mask. It should return true if ip_a and ip_b are in the same subnet.

Example calls:

same_subnet("192.168.0.1","192.168.0.15","255.255.255.0") → true
same_subnet("192.168.0.1","192.168.1.15","255.255.0.0") → true
same_subnet("192.168.0.1","192.168.1.15","255.255.255.0") → false

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

uint32_t
ipv4(const char *s)
{
	uint32_t r;
	unsigned v[4];
	int i;

	if (sscanf(s, "%u.%u.%u.%u", &v[0], &v[1], &v[2], &v[3]) != 4)
		return 0;

	r = 0;
	for (i = 0; i < 4; i++)
		r = (r << 8) | v[i];
	return r;
}

bool
subnet(const char *a, const char *b, const char *s)
{
	uint32_t x, y, m;

	x = ipv4(a);
	y = ipv4(b);
	m = ipv4(s);
	return (x & m) == (y & m);
}

int
main(void)
{
	assert(subnet("192.168.0.1", "192.168.0.15", "255.255.255.0") == true);
	assert(subnet("192.168.0.1", "192.168.1.15", "255.255.0.0") == true);
	assert(subnet("192.168.0.1", "192.168.1.15", "255.255.255.0") == false);

	assert(subnet("10.192.0.33", "10.192.0.175", "255.255.255.0") == true);
	assert(subnet("10.192.0.33", "192.168.1.175", "255.255.255.0") == false);
	assert(subnet("10.192.0.33", "10.192.16.175", "255.255.0.0") == true);
	assert(subnet("10.192.0.175", "10.192.2.175", "255.255.252.0") == true);

	return 0;
}
