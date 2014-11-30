#include <stdio.h>

#define NUM 64
int len[NUM];
int flag[NUM];

int num, total, stick;

int
search(int index, int left)
{
	int i, result;

	if (left == len[index])
	{
		total -= len[index];
		flag[index] = 1;

		if (total == 0) return 1;

		for (i = 0; i < num; i++)
		{
			if (flag[i] == 0) break;
		}
		result = search(i, stick);

		total += len[index];
		flag[index] = 0;

		return result;
	}
	if (left > len[index])
	{
		total -= len[index];
		flag[index] = 1;

		for (i = index + 1; i < num; i++)
		{
			if (flag[i] == 1) continue;
			if (i != index + 1 && flag[i - 1] == 0 && len[i - 1] == len[i]) continue;
			if (search(i, left - len[index]) == 1) return 1;
		}

		total += len[index];
		flag[index] = 0;

		return 0;
	}
}

int
main()
{
	int i, j, k;

	while (1)
	{
		scanf("%d\n", &num);
		if (num == 0) break;

		total = 0;
		for (i = 0; i < num; i++)
		{
			scanf("%d", &len[i]);
			total += len[i];
		}

		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (len[i] < len[j])
				{
					k = len[i];
					len[i] = len[j];
					len[j] = k;
				}
			}
		}

		for (i = len[0]; i <= total; i++)
		{
			if (total % i != 0) continue;
			stick = i;

			for (j = 0; j < num; j++) flag[j] = 0;

			if (search(0, stick) == 1)
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}
