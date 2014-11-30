#include <stdio.h>
#include <string.h>

int n, cnt, ans;
int flag[26];

int
main()
{
	int i;
	char buffer[100];

	while (scanf("%d", &n), n)
	{
		scanf("%s", buffer);
		for (i = 0; i < 26; i++) flag[i] = 0;

		cnt = ans = 0;
		for (i = 0; i < strlen(buffer); i++)
		{
			if (flag[buffer[i] - 'A'] == 0)
			{
				if (n > cnt)
				{
					cnt++;
					flag[buffer[i] - 'A'] = 1;
				}
				else
				{
					ans++;
					flag[buffer[i] - 'A'] = -1;
				}
			}
			else if (flag[buffer[i] - 'A'] == 1)
			{
				cnt--;
				flag[buffer[i] - 'A'] = 0;
			}
			else if (flag[buffer[i] - 'A'] == -1)
			{
				flag[buffer[i] - 'A'] = 0;
			}
		}

		if (ans == 0) printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n", ans);
	}

	return 0;
}
