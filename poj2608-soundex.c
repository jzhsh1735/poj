#include <stdio.h>
#include <string.h>

int val[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
char buffer[50];
int last;

int
main()
{
	int i;

	while (scanf("%s", buffer) != EOF)
	{
		last = 0;
		for (i = 0; i < strlen(buffer); i++)
		{
			if (val[buffer[i] - 'A'] > 0 && val[buffer[i] - 'A'] != last) printf("%d", val[buffer[i] - 'A']);
			last = val[buffer[i] - 'A'];
		}
		printf("\n");
	}

	return 0;
}
