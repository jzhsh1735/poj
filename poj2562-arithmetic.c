#include <stdio.h>
#include <string.h>

char num[2][20];
int len[2];
int oper;
int carry;

int
main()
{
	int i, j;

	while (scanf("%s %s", num[0], num[1]) != EOF)
	{
		if (strcmp(num[0], "0") == 0 && strcmp(num[1], "0") == 0) break;

		len[0] = strlen(num[0]);
		len[1] = strlen(num[1]);
		oper = carry = 0;
		for (i = len[0] - 1, j = len[1] - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (num[0][i] - '0' + num[1][j] - '0' + carry >= 10)
			{
				oper++;
				carry = 1;
			}
			else carry = 0;
		}
		for (; i >= 0; i--)
		{
			if (num[0][i] - '0' + carry >= 10)
			{
				oper++;
				carry = 1;
			}
			else carry = 0;
		}
		for (; j >= 0; j--)
		{
			if (num[1][j] - '0' + carry >= 10)
			{
				oper++;
				carry = 1;
			}
			else carry = 0;
		}

		if (oper == 0) printf("No carry operation.\n");
		else if (oper == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", oper);
	}

	return 0;
}
