#include <stdio.h>
#include <string.h>

char str[100];

int
main()
{
	int i;

	while (scanf("%s", str), strcmp(str, "end") != 0)
	{
		int flag, type, len;

		flag = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("<%s> is not acceptable.\n", str);
			continue;
		}

		flag = type = len = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				if (type == 0) len++;
				else
				{
					type = 0;
					len = 1;
				}
			}
			else
			{
				if (type == 0)
				{
					type = 1;
					len = 1;
				}
				else len++;
			}
			if (len == 3)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf("<%s> is not acceptable.\n", str);
			continue;
		}

		flag = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (i + 1 < strlen(str) && str[i] == str[i + 1] && str[i] != 'e' && str[i] != 'o')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			printf("<%s> is not acceptable.\n", str);
			continue;
		}

		printf("<%s> is acceptable.\n", str);
	}

	return 0;
}
