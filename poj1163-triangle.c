#include <stdio.h>

int n;
int triangle[100][100];
int result[100][100];

int
max(int x, int y)
{
	return x > y? x:y;
}

int
main()
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			scanf("%d", &triangle[i][j]);
		}
	}

	result[0][0] = triangle[0][0];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0) result[i][j] = result[i - 1][j] + triangle[i][j];
			else if (j == i) result[i][j] = result[i - 1][j - 1] + triangle[i][j];
			else result[i][j] = max(result[i - 1][j - 1], result[i - 1][j]) + triangle[i][j];
		}
	}

	int ans = -1;
	for (i = 0; i < n; i++)
	{
		if (ans < 0 || result[n - 1][i] > ans) ans = result[n - 1][i];
	}
	printf("%d\n", ans);

	return 0;
}
