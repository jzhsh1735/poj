#include <stdio.h>
#include <string.h>

char code[100];

int
next(char *str)
{
	char *p, *q, temp;

	p = q = str + strlen(str) - 1;
	while (p >= str && *p >= *(p + 1)) p--;
	if (p < str) return 0;

	while (*p >= *q) q--;
	temp = *p;
	*p = *q;
	*q = temp;

	p++;
	q = str + strlen(str) - 1;
	while (p < q)
	{
		temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
	return 1;
}

int
main()
{
	while (scanf("%s", code), strcmp(code, "#") != 0)
	{
		if (next(code) == 0) printf("No Successor\n");
		else printf("%s\n", code);
	}

	return 0;
}
