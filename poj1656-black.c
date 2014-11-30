#include <stdio.h>
#include <string.h>

#define N 100

int t, x, y, l;
int color[101][101];
int sum[101][101];
char cmd[10];

int
lowbit(int x)
{
	return x & (-x);
}

void
update(int x, int y, int c)
{
	int i, j;

	color[x][y] = c;
	for (i = x; i <= N; i += lowbit(i))
	{
		for (j = y; j <= N; j += lowbit(j))
		{
			if (c == 0) sum[i][j]--;
			else sum[i][j]++;
		}
	}
}

int
getsum(int x, int y)
{
	int i, j;

	int result = 0;
	for (i = x; i > 0; i -= lowbit(i))
	{
		for (j = y; j > 0; j -= lowbit(j))
		{
			result += sum[i][j];
		}
	}

	return result;
}

int
main()
{
	int i, j;

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			color[i][j] = 0;
			sum[i][j] = 0;
		}
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", cmd);
		scanf("%d %d %d", &x, &y, &l);
		if (strcmp(cmd, "BLACK") == 0)
		{
			for (i = x; i <= x + l - 1; i++)
			{
				for (j = y; j <= y + l - 1; j++)
				{
					if (color[i][j] == 0) update(i, j, 1);
				}
			}
		}
		else if (strcmp(cmd, "WHITE") == 0)
		{
			for (i = x; i <= x + l - 1; i++)
			{
				for (j = y; j <= y + l - 1; j++)
				{
					if (color[i][j] == 1) update(i, j, 0);
				}
			}
		}
		else
		{
			printf("%d\n", getsum(x + l - 1, y + l - 1) - getsum(x + l - 1, y - 1) - getsum(x - 1, y + l - 1) + getsum(x - 1, y - 1));
		}
	}

	return 0;
}
