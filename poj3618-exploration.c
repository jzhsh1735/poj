#include <stdio.h>
#include <stdlib.h>

int t, n;
int pos[50001];

int
compare(const void *x, const void *y)
{
	return abs(*(int *)x) - abs(*(int *)y);
}

int
main()
{
	int i;

	scanf("%d %d", &t, &n);
	for (i = 0; i < n; i++) scanf("%d", &pos[i]);

	pos[n] = 0;
	n++;
	qsort(pos, n, sizeof(int), compare);
	int ans = 0;
	for (i = 1; i < n; i++)
	{
		t -= abs(pos[i] - pos[i - 1]);
		if (t >= 0) ans++;
		if (t < 0) break;
	}

	printf("%d\n", ans);

	return 0;
}
