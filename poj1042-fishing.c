#include <stdio.h>

int n, t;
int f[100], d[100], w[100];

int tt, tr;
int tf[100], tl[100];

int r;
int l[100];
int flag;

int
compare()
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (tl[i] > l[i]) return 1;
		if (tl[i] < l[i]) return 0;
	}

	return 0;
}

int
main()
{
	int i, j;
	int tmax, tidx;

	flag = 0;
	while (scanf("%d", &n), n)
	{
		scanf("%d", &t);
		t *= 60;
		for (i = 0; i < n; i++) scanf("%d", &f[i]);
		for (i = 0; i < n; i++) scanf("%d", &d[i]);
		for (i = 0; i < n - 1; i++)
		{
			scanf("%d", &w[i]);
			w[i] *= 5;
		}

		r = 0;
		for (i = 0; i < n; i++) l[i] = 0;
		for (i = 0; i < n; i++)
		{
			tt = t;
			for (j = 0; j < i; j++) tt -= w[j];
			tr = 0;
			for (j = 0; j <= i; j++) tf[j] = f[j];
			for (j = 0; j < n; j++) tl[j] = 0;
			while (tt >= 5)
			{
				tmax = tf[0];
				tidx = 0;
				for (j = 1; j <= i; j++)
				{
					if (tmax < tf[j])
					{
						tmax = tf[j];
						tidx = j;
					}
				}
				if (tmax > 0)
				{
					tt -= 5;
					tr += tmax;
					tf[tidx] -= d[tidx];
					tl[tidx] += 5;
				}
				else break;
			}
			while (tt >= 5)
			{
				tt -= 5;
				tl[0] += 5;
			}
			if (tr > r || tr == r && compare())
			{
				r = tr;
				for (j = 0; j < n; j++) l[j] = tl[j];
			}
		}
		if (flag == 0)
		{
			printf("%d", l[0]);
			flag = 1;
		}
		else printf("\n%d", l[0]);
		for (i = 1; i < n; i++) printf(", %d", l[i]);
		printf("\nNumber of fish expected: %d\n", r);
	}

	return 0;
}
