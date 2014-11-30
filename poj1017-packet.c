#include <stdio.h>

int num[10];
int box;

int
main()
{
	int i, flag;

	while (1)
	{
		flag = 0;
		for (i = 1; i <= 6; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] > 0) flag = 1;
		}
		if (flag == 0) break;
		
		box = num[6];

		box += num[5];
		num[1] -= num[5] * 11;

		box += num[4];
		num[2] -= num[4] * 5;

		box += num[3] / 4;
		num[3] %= 4;
		if (num[3] == 3)
		{
			box++;
			num[2] -= 1;
			num[1] -= 5;
		}
		else if (num[3] == 2)
		{
			box++;
			num[2] -= 3;
			num[1] -= 6;
		}
		else if (num[3] == 1)
		{
			box++;
			num[2] -= 5;
			num[1] -= 7;
		}

		if (num[2] < 0)
		{
			num[1] += num[2] * 4;
			num[2] = 0;
		}
		box += num[2] / 9;
		num[2] %= 9;
		if (num[2] > 0)
		{
			box++;
			num[1] -= 36 - num[2] * 4;
		}

		if (num[1] > 0)
		{
			box += num[1] / 36;
			if (num[1] % 36 > 0) box++;
		}

		printf("%d\n", box);
	}

	return 0;
}
