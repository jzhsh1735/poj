#include <stdio.h>

int t;
int f[50000], d[50000], n[50000];
char oper[10];

int
FIND(int x)
{
	int fx;

	if (f[x] == -1) return x;
	else
	{
		fx = FIND(f[x]);
		d[x] += d[f[x]];
		return f[x] = fx;
	}
}

void
UNION(int x, int y)
{
	int fx, fy;

	fx = FIND(x);
	fy = FIND(y);
	f[fy] = fx;
	d[fy] = n[fx];
	n[fx] += n[fy];
}

int
COUNT(int x)
{
	int fx = FIND(x);

	return n[fx] - d[x] - 1;
}

int
main()
{
	int i, x, y;

	for (i = 0; i < 50000; i++)
	{
		f[i] = -1;
		d[i] = 0;
		n[i] = 1;
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", oper);
		if (oper[0] == 'M')
		{
			scanf("%d %d", &x, &y);
			UNION(x, y);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", COUNT(x));
		}
	}

	return 0;
}
