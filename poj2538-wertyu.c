#include <stdio.h>
#include <string.h>

char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
char map[256];
char str[500];

int
main()
{
	int i;

	for (i = 0; i < strlen(key); i++)
	{
		if (i != 0) map[key[i]] = key[i - 1];
	}
	map[' '] = ' ';

	while (gets(str) != NULL)
	{
		for (i = 0; i < strlen(str); i++) printf("%c", map[str[i]]);
		printf("\n");
	}

	return 0;
}
