#include <stdio.h>

long long a, b;

int
main()
{
	int sa = 0, sb = 0;

	scanf("%lld %lld", &a, &b);
	while (a)
	{
		sa += a % 10;
		a /= 10;
	}
	while (b)
	{
		sb += b % 10;
		b /= 10;
	}

	printf("%d\n", sa * sb);

	return 0;
}
