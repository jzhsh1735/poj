#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int n;
double r;
double x[100], y[100];

int
main()
{
	int i;

	scanf("%d %lf", &n, &r);
	for (i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
	x[n] = x[0];
	y[n] = y[0];

	double ans = 2 * PI * r;
	for (i = 0; i < n; i++) ans += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
	printf("%.2f\n", ans);

	return 0;
}
