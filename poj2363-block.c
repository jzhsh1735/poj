#include <stdio.h>

int t, n;

int
main()
{
	int i, j;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int ans = -1;
		for (i = 1; i * i * i <= n; i++)
		{
			if (n % i != 0) continue;
			for (j = i; i * j * j <= n; j++)
			{
				if (n % (i * j) != 0) continue;
				if (ans < 0 || ans > 2 * (i * j + n / i + n / j)) ans = 2 * (i * j + n / i + n / j);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
