#include <stdio.h>

#define N 200

int n;
int queue[N];
int top_queue, tail_queue;
int stack1[N], stack5[N], stack60[N];
int top_stack1, top_stack5, top_stack60;
int perm[N];
int ans;

int
gcd(int x, int y)
{
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int
main()
{
	int i, j, k;

	while (scanf("%d", &n), n)
	{
		top_queue = 0;
		tail_queue = n - 1;
		for (i = 0; i < n; i++) queue[i] = i;
		top_stack1 = top_stack5 = top_stack60 = -1;

		for (i = 1; i <= 1440; i++)
		{
			top_stack1++;
			stack1[top_stack1] = queue[top_queue];
			top_queue++;
			top_queue %= N;
			if (i % 5 == 0)
			{
				top_stack5++;
				stack5[top_stack5] = stack1[top_stack1];
				top_stack1--;
				while (top_stack1 >= 0)
				{
					tail_queue++;
					tail_queue %= N;
					queue[tail_queue] = stack1[top_stack1];
					top_stack1--;
				}
			}
			if (i % 60 == 0)
			{
				top_stack60++;
				stack60[top_stack60] = stack5[top_stack5];
				top_stack5--;
				while (top_stack5 >= 0)
				{
					tail_queue++;
					tail_queue %= N;
					queue[tail_queue] = stack5[top_stack5];
					top_stack5--;
				}
			}
			if (i % 720 == 0)
			{
				j = stack60[top_stack60];
				top_stack60--;
				while (top_stack60 >= 0)
				{
					tail_queue++;
					tail_queue %= N;
					queue[tail_queue] = stack60[top_stack60];
					top_stack60--;
				}
				tail_queue++;
				tail_queue %= N;
				queue[tail_queue] = j;
			}
		}
		for (i = 0; i < n; i++) perm[i] = queue[(top_queue + i) % N];
		ans = 1;
		for (i = 0; i < n; i++)
		{
			j = 1;
			k = i;
			while (perm[k] != i)
			{
				k = perm[k];
				j++;
			}
			ans = ans * j / gcd(j, ans);
		}
		printf("%d balls cycle after %d days.\n", n, ans);
	}

	return 0;
}
