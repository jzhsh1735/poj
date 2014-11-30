#include <stdio.h>

int n, score, ans, max;

int
main()
{
	int i, j;
	int temp;

	scanf("%d", &n);
	max = -1;
	for (i = 0; i < n; i++)
	{
		temp = 0;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &score);
			if (score == 3) temp++;
		}
		if (temp > max)
		{
			ans = i + 1;
			max = temp;
		}
	}
	printf("%d\n", ans);

	return 0;
}
