#include <stdio.h>

int n;
int num[10];

int
main()
{
	int i;

	scanf("%d", &n);
	while (n--)
	{
		for (i = 0; i < 4; i++) scanf("%d", &num[i]);

		if (num[1] - num[0] == num[2] - num[1] && num[2] - num[1] == num[3] - num[2])
		{
			num[4] = num[3] + num[1] - num[0];
		}
		else
		{
			num[4] = num[3] * num[1] / num[0];
		}

		for (i = 0; i < 5; i++)
		{
			if (i < 4) printf("%d ", num[i]);
			else printf("%d\n", num[i]);
		}
	}

	return 0;
}
