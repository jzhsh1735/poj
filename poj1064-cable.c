#include <stdio.h>

int n, k;
int len[10000];
int max, flag;

int
cable(int l)
{
	int i, j;

	j = 0;
	for (i = 0; i < n; i++) j += len[i] / l;

	return (j >= k);
}

int
main()
{
	int i, j;
	double t;

	max = flag = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &t);
		len[i] = 100 * t;
		if (len[i] > max) max = len[i];
	}
	i = 1; j = max;
	while (i < j)
	{
		if (cable((i + j) / 2 + 1))
		{
			i = (i + j) / 2 + 1;
			flag = 1;
		}
		else j = (i + j) / 2;
	}
	if (flag) printf("%d.%02d\n", i / 100, i % 100);
	else printf("0.00\n");

	return 0;
}
