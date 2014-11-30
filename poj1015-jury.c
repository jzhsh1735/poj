#include <stdio.h>
#include <stdlib.h>

int p[200];
int d[200];

int dp[50][1000];
int path[50][1000];

int res[50];

int
cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int
main()
{
	int n, m;

	int i, j, k, value, index, t1, t2, flag, cnt = 0, psum, dsum;
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;

		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i], &d[i]);
		}

		for (i = 0; i < 50; i++)
		{
			for (j = 0; j < 1000; j++)
			{
				dp[i][j] = path[i][j] = -1;
			}
		}
		dp[0][500] = 0;

		for (i = 1; i <= m; i++)
		{
			for (j = 500 - 20 * i; j <= 500 + 20 * i; j++)
			{
				value = index = -1;
				for (k = 0; k < n; k++)
				{
					if (dp[i - 1][j - p[k] + d[k]] == -1) continue;

					flag = 0;
					t1 = i - 1;
					t2 = j - p[k] + d[k];
					while (path[t1][t2] != -1)
					{
						if (path[t1][t2] == k)
						{
							flag = 1;
							break;
						}
						t2 = t2 - p[path[t1][t2]] + d[path[t1][t2]];
						--t1;
					}
					if (flag == 1) continue;

					if (value == -1 || dp[i - 1][j - p[k] + d[k]] + p[k] + d[k] > value)
					{
						value = dp[i - 1][j - p[k] + d[k]] + p[k] + d[k];
						index = k;
					}
				}
				dp[i][j] = value;
				path[i][j] = index;
			}
		}

		for (i = 0; i <= 20 * m; i++)
		{
			if (dp[m][500 + i] == -1 && dp[m][500 - i] == -1) continue;

			if (dp[m][500 + i] >= dp[m][500 - i])
			{
				t1 = m;
				t2 = 500 + i;
			}
			else
			{
				t1 = m;
				t2 = 500 - i;
			}
			while(path[t1][t2] != -1)
			{
				res[t1 - 1] = path[t1][t2];
				t2 = t2 - p[path[t1][t2]] + d[path[t1][t2]];
				--t1;
			}
			break;
		}
		qsort(res, m, sizeof(int), cmp);

		psum = dsum = 0;
		for (i = 0; i < m; i++)
		{
			psum += p[res[i]];
			dsum += d[res[i]];
		}

		++cnt;
		printf("Jury #%d\n", cnt);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", psum, dsum);
		for (i = 0; i < m; i++)
		{
			printf(" %d", res[i] + 1);
		}
		printf("\n\n");
	}

	return 0;
}
