#include <stdio.h>

long long a;

int
main()
{
	long long i;

	scanf("%lld", &a);
	for (i = a; ; i--)
	{
		if ((a * a + 1) % i == 0) break;
	}
	printf("%lld\n", 2 * a + i + (a * a + 1) / i);

	return 0;
}
