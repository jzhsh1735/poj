#include <stdio.h>
#include <string.h>

struct node
{
	int flag;
	struct node *next[2];
};

struct node n[100];
int len;

char str[100];

int
insert(char *str)
{
	int i;

	struct node *current = &n[0];
	for (i = 0; i < strlen(str); i++)
	{
		if (current->next[str[i] - '0'] == NULL)
		{
			n[len].flag = 0;
			n[len].next[0] = NULL;
			n[len].next[1] = NULL;
			current->next[str[i] - '0'] = &n[len];
			len++;
		}
		current = current->next[str[i] - '0'];

		if (current->flag) return 1;
	}

	if (current->next[0] != NULL || current->next[1] != NULL) return 1;

	current->flag = 1;

	return 0;
}

int
main()
{
	int i = 0, flag;

	while (scanf("%s", str) != EOF)
	{
		len = 1;
		n[0].flag = 0;
		n[0].next[0] = NULL;
		n[0].next[1] = NULL;

		flag = 0;
		insert(str);
		while (scanf("%s", str), strcmp(str, "9") != 0)
		{
			if (flag == 0 && insert(str)) flag = 1;
		}

		if (flag == 0) printf("Set %d is immediately decodable\n", i + 1);
		else printf("Set %d is not immediately decodable\n", i + 1);
		i++;
	}

	return 0;
}
