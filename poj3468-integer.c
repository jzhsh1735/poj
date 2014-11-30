#include <stdio.h>

#define N 300000

struct node
{
	int left, right;
	long long sum, c;
};

int n, q;
long long num[N];
struct node tree[N];
char oper[10];
int a, b;
long long c;

void
build_tree(int root, int left, int right)
{
	int mid;

	tree[root].left = left;
	tree[root].right = right;
	tree[root].c = 0;
	if (left == right) tree[root].sum = num[left];
	else
	{
		mid = (left + right) / 2;
		build_tree(root * 2, left, mid);
		build_tree(root * 2 + 1, mid + 1, right);
		tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
	}
}

void
update(int root, int left, int right, long long c)
{
	int mid;

	if (tree[root].left == left && tree[root].right == right)
	{
		tree[root].sum += c * (right - left + 1);
		tree[root].c += c;
	}
	else
	{
		if (tree[root].c)
		{
			tree[root * 2].c += tree[root].c;
			tree[root * 2 + 1].c += tree[root].c;
			tree[root * 2].sum += tree[root].c * (tree[root * 2].right - tree[root * 2].left + 1);
			tree[root * 2 + 1].sum += tree[root].c * (tree[root * 2 + 1].right - tree[root * 2 + 1].left + 1);
			tree[root].c = 0;
		}
		mid = (tree[root].left + tree[root].right) / 2;
		if (left > mid) update(root * 2 + 1, left, right, c);
		else if (right <= mid) update(root * 2, left, right, c);
		else
		{
			update(root * 2, left, mid, c);
			update(root * 2 + 1, mid + 1, right, c);
		}
		tree[root].sum = tree[root * 2].sum + tree[root * 2 + 1].sum;
	}
}

long long
query(int root, int left, int right)
{
	int mid;

	if (tree[root].left == left && tree[root].right == right) return tree[root].sum;
	else
	{
		if (tree[root].c)
		{
			tree[root * 2].c += tree[root].c;
			tree[root * 2 + 1].c += tree[root].c;
			tree[root * 2].sum += tree[root].c * (tree[root * 2].right - tree[root * 2].left + 1);
			tree[root * 2 + 1].sum += tree[root].c * (tree[root * 2 + 1].right - tree[root * 2 + 1].left + 1);
			tree[root].c = 0;
		}
		mid = (tree[root].left + tree[root].right) / 2;
		if (left > mid) return query(root * 2 + 1, left, right);
		else if (right <= mid) return query(root * 2, left, right);
		else return query(root * 2, left, mid) + query(root * 2 + 1, mid + 1, right);
	}
}

int
main()
{
	int i;

	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%lld", &num[i]);
	build_tree(1, 1, n);
	while (q--)
	{
		scanf("%s", oper);
		if (oper[0] == 'Q')
		{
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(1, a, b));
		}
		if (oper[0] == 'C')
		{
			scanf("%d %d %lld", &a, &b, &c);
			update(1, a, b, c);
		}
	}

	return 0;
}
