#include <stdio.h>
#include <string.h>

char isbn[100];

int
main()
{
	int i, index, sum = 0, ans = -1;

	scanf("%s", isbn);
	for (i = 0; i < strlen(isbn); i++)
	{
		if (isbn[i] == '?') index = 10 - i;
		else if (isbn[i] == 'X') sum += (10 - i) * 10;
		else sum += (10 - i) * (isbn[i] - '0');
	}
	for (i = 0; i < (index == 1? 11: 10); i++)
	{
		if ((sum + index * i) % 11 == 0) ans = i;
	}

	if (ans == 10) printf("X\n");
	else printf("%d\n", ans);

	return 0;
}
