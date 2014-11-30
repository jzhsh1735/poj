#include <stdio.h>

#define PI 3.1415926

int
main()
{
	int i, j, n;
	double x, y;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf %lf\n", &x, &y);
		j = (int)(PI * (x * x + y * y) / 2 / 50) + 1;
		printf("Property %d: This property will begin eroding in year %d.\n", i + 1, j);
	}
	printf("END OF OUTPUT.\n");

	return 0;
}
