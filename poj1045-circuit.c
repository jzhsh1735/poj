#include <stdio.h>
#include <math.h>

int
main()
{
	int n;
	double v, r, c, w;

	scanf("%lf %lf %lf %d", &v, &r, &c, &n);
	while (n--)
	{
		scanf("%lf", &w);
		printf("%.3f\n", v * c * r * w / sqrt(1 + c * c * r * r * w * w));
	}

	return 0;
}
