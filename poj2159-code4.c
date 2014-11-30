#include <stdio.h>
#include <string.h>

char str[100];
int freq[2][26];

int
compare(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int
main()
{
	int i, j;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 26; j++)
		{
			freq[i][j] = 0;
		}
	}

	for (i = 0; i < 2; i++)
	{
		scanf("%s", str);
		for (j = 0; j < strlen(str); j++)
		{
			freq[i][str[j] - 'A']++;
		}
		qsort(freq[i], 26, sizeof(int), compare);
	}
	for (i = 0; i < 26; i++)
	{
		if (freq[0][i] != freq[1][i]) break;
	}

	if (i == 26) printf("YES\n");
	else printf("NO\n");

	return 0;
}
