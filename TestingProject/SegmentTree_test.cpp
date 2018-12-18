#include "CppUTest\TestHarness.h"
#include "SegmentTree.h"
#include<iostream>
using namespace std;
TEST_GROUP(SegmentTreeTestGroup) {
	int leavesCnt = 8;
	SegmentTree Seg;
	void setup() {
		SegmentTree temp(leavesCnt);
		Seg = temp;
		//SegmentTree Seg(leavesCnt);
		for (int i = 1; i <= 8; ++i)Seg.Update(i, i, node(i, i, i, i, i), 1, 8, 1);

	}
	void teardown() {

	}
};

TEST(SegmentTreeTestGroup, Test1) {
	LONGS_EQUAL(8, Seg.getMax(1, 8, 1, 8, 1));
}

TEST(SegmentTreeTestGroup, Test2) {
	cout << Seg.getMin(1, 8, 1, 8, 1);
	LONGS_EQUAL(1, Seg.getMin(1, 8, 1, 8, 1));
}

TEST(SegmentTreeTestGroup, Test3) {
	LONGS_EQUAL(36, Seg.getSum(1, 8, 1, 8, 1));
}

TEST(SegmentTreeTestGroup, Test4) {
	LONGS_EQUAL(1, Seg.getGcd(1, 8, 1, 8, 1));
}

TEST(SegmentTreeTestGroup, Test5) {
	LONGS_EQUAL(40320, Seg.getMul(1, 8, 1, 8, 1));
}
