#pragma once
#include<vector>
using namespace std;
struct node {
	int max, sum, min, gcd, mul;
	node() {};
	node(int mx, int s, int mn, int g, int mu) :max(mx), sum(s), min(mn), gcd(g), mul(mu) {};
};
class SegmentTree {
private:
	int leavesCnt;
	vector<node>tree;
public:
	SegmentTree();
	SegmentTree(int n);
	void Update(int x, int y, node val, int l, int r, int idx);
	int getMax(int x, int y, int l, int r, int idx);
	int getMin(int x, int y, int l, int r, int idx);
	int getSum(int x, int y, int l, int r, int idx);
	int getGcd(int x, int y, int l, int r, int idx);
	int getMul(int x, int y, int l, int r, int idx);
};
