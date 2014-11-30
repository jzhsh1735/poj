#include <stdio.h>

int n, d;
int x[2000], y[2000];

int len[2000];
int c[2000][2000];
int state[2000];

int f[2000];

int
FIND(int x)
{
	if (f[x] == -1) return x;
	else return f[x] = FIND(f[x]);
}

void
UNION(int x, int y)
{
	int fx, fy;
	fx = FIND(x);
	fy = FIND(y);
	if (fx != fy) f[fx] = fy;
}

int
main()
{
	int i, j, p, q;
	char oper[10];

	scanf("%d %d", &n, &d);
	for (i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
	for (i = 1; i <= n; i++)
	{
		len[i] = state[i] = 0;
		f[i] = -1;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d)
			{
				c[i][len[i]] = j;
				len[i]++;
				c[j][len[j]] = i;
				len[j]++;
			}
		}
	}

	while (scanf("%s", oper) != EOF)
	{
		if (oper[0] == 'O')
		{
			scanf("%d", &p);
			state[p] = 1;
			for (i = 0; i < len[p]; i++)
			{
				if (state[c[p][i]]) UNION(p, c[p][i]);
			}
		}
		if (oper[0] == 'S')
		{
			scanf("%d %d", &p, &q);
			if (FIND(p) == FIND(q)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}

	return 0;
}
