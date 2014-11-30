#include <stdio.h>

int n;
double x[5000];
double y[5000];

int
main()
{
	int i;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
		x[n] = x[0];
		y[n] = y[0];

		printf("%d", n);
		for (i = 0; i < n; i++) printf(" %.6f %.6f", (x[i] + x[i + 1]) / 2, (y[i] + y[i + 1]) / 2);
		printf("\n");
	}

	return 0;
}
