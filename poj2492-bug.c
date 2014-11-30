#include <stdio.h>

int t, n, m;
int f[10000], r[10000];

int
FIND(int x)
{
	int t;

	if (f[x] == -1) return x;
	else
	{
		t = FIND(f[x]);
		r[x] = (r[x] == r[f[x]]? 1: 0);
		return f[x] = t;
	}
}

void
UNION(int x, int y)
{
	int fx, fy;

	fx = FIND(x);
	fy = FIND(y);
	if (fx == fy) return;
	f[fx] = fy;
	r[fx] = (r[x] == r[y]? 0: 1);
}

int
main()
{
	int i, j, x, y, ans;

	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d %d", &n, &m);
		for (j = 1; j <= n; j++)
		{
			f[j] = -1;
			r[j] = 1;
		}
		ans = 0;
		while (m--)
		{
			scanf("%d %d", &x, &y);
			if (FIND(x) == FIND(y))
			{
				if (r[x] == r[y]) ans = 1;
			}
			else UNION(x, y);
		}
		printf("Scenario #%d:\n", i);
		if (ans) printf("Suspicious bugs found!\n\n");
		else printf("No suspicious bugs found!\n\n");
	}

	return 0;
}
