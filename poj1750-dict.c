#include <stdio.h>
#include <string.h>

char str[100];
char last[100];

int
main()
{
	int cnt, flag;

	scanf("%s", last);
	printf("%s\n", last);
	flag = 0;
	while (scanf("%s", str) != EOF)
	{
		cnt = 0;
		while (str[cnt] != 0 && last[cnt] != 0 && str[cnt] == last[cnt]) cnt++;
		if (cnt > flag + 1) cnt = flag + 1;
		flag = cnt;
		strcpy(last, str);

		while (cnt--) printf(" ");
		printf("%s\n", last);
	}

	return 0;
}
