#include <stdio.h>

int
main()
{
	int i;
	double sum = 0, temp;
	for (i = 0; i < 12; i++)
	{
		scanf("%lf\n", &temp);
		sum += temp;
	}
	sum /= 12;
	
	if ((int)(sum * 100) + 0.5 > sum * 100)
		i = (int)(sum * 100);
	else
		i = (int)(sum * 100) + 1;
	
	printf("$%d.%02d\n", i / 100, i % 100);

	return 0;
}
