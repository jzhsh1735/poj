#include <stdio.h>

int t;
long long n;

int
main()
{
	int i;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		printf("%d %lld %lld\n", i + 1, n, n * (n + 1) * (n + 2) * (n + 3) / 8);
	}

	return 0;
}
