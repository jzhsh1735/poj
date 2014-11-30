#include <stdio.h>

int t, n, m;
char matrix[100][100];

int
mark(int x, int y, int dx, int dy, char c)
{
	while (x < n && y < m)
	{
		if (matrix[x][y] == c)
		{
			matrix[x][y] = '.';
			x += dx;
			y += dy;
		}
		else break;
	}

	return 1;
}

int
main()
{
	int i, j;
	int flag;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) scanf("%s", matrix[i]);

		flag = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (matrix[i][j] == '-') flag += mark(i, j, 0, 1, '-');
				else if (matrix[i][j] == '|') flag += mark(i, j, 1, 0, '|');
				else if (matrix[i][j] == '/') flag += mark(i, j, 1, -1, '/');
				else if (matrix[i][j] == '\\') flag += mark(i, j, 1, 1, '\\');
			}
		}
		if (flag == 1) printf("CORRECT\n");
		else printf("INCORRECT\n");
	}

	return 0;
}
