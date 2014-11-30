#include <stdio.h>

char code[100], str[100];

int
main()
{
	char *p;

	scanf("%s", code);
	getchar();
	gets(str);

	p = str;
	while (*p)
	{
		if (*p >= 'A' && *p <= 'Z') printf("%c", code[*p - 'A'] + 'A' - 'a');
		else if (*p >= 'a' && *p <= 'z') printf("%c", code[*p - 'a']);
		else printf("%c", *p);
		p++;
	}
	printf("\n");

	return 0;
}
