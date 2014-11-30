#include <stdio.h>
#include <string.h>

int
main()
{
	int len, sum;
	char city[100], code[10];

	sum = 0;
	while (scanf("%s", city), strcmp(city, "#") != 0)
	{
		while (strcmp(city, "0") != 0)
		{
			scanf("%s %d %s", city, &len, code);
			if (code[0] == 'F')
			{
				sum += len * 2;
			}
			else if (code[0] == 'B')
			{
				sum += len + (len + len % 2) / 2;
			}
			else if (code[0] = 'Y')
			{
				if (len < 500) sum += 500;
				else sum += len;
			}
			scanf("%s", city);
		}
		printf("%d\n", sum);
		sum = 0;
	}

	return 0;
}
