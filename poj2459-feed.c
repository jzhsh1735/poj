#include <stdio.h>

int c, f1, f2, d;
int cost[2000];

int
main()
{
	int i, j, begin, end;

	scanf("%d %d %d %d", &c, &f1, &f2, &d);
	for (i = 0; i < d; i++) cost[i] = 0;
	for (i = 0; i < c; i++)
	{
		scanf("%d %d", &begin, &end);
		for (j = begin; j <= end && j <= d; j++) cost[j - 1]++;
	}
	
	j = 0;
	for (i = d - 1; i >= 0; i--)
	{
		if (j >= f1 - f2) break;
		j += cost[i];
	}
	printf("%d\n", i + 2);

	return 0;
}
