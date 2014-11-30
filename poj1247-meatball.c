#include <stdio.h>

int n;
int ball[100];
int sam, ella;

int
main()
{
	int i, j;

	while (scanf("%d", &n), n)
	{
		for (i = 0; i < n; i++) scanf("%d", &ball[i]);

		i = -1;
		j = n;
		sam = ella = 0;

		while (i + 1 != j)
		{
			if (sam < ella)
			{
				i++;
				sam += ball[i];
			}
			else
			{
				j--;
				ella += ball[j];
			}
		}

		if (sam == ella)
		{
			printf("Sam stops at position %d and Ella stops at position %d.\n", i + 1, j + 1);
		}
		else
		{
			printf("No equal partitioning.\n");
		}
	}

	return 0;
}
