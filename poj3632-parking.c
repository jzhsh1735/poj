#include <stdio.h>
#include <stdlib.h>

int t, n;
int pos[20];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", &pos[i]);
		qsort(pos, n, sizeof(int), compare);
		printf("%d\n", 2 * (pos[n - 1] - pos[0]));
	}

	return 0;
}
