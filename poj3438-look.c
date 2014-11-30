#include <stdio.h>
#include <string.h>

int n;
char str[2000];
char key;
int value;

int
main()
{
	int i;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", str);

		key = value = 0;
		for (i = 0; i < strlen(str); i++)
		{
			if (key != str[i])
			{
				if (i != 0) printf("%d%c", value, key);
				key = str[i];
				value = 1;
			}
			else value++;
		}
		printf("%d%c\n", value, key);
	}

	return 0;
}
