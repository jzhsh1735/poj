#include <stdio.h>

int n, l;
int height[30000];
int key, value;

int
main()
{
	int i, j, temp;

	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++) scanf("%d", &height[i]);

	value = -1;
	for (i = 0; i < l; i++)
	{
		temp = 0;
		for (j = 0; j < n; j++)
		{
			temp += height[j] % l;
			height[j]++;
		}
		if (value < 0 || temp < value)
		{
			key = i;
			value = temp;
		}
	}
	printf("%d\n", key);

	return 0;
}
