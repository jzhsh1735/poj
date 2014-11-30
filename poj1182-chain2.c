#include <stdio.h>

int n, k;
int f[100000], r[100000];

int
FIND(int x)
{
	int t;

	if (f[x] == -1) return x;
	else
	{
		t = FIND(f[x]);
		r[x] = (r[x] + r[f[x]]) % 3;
		return f[x] = t;
	}
}

int
UNION(int x, int y, int d)
{
	int fx, fy;

	fx = FIND(x);
	fy = FIND(y);

	if (fx == fy) return ((r[x] - r[y] + 3) % 3 != d - 1);
	else
	{
		f[fx] = fy;
		r[fx] = (r[y] - r[x] + d + 2) % 3;
		return 0;
	}
}

int
main()
{
	int i, d, x, y, ans;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		f[i] = -1;
		r[i] = 0;
	}
	ans = 0;
	for (i = 0; i < k; i++)
	{
		scanf("%d %d %d", &d, &x, &y);
		if (x > n || y > n || d == 2 && x == y)
		{
			ans++;
			continue;
		}
		ans += UNION(x, y, d);
	}
	printf("%d\n", ans);

	return 0;
}
