#include <stdio.h>
#include <math.h>

#define ZERO 1e-8

double b, n;

int
main()
{
	//while (scanf("%lf %lf", &b, &n), fabs(b) > ZERO && fabs(n) > ZERO)
	while (scanf("%lf %lf", &b, &n) != EOF)
	{
		if (fabs(b) < ZERO && fabs(n) < ZERO) break;

		int temp = (int)pow(b, 1 / n);

		if (b - pow(temp, n) < pow(temp + 1, n) - b) printf("%d\n", temp);
		else printf("%d\n", temp + 1);
	}

	return 0;
}
