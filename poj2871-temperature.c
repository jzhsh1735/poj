#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ZERO 1e-8

int
main()
{
	double last, current;

	scanf("%lf", &last);
	while (fabs(last - 999) > ZERO && scanf("%lf", &current), fabs(current - 999) > ZERO)
	{
		printf("%.2f\n", current - last);
		last = current;
	}
	printf("End of Output\n");

	return 0;
}
