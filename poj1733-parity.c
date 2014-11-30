#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int a[5000], b[5000], c[5000];
int h[20000], f[20000], r[20000];
char ans[10];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
find(int x, int l, int r)
{
	int m = (l + r) / 2;

	if (l == r) return l;

	if (h[m] < x) return find(x, m + 1, r);
	else return find(x, l, m);
}

int
FIND(int x)
{
	int fx;

	if (f[x] == -1) return x;
	else
	{
		fx = FIND(f[x]);
		r[x] = (r[x] + r[f[x]]) % 2;

		return f[x] = fx;
	}
}

int
UNION(int x, int y, int d)
{
	int fx, fy;

	fx = FIND(x);
	fy = FIND(y);
	if (fx == fy) return ((r[x] + r[y]) % 2 == d? 0: 1);
	else
	{
		f[fy] = fx;
		r[fy] = (r[x] + r[y] + d) % 2;

		return 0;
	}
}

int
main()
{
	int i;

	scanf("%d %d", &n, &m);
	n = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %s", &a[i], &b[i], ans);
		c[i] = (strcmp(ans, "even") == 0? 0: 1);
		h[n++] = a[i] - 1;
		h[n++] = b[i];
	}
	qsort(h, n, sizeof(int), compare);
	for (i = 0; i < n; i++)
	{
		f[i] = -1;
		r[i] = 0;
	}
	for (i = 0; i < m; i++)
	{
		if (UNION(find(a[i] - 1, 0, n - 1), find(b[i], 0, n - 1), c[i])) break;
	}
	printf("%d\n", i);

	return 0;
}
