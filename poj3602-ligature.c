#include <stdio.h>
#include <string.h>

char buffer[200];
int flag[300];
int ans;

int
main()
{
	int i;

	for (i = 0; i < 300; i++) flag[i] = 0;
	while (gets(buffer) != NULL)
	{
		i = 0;
		while (i < strlen(buffer))
		{
			if (buffer[i] == 'f' && buffer[i + 1] == 'f' && buffer[i + 2] == 'i')
			{
				flag[256] = 1;
				i += 3;
			}
			else if (buffer[i] == 'f' && buffer[i + 1] == 'f' && buffer[i + 2] == 'l')
			{
				flag[257] = 1;
				i += 3;
			}
			else if (buffer[i] == 'f' && buffer[i + 1] == 'f')
			{
				flag[258] = 1;
				i += 2;
			}
			else if (buffer[i] == 'f' && buffer[i + 1] == 'i')
			{
				flag[259] = 1;
				i += 2;
			}
			else if (buffer[i] == 'f' && buffer[i + 1] == 'l')
			{
				flag[260] = 1;
				i += 2;
			}
			else if (buffer[i] == '`' && buffer[i + 1] == '`')
			{
				flag[261] = 1;
				i += 2;
			}
			else if (buffer[i] == '\'' && buffer[i + 1] == '\'')
			{
				flag[262] = 1;
				i += 2;
			}
			else
			{
				if (buffer[i] != ' ') flag[buffer[i]] = 1;
				i++;
			}
		}
	}
	ans = 0;
	for (i = 0; i < 300; i++) ans += flag[i];
	printf("%d\n", ans);

	return 0;
}
