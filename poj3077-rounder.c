#include <stdio.h>
#include <string.h>

int n;
char num[20];
int carry;

int
main()
{
	int i;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", num);
		carry = 0;
		for (i = strlen(num) - 1; i > 0; i--)
		{
			if (num[i] + carry >= '5') carry = 1;
			else carry = 0;
			num[i] = '0';
		}
		if (num[0] + carry > '9') printf("10%s\n", num + 1);
		else
		{
			num[0] += carry;
			printf("%s\n", num);
		}
	}

	return 0;
}
