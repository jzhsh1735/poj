#include <stdio.h>

int n;
int loc[50000];

int
main()
{
	int i, min, idx;

	scanf("%d", &n);
	loc[0] = 0;
	for (i = 1; i < n; i++) scanf("%d", &loc[i]);

	min = -1;
	for (i = 2; i < n - 1; i++)
	{
		if (min < 0 || loc[i] - loc[i - 1] < min)
		{
			min = loc[i] - loc[i - 1];
			idx = i;
		}
	}
	
	if (n < 4) printf("0\n");
	else printf("%d\n%d %d %d %d\n", loc[n - 1] + min, idx + 1, 1, n, idx);

	return 0;
}
