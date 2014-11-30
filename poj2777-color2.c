#include <stdio.h>

#define N 300000

struct node
{
	int left, right;
	int color;
	int cover;
};

int l, t, o;
struct node tree[N];
char oper[10];
int a, b, c;
int color;

void
build_tree(int root, int left, int right)
{
	int mid;

	tree[root].left = left;
	tree[root].right = right;
	tree[root].color = (1 << 1);
	tree[root].cover = 1;
	if (left == right) return;
	else
	{
		mid = (left + right) / 2;
		build_tree(root * 2, left, mid);
		build_tree(root * 2 + 1, mid + 1, right);
	}
}

void
swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void
update(int root, int left, int right, int color)
{
	int mid;

	if (tree[root].left == left && tree[root].right == right)
	{
		tree[root].color = (1 << color);
		tree[root].cover = 1;
	}
	else
	{
		if (tree[root].cover)
		{
			tree[root * 2].color = tree[root * 2 + 1].color = tree[root].color;
			tree[root * 2].cover = tree[root * 2 + 1].cover = 1;
			tree[root].cover = 0;
		}
		mid = (tree[root].left + tree[root].right) / 2;
		if (left > mid) update(root * 2 + 1, left, right, color);
		else if (right <= mid) update(root * 2, left, right, color);
		else
		{
			update(root * 2, left, mid, color);
			update(root * 2 + 1, mid + 1, right, color);
		}
		tree[root].color = tree[root * 2].color | tree[root * 2 + 1].color;
	}
}

int
query(int root, int left, int right)
{
	int mid;

	if (tree[root].left == left && tree[root].right == right) return tree[root].color;
	else
	{
		if (tree[root].cover)
		{
			tree[root * 2].color = tree[root * 2 + 1].color = tree[root].color;
			tree[root * 2].cover = tree[root * 2 + 1].cover = 1;
		}
		mid = (tree[root].left + tree[root].right) / 2;
		if (left > mid) return query(root * 2 + 1, left, right);
		else if (right <= mid) return query(root * 2, left, right);
		else return query(root * 2, left, mid) | query(root * 2 + 1, mid + 1, right);
	}
}

int
count(int color)
{
	int res = 0;

	while (color)
	{
		if (color % 2) res++;
		color /= 2;
	}

	return res;
}

int
main()
{
	scanf("%d %d %d", &l, &t, &o);
	build_tree(1, 1, l);
	while (o--)
	{
		scanf("%s", oper);
		if (oper[0] == 'C')
		{
			scanf("%d %d %d", &a, &b, &c);
			if (a > b) swap(&a, &b);
			update(1, a, b, c);
		}
		if (oper[0] == 'P')
		{
			scanf("%d %d", &a, &b);
			if (a > b) swap(&a, &b);
			color = query(1, a, b);
			printf("%d\n", count(color));
		}
	}

	return 0;
}
