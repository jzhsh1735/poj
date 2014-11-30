#include <stdio.h>

int t, n;
char team[100];
int score;

int
main()
{
	while (scanf("%d %d", &t, &n) != EOF)
	{
		if (t == 0 && n == 0) break;

		n *= 3;
		while (t--)
		{
			scanf("%s %d", team, &score);
			n -= score;
		}
		printf("%d\n", n);
	}

	return 0;
}
