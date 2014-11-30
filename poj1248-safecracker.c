#include <stdio.h>
#include <string.h>

int target;
char letter[50];
char result[50];
int flag;

int
calc(char *str)
{
	int i, j, result = 0;

	for (i = 1; i <= 5; i++)
	{
		int temp = 1;
		for (j = 1; j <= i; j++) temp *= str[i - 1] - 'A' + 1;

		if (i % 2) result += temp;
		else result -= temp;
	}

	return result;
}

int
main()
{
	int i, j, k, l, m;

	while (scanf("%d", &target), target)
	{
		scanf("%s", letter);
		for (i = 0; i < strlen(letter); i++)
		{
			for (j = i + 1; j < strlen(letter); j++)
			{
				if (letter[i] < letter[j])
				{
					char temp = letter[i];
					letter[i] = letter[j];
					letter[j] = temp;
				}
			}
		}

		flag = 0;
		for (i = 0; i < strlen(letter) && flag == 0; i++)
		{
			result[0] = letter[i];
			for (j = 0; j < strlen(letter) && flag == 0; j++)
			{
				if (j == i) continue;
				result[1] = letter[j];
				for (k = 0; k < strlen(letter) && flag == 0; k++)
				{
					if (k == i || k == j) continue;
					result[2] = letter[k];
					for (l = 0; l < strlen(letter) && flag == 0; l++)
					{
						if (l == i || l == j || l == k) continue;
						result[3] = letter[l];
						for (m = 0; m < strlen(letter) && flag == 0; m++)
						{
							if (m == i || m == j || m == k || m == l) continue;
							result[4] = letter[m];
							result[5] = 0;

							int temp = calc(result);
							if (temp == target) flag = 1;
						}
					}
				}
			}
		}

		if (flag == 0) printf("no solution\n");
		else printf("%s\n", result);
	}

	return 0;
}
