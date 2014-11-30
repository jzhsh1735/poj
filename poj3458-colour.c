#include <stdio.h>
#include <string.h>

int n;
char seq[200];
char card[2][200];

int
main()
{
	int i, j;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", seq);
		for (i = 0; i < 2; i++) scanf("%s", card[i]);

		i = 0;
		for (j = 0; j < strlen(card[0]) && seq[i] != 0; j++)
		{
			if (card[0][j] == '*' || card[1][j] == '*' || card[0][j] == seq[i] || card[1][j] == seq[i]) i++;
		}
		if (seq[i] == 0) printf("win\n");
		else printf("lose\n");
	}

	return 0;
}
