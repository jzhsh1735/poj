#include <stdio.h>
#include <stdlib.h>

int n;
int x[10000], y[10000];
int ans;

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

	qsort(x, n, sizeof(int), compare);
	qsort(y, n, sizeof(int), compare);
	for (i = 0; i < n; i++) x[i] -= i;
	qsort(x, n, sizeof(int), compare);

	ans = 0;
	for (i = 0; i < n / 2; i++) ans += x[n - 1 - i] - x[i] + y[n - 1 - i] - y[i];
	printf("%d\n", ans);

	return 0;
}
