#include <stdio.h>

int t;
long long n, m;

int
main()
{
	int i;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%lld %lld", &n, &m);
		printf("Scenario #%d:\n", i + 1);
		printf("%lld\n\n", (n + m) * (m - n + 1) / 2);
	}

	return 0;
}
