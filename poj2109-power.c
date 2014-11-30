#include <stdio.h>
#include <math.h>

double n, p, k;

int
main()
{
	while (scanf("%lf %lf", &n, &p) != EOF)
	{
		k = pow(p, 1 / n);
		printf("%.0f\n", k);
	}

	return 0;
}
