#include <stdio.h>
#include <string.h>

#define NUM 10000000
int cnt[NUM];

int main()
{
	int n;
	scanf("%d", &n);

	char buffer[1024];

	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		scanf("%s", buffer);
		temp = 0;
		for (j = 0; j < strlen(buffer); j++)
		{
			switch (buffer[j])
			{
				case '0': temp *= 10;
				break;
				case '1': temp *= 10; temp += 1;
				break;
				case 'A':
				case 'B':
				case 'C':
				case '2': temp *= 10; temp += 2;
				break;
				case 'D':
				case 'E':
				case 'F':
				case '3': temp *= 10; temp += 3;
				break;
				case 'G':
				case 'H':
				case 'I':
				case '4': temp *= 10; temp += 4;
				break;
				case 'J':
				case 'K':
				case 'L':
				case '5': temp *= 10; temp += 5;
				break;
				case 'M':
				case 'N':
				case 'O':
				case '6': temp *= 10; temp += 6;
				break;
				case 'P':
				case 'R':
				case 'S':
				case '7': temp *= 10; temp += 7;
				break;
				case 'T':
				case 'U':
				case 'V':
				case '8': temp *= 10; temp += 8;
				break;
				case 'W':
				case 'X':
				case 'Y':
				case '9': temp *= 10; temp += 9;
				break;
				case '-':
				default:
				break;
			}
		}
		cnt[temp]++;
	}

	int flag = 0;
	for (i = 0; i < NUM; i++)
	{
		if (cnt[i] > 1)
		{
			sprintf(buffer, "%07d", i);
			printf("%c%c%c-%c%c%c%c %d\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6], cnt[i]);
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("No duplicates.\n");
	}

	return 0;
}
