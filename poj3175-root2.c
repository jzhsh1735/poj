#include <stdio.h>
#include <math.h>

int l;
char digit[10];

int
main()
{
	int i;

	scanf("%d", &l);
	scanf("%s", digit);

	double temp1, temp2;
	temp1 = (double)(digit[l - 1] - '0' + 1) / 10;
	temp2 = (double)(digit[l - 1] - '0') / 10;
	for (i = l - 2; i >= 0; i--)
	{
		temp1 = (temp1 + digit[i] - '0') / 10;
		temp2 = (temp2 + digit[i] - '0') / 10;
	}
	for (i = 0; ; i++)
	{
		if ((i + temp1) * (i + temp1) > ceil((i + temp2) * (i + temp2))) break;
	}

	printf("%.0f\n", ceil((i + temp2) * (i + temp2)));

	return 0;
}
