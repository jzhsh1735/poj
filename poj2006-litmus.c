#include <stdio.h>
#include <math.h>

#define ZERO 1e-8

double k, o, m, n;
double a, b, c, x;

int
main()
{
	while (scanf("%lf %lf %lf %lf", &k, &o, &m, &n), k + o + m + n > ZERO)
	{
		a = n;
		b = k;
		c = - k * o * m;

		x = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
		printf("%.3f\n", - log(x) / log(10));
	}

	return 0;
}
