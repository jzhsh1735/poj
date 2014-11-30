#include <stdio.h>

int n;
int seq[3000];

int
main()
{
	int i, j, flag;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%d", &seq[i]);
		for (i = 0; i < n - 1; i++) seq[i] = abs(seq[i] - seq[i + 1]);

		flag = 0;
		for (i = 0; i < n - 1 && flag == 0; i++)
		{
			flag = 1;
			for (j = 0; j < n - 1; j++)
			{
				if (seq[j] == i + 1)
				{
					flag = 0;
					break;
				}
			}
		}

		if (flag == 0) printf("Jolly\n");
		else printf("Not jolly\n");
	}

	return 0;
}
