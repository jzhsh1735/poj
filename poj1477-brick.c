#include <stdio.h>

int n;
int h[100];

int
main()
{
	int i, j;

	j = 0;
	while (scanf("%d", &n), n)
	{
		int temp = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &h[i]);
			temp += h[i];
		}
		temp /= n;

		int ans = 0;
		for (i = 0; i < n; i++)
		{
			if (h[i] > temp) ans += h[i] - temp;
		}
		j++;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", j, ans);
	}

	return 0;
}
