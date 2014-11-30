#include <stdio.h>
#include <math.h>

int n, b, k, r, c;
int farm[256][256];
int dpmax[256][256][8][8];
int dpmin[256][256][8][8];

int
max(int x, int y)
{
	return x > y? x: y;
}

int
min(int x, int y)
{
	return x > y? y: x;
}

int
main()
{
	int i, j, p, q;

	scanf("%d %d %d", &n, &b, &k);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &farm[i][j]);
			dpmax[i][j][0][0] = dpmin[i][j][0][0] = farm[i][j];
		}
	}

	for (p = 0; (1 << p) < n; p++)
	{
		for (q = 0; (1 << q) < n; q++)
		{
			if (p == 0 && q == 0) continue;
			for (i = 1; i + (1 << p) - 1 <= n; i++)
			{
				for (j = 1; j + (1 << q) - 1 <= n; j++)
				{
					if (p == 0)
					{
						dpmax[i][j][p][q] = max(dpmax[i][j][p][q - 1], dpmax[i][j + (1 << (q - 1))][p][q - 1]);
						dpmin[i][j][p][q] = min(dpmin[i][j][p][q - 1], dpmin[i][j + (1 << (q - 1))][p][q - 1]);
					}
					else
					{
						dpmax[i][j][p][q] = max(dpmax[i][j][p - 1][q], dpmax[i + (1 << (p - 1))][j][p - 1][q]);
						dpmin[i][j][p][q] = min(dpmin[i][j][p - 1][q], dpmin[i + (1 << (p - 1))][j][p - 1][q]);
					}
				}
			}
		}
	}

	i = log((double)b) / log(2.0);
	for (j = 0; j < k; j++)
	{
		scanf("%d %d", &r, &c);
		printf("%d\n", max(max(max(
				dpmax[r][c][i][i],
				dpmax[r][c + b - (1 << i)][i][i]),
				dpmax[r + b - (1 << i)][c][i][i]),
				dpmax[r + b - (1 << i)][c + b - (1 << i)][i][i])
			- min(min(min(
				dpmin[r][c][i][i],
				dpmin[r][c + b - (1 << i)][i][i]),
				dpmin[r + b - (1 << i)][c][i][i]),
				dpmin[r + b - (1 << i)][c + b - (1 << i)][i][i]));
	}
	
	return 0;
}
