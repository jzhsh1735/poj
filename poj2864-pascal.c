#include <stdio.h>

int n, d;
int x[500][500];

int
main()
{
	int i, j;
	int temp;

	while (scanf("%d %d", &n, &d) != EOF)
	{
		if (n == 0 && d == 0) break;
		for (i = 0; i < d; i++)
		{
			for (j = 0; j < n; j++) scanf("%d", &x[i][j]);
		}
		for (i = 0; i < n; i++)
		{
			temp = 0;
			for (j = 0; j < d; j++) temp += x[j][i];
			if (temp == d)
			{
				printf("yes\n");
				break;
			}
		}
		if (i == n) printf("no\n");
	}

	return 0;
}
