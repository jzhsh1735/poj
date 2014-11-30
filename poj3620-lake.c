#include <stdio.h>

int n, m, k;
int cell[200][200];

int
dfs(int x, int y)
{
	int result = 1;

	cell[x][y] = -1;
	if (x - 1 >= 1 && cell[x - 1][y] == 1) result += dfs(x - 1, y);
	if (y - 1 >= 1 && cell[x][y - 1] == 1) result += dfs(x, y - 1);
	if (x + 1 <= n && cell[x + 1][y] == 1) result += dfs(x + 1, y);
	if (y + 1 <= m && cell[x][y + 1] == 1) result += dfs(x, y + 1);

	return result;
}

int
main()
{
	int i, j, x, y;

	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cell[i][j] = 0;
		}
	}
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &x, &y);
		cell[x][y] = 1;
	}


	int ans = 0, temp;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (cell[i][j] == 1)
			{
				temp = dfs(i, j);
				if (temp > ans) ans = temp;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
