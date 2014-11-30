#include <stdio.h>
#include <string.h>

char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.,?";
char morse[30][10] = {
	{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."},
	{"..-."}, {"--."}, {"...."}, {".."}, {".---"},
	{"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"},
	{".--."}, {"--.-"}, {".-."}, {"..."}, {"-"},
	{"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"},
	{"--.."}, {"..--"}, {"---."}, {".-.-"}, {"----"}
	};

int n;

char str[200];
int len[200];

char code[1000];

int
main()
{
	int i, j, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);

		code[0] = 0;
		for (j = 0; j < strlen(str); j++)
		{
			for (k = 0; str[j] != letter[k]; k++);
			strcat(code, morse[k]);
			len[j] = strlen(morse[k]);
		}

		int offset = 0;
		char buffer[10];
		for (j = 0; j < strlen(str); j++)
		{
			for (k = 0; k < len[strlen(str) - 1 - j]; k++) buffer[k] = code[offset + k];
			buffer[k] = 0;
			offset += len[strlen(str) - 1 - j];
			for (k = 0; strcmp(buffer, morse[k]) != 0; k++);
			str[j] = letter[k];
		}

		printf("%d: %s\n", i + 1, str);
	}

	return 0;
}
