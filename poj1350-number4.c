#include <stdio.h>
#include <string.h>

int n;
char num[10], big[10], small[10];

int
cmp_small(const void *x, const void *y)
{
	return *(char *)x - *(char *)y;
}

int
cmp_big(const void *x, const void *y)
{
	return *(char *)y - *(char *)x;
}

int
main()
{
	int i, j;

	while (scanf("%d", &n), n != -1)
	{
		printf("N=%d:\n", n);
		sprintf(num, "%d", n);

		int flag = 1;
		for (i = 1; i < 4; i++) flag *= (num[i - 1] == num[i]);
		if (strlen(num) != 4 || flag)
		{
			printf("No!!\n");
			continue;
		}

		for (i = 1; ; i++)
		{
			int t1, t2;

			t1 = 0;
			strcpy(big, num);
			qsort(big, strlen(big), sizeof(char), cmp_big);
			for (j = 0; j < strlen(big); j++) t1 = 10 * t1 + big[j] - '0';

			t2 = 0;
			strcpy(small, num);
			qsort(small, strlen(small), sizeof(char), cmp_small);
			for (j = 0; j < strlen(small); j++) t2 = 10 * t2 + small[j] - '0';

			printf("%d-%d=%d\n", t1, t2, t1 - t2);
			if (t1 == t2 || t1 - t2 == 6174) break;

			sprintf(num, "%d", t1 - t2);
		}
		printf("Ok!! %d times\n", i);
	}

	return 0;
}
