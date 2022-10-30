#include "lib.h"

void render(int width, int height)
{
	printf("P3\n");
	printf("%d\n%d\n%d\n", width, height, 255);
	for (auto y = height - 1; y >= 0; y--)
	{
		for (auto x = 0; x < width; x++)
		{
			auto r = x * 1.0 / (width - 1);
			auto g = y * 1.0 / (height - 1);
			auto b = 0.25;

			r = clamp(r * 256, 0, 255);
			g = clamp(g * 256, 0, 255);
			b = clamp(b * 256, 0, 255);
			printf("%.f %.f %.f\n", r, g, b);
		}
	}
}

int main()
{
	render(512, 512);
	return 0;
}