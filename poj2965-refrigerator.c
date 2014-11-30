#include <stdio.h>

char handle[10][10];
int flag[10][10];
int ans;

int
main()
{
	int i, j, k;

	for (i = 0; i < 4; i++) scanf("%s", handle[i]);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++) flag[i][j] = 0;
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (handle[i][j] == '+')
			{
				for (k = 0; k < 4; k++)
				{
					flag[i][k]++;
					flag[k][j]++;
				}
				flag[i][j]++;
			}
		}
	}
	ans = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (flag[i][j] % 2 == 1) ans++;
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (flag[i][j] % 2 == 1) printf("%d %d\n", i + 1, j + 1);
		}
	}

	return 0;
}
