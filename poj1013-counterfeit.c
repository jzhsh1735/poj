#include <stdio.h>
#include <string.h>

char left[3][12];
char right[3][12];
char result[3][12];

int flag[12];

int
main()
{
	int n;
	scanf("%d\n", &n);

	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++) scanf("%s %s %s", left[j], right[j], result[j]);

		for (j = 0; j < 12; j++) flag[j] = -1;
		for (j = 0; j < 3; j++)
		{
			if (strcmp(result[j], "even") == 0)
			{
				for (k = 0; k < strlen(left[j]); k++) flag[left[j][k] - 'A'] = 0;
				for (k = 0; k < strlen(right[j]); k++) flag[right[j][k] - 'A'] = 0;
			}
			if (strcmp(result[j], "up") == 0)
			{
				int temp[12];
				for (k = 0; k < 12; k++) temp[k] = 0;
				for (k = 0; k < strlen(left[j]); k++)
				{
					temp[left[j][k] - 'A'] = 1;
					if (flag[left[j][k] - 'A'] < 0) flag[left[j][k] - 'A'] = 1;
					if (flag[left[j][k] - 'A'] == 2) flag[left[j][k] - 'A'] = 0;
				}
				for (k = 0; k < strlen(right[j]); k++)
				{
					temp[right[j][k] - 'A'] = 1;
					if (flag[right[j][k] - 'A'] < 0) flag[right[j][k] - 'A'] = 2;
					if (flag[right[j][k] - 'A'] == 1) flag[right[j][k] - 'A'] = 0;
				}
				for (k = 0; k < 12; k++)
				{
					if (temp[k] == 0) flag[k] = 0;
				}
			}
			if (strcmp(result[j], "down") == 0)
			{
				int temp[12];
				for (k = 0; k < 12; k++) temp[k] = 0;
				for (k = 0; k < strlen(left[j]); k++)
				{
					temp[left[j][k] - 'A'] = 1;
					if (flag[left[j][k] - 'A'] < 0) flag[left[j][k] - 'A'] = 2;
					if (flag[left[j][k] - 'A'] == 1) flag[left[j][k] - 'A'] = 0;
				}
				for (k = 0; k < strlen(right[j]); k++)
				{
					temp[right[j][k] - 'A'] = 1;
					if (flag[right[j][k] - 'A'] < 0) flag[right[j][k] - 'A'] = 1;
					if (flag[right[j][k] - 'A'] == 2) flag[right[j][k] - 'A'] = 0;
				}
				for (k = 0; k < 12; k++)
				{
					if (temp[k] == 0) flag[k] = 0;
				}
			}
		}

		for (j = 0; j < 12; j++)
		{
			if (flag[j] > 0)
			{
				if (flag[j] == 1) printf("%c is the counterfeit coin and it is heavy.\n", 'A' + j);
				if (flag[j] == 2) printf("%c is the counterfeit coin and it is light.\n", 'A' + j);
				break;
			}
		}
	}
	return 0;
}
