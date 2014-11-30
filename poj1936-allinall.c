#include <stdio.h>

char s[100000], t[100000];

int
main()
{
	char *p, *q;

	while (scanf("%s %s", s, t) != EOF)
	{
		for (p = s, q = t; *p; p++, q++)
		{
			while (*p != *q && *q) q++;

			if (*q == 0) break;
		}
		printf(*p == 0? "Yes\n": "No\n");
	}

	return 0;
}
