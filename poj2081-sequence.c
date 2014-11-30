#include <stdio.h>

int k;
int a[500001];
int flag[5000000];

int
main()
{
	int i;

	for (i = 0; i < 5000000; i++) flag[i] = 0;

	a[0] = 0;
	flag[0] = 1;
	for (i = 1; i <= 500000; i++)
	{
		if (a[i - 1] - i > 0 && flag[a[i - 1] - i] == 0) a[i] = a[i - 1] - i;
		else a[i] = a[i - 1] + i;

		flag[a[i]] = 1;
	}

	while (scanf("%d", &k), k != -1)
	{
		printf("%d\n", a[k]);
	}

	return 0;
}
