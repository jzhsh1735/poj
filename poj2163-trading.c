#include <stdio.h>

int m, n, k;
double price[10000];
double pm, pn;
int last;

int
main()
{
	int i;

	scanf("%d %d %d", &m, &n, &k);
	for (i = 0; i < k; i++) scanf("%lf", &price[i]);

	pm = 0;
	for (i = 0; i < m; i++) pm += price[n - 1 - i];
	pn = 0;
	for (i = 0; i < n; i++) pn += price[n - 1 - i];
	for (i = n - 1; i < k; i++)
	{
		if (pm / m > pn / n)
		{
			if (i == n - 1 || last == -1) printf("BUY ON DAY %d\n", i + 1);
			last = 1;
		}
		else
		{
			if (i == n - 1 || last == 1) printf("SELL ON DAY %d\n", i + 1);
			last = -1;
		}
		if (i != k - 1)
		{
			pm += price[i + 1] - price[i - m + 1];
			pn += price[i + 1] - price[i - n + 1];
		}
	}

	return 0;
}
