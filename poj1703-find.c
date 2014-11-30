#include <stdio.h>

int t, n, m;
int f[100001], r[100001];

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
	int i;

	char s[10];
	int x, y;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			f[i] = -1;
			r[i] = 1;
		}
		while (m--)
		{
			scanf("%s%d%d", s, &x, &y);
			if (s[0] == 'A')
			{
				if (FIND(x) == FIND(y))
				{
					if (r[x] == r[y]) printf("In the same gang.\n");
					else printf("In different gangs.\n");
				}
				else printf("Not sure yet.\n");
			}
			if (s[0] == 'D') UNION(x, y);
		}
	}

	return 0;
}
