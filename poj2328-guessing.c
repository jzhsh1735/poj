#include <stdio.h>

int n, low, high;
char str[100];

int
min(int x, int y)
{
	return x > y? y: x;
}

int
max(int x, int y)
{
	return x > y? x: y;
}

int
main()
{
	while (scanf("%d", &n), n)
	{
		low = 0;
		high = 11;
		while (getchar(), gets(str), strcmp(str, "right on") != 0)
		{
			if (strcmp(str, "too high") == 0) high = min(high, n);
			else low = max(low, n);

			scanf("%d", &n);
		}

		if (low < n && n < high) printf("Stan may be honest\n");
		else printf("Stan is dishonest\n");
	}

	return 0;
}
