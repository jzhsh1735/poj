#include <stdio.h>
#include <string.h>

char str[1000001];
int next[1000001];
int n;

int
main()
{
	int i, j;

	while (scanf("%s", str), strcmp(str, ".") != 0)
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
		if (n % (n - next[n]) == 0) printf("%d\n", n / (n - next[n]));
		else printf("1\n");
	}

	return 0;
}
