#include <stdio.h>
#include <string.h>

int n;
char word[100];

int
rank(char c)
{
	if (c >= 'A' && c <= 'Z') return 2 * (c - 'A');
	else return 2 * (c - 'a') + 1;
}

int
compare(const void *x, const void *y)
{
	return rank(*(char *)x) - rank(*(char *)y);
}

int
next(char *str)
{
	char *p, *q, temp;

	p = q = str + strlen(str) - 1;
	//while (p >= str && *p >= *(p + 1)) p--;
	while (p >= str && (*(p + 1) == 0 || compare(p, p + 1) >= 0)) p--;
	if (p < str) return 0;

	//while (*p >= *q) q--;
	while (compare(p, q) >= 0) q--;
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
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", word);
		qsort(word, strlen(word), sizeof(char), compare);

		printf("%s\n", word);
		while (next(word) != 0) printf("%s\n", word);
	}

	return 0;
}
