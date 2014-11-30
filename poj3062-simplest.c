#include <stdio.h>

char str[100];

int
main()
{
	while (gets(str) != NULL)
	{
		printf("%s\n", str);
	}

	return 0;
}
