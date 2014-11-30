#include <stdio.h>

double r, m;
int y;

int
main()
{
	int i;

	scanf("%lf %lf %d", &r, &m, &y);
	
	for (i = 0; i < y; i++) m *= 1 + r / 100;
	printf("%d\n", (int)m);

	return 0;
}
