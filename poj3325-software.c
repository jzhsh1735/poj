#include <stdio.h>

int n, s, t, max, min;

int
main()
{
	int i;

	while (scanf("%d", &n), n)
	{
		t = 0;
		max = min = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &s);
			if (max < 0 || max < s) max = s;
			if (min < 0 || min > s) min = s;
			t += s;
		}
		t -= max + min;
		printf("%d\n", t / (n - 2));
	}

	return 0;
}
