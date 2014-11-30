#include <stdio.h>

int t;
char a[10], b[10];

int
main()
{
	int i, j;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %s", a, b);

		int ans1 = 0, ans2 = 0;
		for (i = 0; i < 4; i++)
		{
			if (a[i] == b[i]) ans1++;
		}
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				if (a[i] == b[j]) ans2++;
			}
		}
		printf("%dA%dB\n", ans1, ans2 - ans1);
	}

	return 0;
}
