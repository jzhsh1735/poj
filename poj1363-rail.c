#include <stdio.h>

int n;
int out[1000];
int stack[1000];
int flag;

int
main()
{
	int i, j, k;

	flag = 0;
	while (scanf("%d", &n), n)
	{
		if (flag == 0) flag = 1;
		else printf("\n");

		while (scanf("%d", &out[0]), out[0])
		{
			for (i = 1; i < n; i++) scanf("%d", &out[i]);

			j = -1;
			k = 0;
			for (i = 1; i <= n; i++)
			{
				j++;
				stack[j] = i;
				while (j >= 0 && stack[j] == out[k])
				{
					j--;
					k++;
				}
			}
			printf("%s\n", (k == n? "Yes": "No"));
		}
	}

	return 0;
}
