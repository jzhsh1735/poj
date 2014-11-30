#include <stdio.h>
#include <stdlib.h>

int t, n;
int c[1000];
int ans;

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &c[i]);

		qsort(c, n, sizeof(int), compare);
		ans = 0;
		while (n > 3)
		{
			if (c[0] + c[n - 2] < 2 * c[1]) ans += 2 * c[0] + c[n - 1] + c[n - 2];
			else ans += c[0] + 2 * c[1] + c[n - 1];
			n -= 2;
		}
		if (n == 3) ans += c[0] + c[1] + c[2];
		else ans += c[n - 1];
		printf("%d\n", ans);
	}

	return 0;
}
