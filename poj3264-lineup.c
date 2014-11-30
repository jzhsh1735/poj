#include <stdio.h>

#define N 200000

struct node
{
	int left, right;
	int max, min;
};

int n, q, qmax, qmin;
int num[N];
struct node tree[N];

int
max(int x, int y)
{
	return x > y? x: y;
}

int
min(int x, int y)
{
	return x < y? x: y;
}

void
build_tree(int root, int left, int right)
{
	int mid;

	tree[root].left = left;
	tree[root].right = right;
	if (left == right)
	{
		tree[root].max = tree[root].min = num[left];
	}
	else
	{
		mid = (left + right) / 2;
		build_tree(root * 2, left, mid);
		build_tree(root * 2 + 1, mid + 1, right);
		tree[root].max = max(tree[root * 2].max, tree[root * 2 + 1].max);
		tree[root].min = min(tree[root * 2].min, tree[root * 2 + 1].min);
	}
}

void
query(int root, int left, int right)
{
	int mid;

	if (tree[root].left == left && tree[root].right == right)
	{
		if (qmax < 0 || qmax < tree[root].max) qmax = tree[root].max;
		if (qmin < 0 || qmin > tree[root].min) qmin = tree[root].min;
	}
	else
	{
		mid = (tree[root].left + tree[root].right) / 2;
		if (left > mid) query(root * 2 + 1, left, right);
		else if (right <= mid) query(root * 2, left, right);
		else
		{
			query(root * 2, left, mid);
			query(root * 2 + 1, mid + 1, right);
		}
	}
}

int
main()
{
	int i;
	int t1, t2;

	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%d", &num[i]);
	build_tree(1, 1, n);
	while (q--)
	{
		scanf("%d %d", &t1, &t2);
		qmax = qmin = -1;
		query(1, t1, t2);
		printf("%d\n", qmax - qmin);
	}

	return 0;
}
