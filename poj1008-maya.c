#include <stdio.h>
#include <string.h>

int
main()
{
	int n;
	scanf("%d\n", &n);
	printf("%d\n", n);

	int day, month, year, total;
	char buffer[32];

	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d. %s %d", &day, buffer, &year);

		if (strcmp(buffer, "pop") == 0) month = 0;
		if (strcmp(buffer, "no") == 0) month = 1;
		if (strcmp(buffer, "zip") == 0) month = 2;
		if (strcmp(buffer, "zotz") == 0) month = 3;
		if (strcmp(buffer, "tzec") == 0) month = 4;
		if (strcmp(buffer, "xul") == 0) month = 5;
		if (strcmp(buffer, "yoxkin") == 0) month = 6;
		if (strcmp(buffer, "mol") == 0) month = 7;
		if (strcmp(buffer, "chen") == 0) month = 8;
		if (strcmp(buffer, "yax") == 0) month = 9;
		if (strcmp(buffer, "zac") == 0) month = 10;
		if (strcmp(buffer, "ceh") == 0) month = 11;
		if (strcmp(buffer, "mac") == 0) month = 12;
		if (strcmp(buffer, "kankin") == 0) month = 13;
		if (strcmp(buffer, "muan") == 0) month = 14;
		if (strcmp(buffer, "pax") == 0) month = 15;
		if (strcmp(buffer, "koyab") == 0) month = 16;
		if (strcmp(buffer, "cumhu") == 0) month = 17;
		if (strcmp(buffer, "uayet") == 0) month = 18;

		total = day + month * 20 + year * 365;

		year = total / 260;
		month = total % 20;
		day = total % 13 + 1;

		switch (month)
		{
			case 0: sprintf(buffer, "imix");
			break;
			case 1: sprintf(buffer, "ik");
			break;
			case 2: sprintf(buffer, "akbal");
			break;
			case 3: sprintf(buffer, "kan");
			break;
			case 4: sprintf(buffer, "chicchan");
			break;
			case 5: sprintf(buffer, "cimi");
			break;
			case 6: sprintf(buffer, "manik");
			break;
			case 7: sprintf(buffer, "lamat");
			break;
			case 8: sprintf(buffer, "muluk");
			break;
			case 9: sprintf(buffer, "ok");
			break;
			case 10: sprintf(buffer, "chuen");
			break;
			case 11: sprintf(buffer, "eb");
			break;
			case 12: sprintf(buffer, "ben");
			break;
			case 13: sprintf(buffer, "ix");
			break;
			case 14: sprintf(buffer, "mem");
			break;
			case 15: sprintf(buffer, "cib");
			break;
			case 16: sprintf(buffer, "caban");
			break;
			case 17: sprintf(buffer, "eznab");
			break;
			case 18: sprintf(buffer, "canac");
			break;
			case 19: sprintf(buffer, "ahau");
			break;
			default:
			break;
		}

		printf("%d %s %d\n", day, buffer, year);
	}

	return 0;
}
