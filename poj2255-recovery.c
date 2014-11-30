#include <stdio.h>
#include <string.h>

char preord[100];
char inord[100];

void
postord(int preidx, int inidx, int len)
{
	int i;

	if (len == 0) return;
	for (i = 0; i < len; i++)
	{
		if (preord[preidx] == inord[inidx + i]) break;
	}
	postord(preidx + 1, inidx, i);
	postord(preidx + i + 1, inidx + i + 1, len - 1 - i);
	printf("%c", preord[preidx]);
}

int
main()
{
	while (scanf("%s %s", preord, inord) != EOF)
	{
		postord(0, 0, strlen(inord));
		printf("\n");
	}

	return 0;
}
