#include <stdio.h>
#include <stdlib.h>

int n, s;
int num[20000];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i, j;

	scanf("%d %d", &n, &s);
	for (i = 0; i < n; i++) scanf("%d", &num[i]);

	qsort(num, n, sizeof(int), compare);
	int ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (num[i] + num[j] <= s) ans++;
			else break;
		}
	}
	printf("%d\n", ans);

	return 0;
}
