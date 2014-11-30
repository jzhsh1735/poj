#include <stdio.h>

int n;
int result[1000];

int
main()
{
	int i, num;

	scanf("%d", &n);

	i = 2;
	num = 0;
	while (i <= n)
	{
		n -= i;
		result[num] = i;
		i++;
		num++;
	}
	for (i = num - 1; i >= 0 && n > 0; i--)
	{
		result[i]++;
		n--;
	}
	if (n > 0) result[num - 1]++;

	printf("%d", result[0]);
	for (i = 1; i < num; i++) printf(" %d", result[i]);
	printf("\n");

	return 0;
}
