#include <stdio.h>

int n, p;
int simple[100];
int score[100];

int
main()
{
	int i, j, max, min, flag;

	scanf("%d %d", &n, &p);
	for (i = 0; i < p; i++) simple[i] = 0;
	for (i = 0; i < n; i++)
	{
		max = min = -1;
		for (j = 0; j < p; j++)
		{
			scanf("%d", &score[j]);
			if (max == -1 || score[j] > max) max = score[j];
			if (min == -1 || score[j] < min) min = score[j];
		}
		for (j = 0; j < p; j++)
		{
			if (max == score[j]) simple[j] = -1;
			if (min == score[j] && simple[j] >= 0) simple[j]++;
		}
	}

	flag = 0;
	for (i = 0; i < p; i++)
	{
		if (2 * simple[i] > n)
		{
			if (flag == 0)
			{
				flag = 1;
				printf("%d", i + 1);
			}
			else printf(" %d", i + 1);
		}
	}
	if (flag == 0) printf("0");
	printf("\n");

	return 0;
}
