#include <stdio.h>
#include <math.h>

#define EPS 1e-6
#define INF 1e30
#define M 1e10

int n, m;
double a[500][1000];
double c[1000];

int main()
{
	int i, j;

	int from, to, val;
	int var, bnd, row, col;
	double max, min, delta;

	while (scanf("%d%d", &n, &m) != EOF)
	{
		var = 2 * n + m - 2;
		bnd = n + m - 2;
		for (i = 0; i <= var; i++) c[i] = 0;
		for (i = 0; i <= bnd; i++)
		{
			for (j = 0; j <= var; j++) a[i][j] = 0;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &from, &to, &val);
			a[i][0] = val;
			a[i][i] = a[i][i + n] = 1;
			if (from == 1) c[i] = -1;
			if (to == 1) c[i] = 1;
			if (from != 1 && from != m) a[n + from - 1][i] = -1;
			if (to != 1 && to != m) a[n + to - 1][i] = 1;
		}
		for (i = 1; i <= m - 2; i++)
		{
			a[n + i][2 * n + i] = 1;
			c[2 * n + i] = M;
		}
		for (i = 0; i <= var; i++)
		{
			for (j = 1; j <= bnd; j++) a[0][i] += c[n + j] * a[j][i];
			a[0][i] -= c[i];
		}
		while (1)
		{
			max = 0; col = 0;
			for (i = 1; i <= var; i++)
			{
				if (a[0][i] > EPS && a[0][i] > max)
				{
					max = a[0][i];
					col = i;
				}
			}
			if (col == 0) break;
			min = INF; row = 0;
			for (i = 1; i <= bnd; i++)
			{
				if (a[i][col] > EPS && a[i][0] / a[i][col] < min)
				{
					min = a[i][0] / a[i][col];
					row = i;
				}
			}
			delta = a[row][col];
			for (i = 0; i <= var; i++) a[row][i] /= delta;
			for (i = 0; i <= bnd; i++)
			{
				if (i != row && fabs(a[i][col]) > EPS)
				{
					delta = a[i][col];
					for (j = 0; j <= var; j++) a[i][j] -= delta * a[row][j];
				}
			}
		}
		printf("%.0f\n", fabs(a[0][0]));
	}

	return 0;
}
