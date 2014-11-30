#include <stdio.h>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int t, a, b, n, m;
int x[100], y[100], d[100];
int house[100][100];
int flag;

int
main()
{
	int i, j, k;
	char c;
	int idx, move;

	scanf("%d", &t);
	while (t--)
	{
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++) house[i][j] = -1;
		}
		scanf("%d %d", &a, &b);
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d %c", &x[i], &y[i], &c);
			x[i]--;
			y[i]--;
			house[x[i]][y[i]] = i;
			if (c == 'N') d[i] = 0;
			else if (c == 'E') d[i] = 1;
			else if (c == 'S') d[i] = 2;
			else if (c == 'W') d[i] = 3;
		}
		flag = 1;
		for (i = 0; i < m; i++)
		{
			scanf("%d %c %d", &idx, &c, &move);
			if (flag == 0) continue;
			if (c == 'L')
			{
				d[idx - 1] += 4 - move % 4;
				d[idx - 1] %= 4;
			}
			else if (c == 'R')
			{
				d[idx - 1] += move;
				d[idx - 1] %= 4;
			}
			else if (c == 'F')
			{
				int tx, ty;
				for (j = 1; j <= move && flag; j++)
				{
					tx = x[idx - 1] + dx[d[idx - 1]] * j;
					ty = y[idx - 1] + dy[d[idx - 1]] * j;
					if (tx < 0 || ty < 0 || tx >= a || ty >= b) break;
					k = house[tx][ty];
					if (k >= 0)
					{
						printf("Robot %d crashes into robot %d\n", idx, k + 1);
						flag = 0;
					}
				}
				tx = x[idx - 1] + dx[d[idx - 1]] * move;
				ty = y[idx - 1] + dy[d[idx - 1]] * move;
				if (flag)
				{
					if (tx < 0 || ty < 0 || tx >= a || ty >= b)
					{
						printf("Robot %d crashes into the wall\n", idx);
						flag = 0;
					}
					else
					{
						house[x[idx - 1]][y[idx - 1]] = -1;
						house[tx][ty] = idx - 1;
						x[idx - 1] = tx;
						y[idx - 1] = ty;
					}
				}
			}
		}
		if (flag == 1) printf("OK\n");
	}

	return 0;
}
