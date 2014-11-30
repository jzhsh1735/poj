#include <stdio.h>

int n, b;
int height[20000];

int
compare(const void *x, const void *y)
{
	return *(int *)y - *(int *)x;
}

int
main()
{
	int i;

	scanf("%d %d", &n, &b);
	for (i = 0; i < n; i++) scanf("%d", &height[i]);

	qsort(height, n, sizeof(int), compare);
	i = 0;
	while (b > 0)
	{
		b -= height[i];
		i++;
	}

	printf("%d\n", i);

	return 0;
}
