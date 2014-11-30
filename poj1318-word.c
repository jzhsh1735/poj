#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char word[100][10];
char sort[100][10];
char query[100];

int
cmp_string(const void *x, const void *y)
{
	return strcmp((char *)x, (char *)y);
}

int
cmp_char(const void *x, const void *y)
{
	return *(char *)x - *(char *)y;
}

int
main()
{
	int i;

	n = 0;
	while (scanf("%s", word[n]), strcmp(word[n], "XXXXXX") != 0) n++;
	qsort(word, n, sizeof(word[0]), cmp_string);

	for (i = 0; i < n; i++)
	{
		strcpy(sort[i], word[i]);
		qsort(sort[i], strlen(sort[i]), sizeof(char), cmp_char);
	}

	while (scanf("%s", query), strcmp(query, "XXXXXX") != 0)
	{
		int flag = 0;
		qsort(query, strlen(query), sizeof(char), cmp_char);
		for (i = 0; i < n; i++)
		{
			if (strcmp(query, sort[i]) == 0)
			{
				printf("%s\n", word[i]);
				flag = 1;
			}
		}
		
		if (flag == 0) printf("NOT A VALID WORD\n");
		printf("******\n");
	}

	return 0;
}
