/*

The reference implementation of CRC32 computes a lookup table at runtime:

unsigned long crc_table[256];

int crc_table_computed = 0;

void make_crc_table(void)
{
    unsigned long c;

    int n, k;
    for (n = 0; n < 256; n++) {
        c = (unsigned long) n;
        for (k = 0; k < 8; k++) {
            if (c & 1) {
                c = 0xedb88320L ^ (c >> 1);
            } else {
                c = c >> 1;
            }
        }
        crc_table[n] = c;
    }
    crc_table_computed = 1;
}

Can you compute the table at compile-time, thus getting rid of the function and the status flag?

*/

#include <cstdio>

struct CRC32
{
	constexpr CRC32()
		: table()
	{
		unsigned long c = 0, n = 0, k = 0;
		for (n = 0; n < 256; n++)
		{
			c = n;
			for (k = 0; k < 8; k++)
			{
				if (c & 1)
					c = 0xedb88320L ^ (c >> 1);
				else
					c = c >> 1;
			}
			table[n] = c;
		}
	}

	unsigned long table[256];
};

const auto crc32 = CRC32();

int main()
{
	for (auto i = 0; i < 256; i++)
	{
		printf("%08lX ", crc32.table[i]);
		if ((i & 7) == 7)
			printf("\n");
	}

	return 0;
}
