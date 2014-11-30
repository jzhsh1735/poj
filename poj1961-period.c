#include <stdio.h>

char str[1000001];
int next[1000001];
int n, t;

int
main()
{
	int i, j, k;

	t = 0;
	while (scanf("%d", &n), n)
	{
		scanf("%s", str);
		i = 0;
		j = -1;
		next[0] = -1;
		while (i < n)
		{
			if (j == -1 || str[i] == str[j])
			{
				i++;
				j++;
				next[i] = j;
			}
			else j = next[j];
		}
		t++;
		printf("Test case #%d\n", t);
		for (i = 2; i <= n; i++)
		{
			if (i % (j = i - next[i]) == 0)
			{
				if ((k = i / j) > 1) printf("%d %d\n", i, k);
			}
		}
		printf("\n");
	}

	return 0;
}
