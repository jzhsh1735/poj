#include <stdio.h>
#include <string.h>

#define N 32

char abbr[N][10] = {"UTC", "GMT", "BST", "IST", "WET", "WEST", "CET", "CEST", "EET", "EEST", "MSK", "MSD", "AST", "ADT", "NST", "NDT", "EST", "EDT", "CST", "CDT", "MST", "MDT", "PST", "PDT", "HST", "AKST", "AKDT", "AEST", "AEDT", "ACST", "ACDT", "AWST"};
double deta[N] = {0, 0, 1, 1, 0, 1, 1, 2, 2, 3, 3, 4, -4, -3, -3.5, -2.5, -5, -4, -6, -5, -7, -6, -8, -7, -10, -9, -8, 10, 11, 9.5, 10.5, 8};
int t;
char now[10], apm[10], from[10], to[10];
int n, h, m;

int
main()
{
	int i;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", now);
		if (strcmp(now, "midnight") == 0) n = 0;
		else if (strcmp(now, "noon") == 0) n = 720;
		else
		{
			sscanf(now, "%d:%d", &h, &m);
			h %= 12;
			n = 60 * h + m;
			scanf("%s", apm);
			if (strcmp(apm, "p.m.") == 0) n += 720;
		}
		scanf("%s", from);
		for (i = 0; i < N; i++)
		{
			if (strcmp(from, abbr[i]) == 0) break;
		}
		n -= deta[i] * 60;
		scanf("%s", to);
		for (i = 0; i < N; i++)
		{
			if (strcmp(to, abbr[i]) == 0) break;
		}
		n += deta[i] * 60;
		while (n < 0) n += 1440;
		n %= 1440;

		if (n == 0) printf("midnight\n");
		else if (n == 720) printf("noon\n");
		else
		{
			h = n / 60;
			m = n % 60;
			printf("%d:%02d ", (h % 12 == 0? 12: h % 12), m);
			if (h < 12) printf("a.m.\n");
			else printf("p.m.\n");
		}
	}

	return 0;
}
