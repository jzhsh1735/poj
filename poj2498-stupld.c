#include <stdio.h>
#include <string.h>

int n;
char number[10];
int fac[3] = {9, 3, 7};
int mpos, mfac, prod;

int
main()
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", number);
		prod = 0;
		for (j = 0; j < strlen(number); j++)
		{
			if (number[j] == '?')
			{
				mpos = j;
				mfac = fac[(strlen(number) - 1 - j) % 3];
			}
			else
			{
				prod += (number[j] - '0') * fac[(strlen(number) - 1 - j) % 3];
			}
		}
		for (j = 0; j < 10; j++)
		{
			if ((prod + mfac * j) % 10 == 0) break;
		}
		number[mpos] = '0' + j;
		printf("Scenario #%d:\n%s\n\n", i + 1, number);
	}

	return 0;
}
