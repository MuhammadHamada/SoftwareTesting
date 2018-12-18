#include "SegmentTree.h"
#include<algorithm>
int gcd(int a, int b)
{
	if (b == 0)return a; return gcd(b, a%b);
}
SegmentTree::SegmentTree()
{
}

SegmentTree::SegmentTree(int n)
{
	leavesCnt = n;
	tree.resize(leavesCnt * 2);
}



void SegmentTree::Update(int x, int y, node val, int l, int r, int idx)
{
	if (l > y || r < x)return;
	if (l >= x&&r <= y) {
		tree[idx] = val;
		return;
	}
	int mid = (l + r) >> 1;
	Update(x, y, val, l, mid, idx << 1);
	Update(x, y, val, mid + 1, r, (idx << 1) + 1);
	tree[idx].sum = tree[idx << 1].sum + tree[(idx << 1) + 1].sum;
	tree[idx].max = max(tree[idx << 1].max, tree[(idx << 1) + 1].max);
	tree[idx].min = min(tree[idx << 1].min, tree[(idx << 1) + 1].min);
	tree[idx].gcd = gcd(tree[idx << 1].gcd, tree[(idx << 1) + 1].gcd);
	tree[idx].mul = tree[idx << 1].mul * tree[(idx << 1) + 1].mul;
}

int SegmentTree::getMax(int x, int y, int l, int r, int idx)
{
	if (l > y || r < x)return 0;
	if (l >= x&&r <= y)return tree[idx].max;
	int mid = (l + r) >> 1;
	return (getMax(x, y, l, mid, idx << 1), getMax(x, y, mid + 1, r, (idx << 1) + 1));
}

int SegmentTree::getMin(int x, int y, int l, int r, int idx)
{
	if (l > y || r < x)return 1e9;
	if (l >= x&&r <= y)return tree[idx].min;
	int mid = (l + r) >> 1;
	return min(getMin(x, y, l, mid, idx << 1), getMin(x, y, mid + 1, r, (idx << 1) + 1));
}

int SegmentTree::getSum(int x, int y, int l, int r, int idx)
{
	if (l > y || r < x)return 0;
	if (l >= x&&r <= y)return tree[idx].sum;
	int mid = (l + r) >> 1;
	return getSum(x, y, l, mid, idx << 1) + getSum(x, y, mid + 1, r, (idx << 1) + 1);
}

int SegmentTree::getGcd(int x, int y, int l, int r, int idx)
{
	if (l > y || r < x)return 0;
	if (l >= x&&r <= y)return tree[idx].gcd;
	int mid = (l + r) >> 1;
	return gcd(getGcd(x, y, l, mid, idx << 1), getGcd(x, y, mid + 1, r, (idx << 1) + 1));
}

int SegmentTree::getMul(int x, int y, int l, int r, int idx)
{
	if (l > y || r < x)return 1;
	if (l >= x&&r <= y)return tree[idx].mul;
	int mid = (l + r) >> 1;
	return getMul(x, y, l, mid, idx << 1) * getMul(x, y, mid + 1, r, (idx << 1) + 1);
}
