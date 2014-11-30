#include <stdio.h>
#include <string.h>

char str[500000];
int next[500000];
int ans[500000];
int n;

int
main()
{
	int i, j;

	while (scanf("%s", str) != EOF)
	{
		n = strlen(str);
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
		i = n;
		j = 0;
		while (next[i] != -1)
		{
			ans[j] = i;
			j++;
			i = next[i];
		}
		while (j--, j > 0) printf("%d ", ans[j]);
		printf("%d\n", ans[0]);
	}

	return 0;
}
