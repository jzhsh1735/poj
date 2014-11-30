#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct sect
{
	double begin, end;
};

int n, d;
int x[1000], y[1000];
struct sect s[1000];
int ans;

int
compare(const void *x, const void *y)
{
	if (((struct sect *)x)->begin < ((struct sect *)y)->begin ||
		((struct sect *)x)->begin == ((struct sect *)y)->begin &&
		((struct sect *)x)->end < ((struct sect *)y)->end) return -1;
	else return 1;
}

int
main()
{
	int i, j;
	double pos;

	i = 0;
	while (scanf("%d %d", &n, &d) != EOF)
	{
		if (n == 0 && d == 0) break;
		ans = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d %d", &x[j], &y[j]);
			if (d < abs(y[j])) ans = -1;
		}
		if (ans == -1)
		{
			i++;
			printf("Case %d: %d\n", i, ans);
			continue;
		}
		for (j = 0; j < n; j++)
		{
			s[j].begin = x[j] - sqrt(d * d - y[j] * y[j]);
			s[j].end = x[j] + sqrt(d * d - y[j] * y[j]);
		}
		qsort(s, n, sizeof(struct sect), compare);
		pos = s[0].end;
		for (j = 1; j < n; j++)
		{
			if (s[j].begin <= pos)
			{
				if (s[j].end < pos) pos = s[j].end;
			}
			else
			{
				ans++;
				pos = s[j].end;
			}
		}
		ans++;
		i++;
		printf("Case %d: %d\n", i, ans);
	}

	return 0;
}
