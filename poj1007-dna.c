#include <stdio.h>

char dna[100][100];
int score[100];
int flag[100];

int
main()
{
	int l, n;
	scanf("%d %d\n", &l, &n);

	int i, j, k;
	for (i = 0; i < n; i++)
	{
		scanf("%s", dna[i]);
	}

	for (i = 0; i < n; i++)
	{
		score[i] = 0;
		for (j = 0; j < l; j++)
		{
			for (k = j + 1; k < l; k++)
			{
				if (dna[i][j] > dna[i][k]) score[i]++;
			}
		}
	}

	int index, min;
	for (i = 0; i < n; i++)
	{
		index = -1;
		for (j = 0; j < n; j++)
		{
			if (flag[j] == 1) continue;

			if (index < 0 || min > score[j])
			{
				index = j;
				min = score[j];
			}
		}
		flag[index] = 1;
		printf("%s\n", dna[index]);
	}

	return 0;
}
