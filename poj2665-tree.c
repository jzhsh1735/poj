#include <stdio.h>

long long l;
int m;
long long start, end;

int
main()
{
	while (scanf("%lld %d", &l, &m) != EOF)
	{
		if (l == 0 && m == 0) break;
		while (m--)
		{
			scanf("%lld %lld", &start, &end);
			l -= end - start + 1;
		}
		printf("%lld\n", l + 1);
	}

	return 0;
}
