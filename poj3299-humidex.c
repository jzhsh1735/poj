#include <stdio.h>
#include <math.h>

double t, d, h;
char key[2][10];
double value[2];

int
main()
{
	double temp1, temp2;

	while (scanf("%s", key[0]), key[0][0] != 'E')
	{
		scanf("%lf %s %lf", &value[0], key[1], &value[1]);
		if (key[0][0] == 'T' && key[1][0] == 'D')
		{
			t = value[0]; d = value[1];
			temp1 = 6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16)));
			temp2 = 0.5555 * (temp1 - 10.0);
			h = t + temp2;
		}
		if (key[0][0] == 'D' && key[1][0] == 'T')
		{
			d = value[0]; t = value[1];
			temp1 = 6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16)));
			temp2 = 0.5555 * (temp1 - 10.0);
			h = t + temp2;
		}
		if (key[0][0] == 'T' && key[1][0] == 'H')
		{
			t = value[0]; h = value[1];
			temp1 = h - t;
			temp2 = temp1 / 0.5555 + 10.0;
			d = 1 / (1 / 273.16 - log(temp2 / 6.11) / 5417.7530) - 273.16;
		}
		if (key[0][0] == 'H' && key[1][0] == 'T')
		{
			h = value[0]; t = value[1];
			temp1 = h - t;
			temp2 = temp1 / 0.5555 + 10.0;
			d = 1 / (1 / 273.16 - log(temp2 / 6.11) / 5417.7530) - 273.16;
		}
		if (key[0][0] == 'H' && key[1][0] == 'D')
		{
			h = value[0]; d = value[1];
			temp1 = 6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16)));
			temp2 = 0.5555 * (temp1 - 10.0);
			t = h - temp2;
		}
		if (key[0][0] == 'D' && key[1][0] == 'H')
		{
			d = value[0]; h = value[1];
			temp1 = 6.11 * exp(5417.7530 * (1 / 273.16 - 1 / (d + 273.16)));
			temp2 = 0.5555 * (temp1 - 10.0);
			t = h - temp2;
		}

		printf("T %.1f D %.1f H %.1f\n", t, d, h);
	}

	return 0;
}
