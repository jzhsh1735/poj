#include <stdio.h>

int n;
int cow[30000];
int dp[30000];

int
find(int l, int r, int v)
{
	if (l == r) return l;

	int m = (l + r) / 2;
	if (dp[m] > v) return find(l, m, v);
	else return find(m + 1, r, v);
}

int
main()
{
	int i, len;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &cow[i]);

	len = 0;
	dp[0] = 1;
	for (i = 0; i < n; i++)
	{
		if (cow[i] >= dp[len])
		{
			len++;
			dp[len] = cow[i];
		}
		else
		{
			int index = find(0, len, cow[i]);
			dp[index] = cow[i];
		}
	}

	printf("%d\n", n - len);

	return 0;
}
