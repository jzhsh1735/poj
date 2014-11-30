#include <stdio.h>

int t, n, k;
int num[1024];

int
next()
{
	int p, q, temp;

	p = q = n - 1;
	while (p >= 0 && (p == n - 1 || num[p] >= num[p + 1])) p--;
	if (p < 0)
	{
		p = 0;
		q = n - 1;
		while (p < q)
		{
			temp = num[p];
			num[p] = num[q];
			num[q] = temp;
			p++;
			q--;
		}
		return 0;
	}

	while (num[p] >= num[q]) q--;
	temp = num[p];
	num[p] = num[q];
	num[q] = temp;

	p++;
	q = n - 1;
	while (p < q)
	{
		temp = num[p];
		num[p] = num[q];
		num[q] = temp;
		p++;
		q--;
	}
	return 1;
}

int
main()
{
	int i;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) scanf("%d", &num[i]);

		for (i = 0; i < k; i++) next();

		for (i = 0; i < n; i++) printf("%d ", num[i]);
		printf("\n");
	}

	return 0;
}
