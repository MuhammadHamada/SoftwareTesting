#include "Trie.h"
#include "CppUTest\TestHarness.h"
#include "CppUTestExt\MockSupport.h"
#include<iostream>
using namespace std;
class TrieMock : public trie {
public:
	virtual bool DeleteOccurence(const char* s) {
		mock().actualCall("DeleteOccurence").withParameter("s", s);
		if (!Search(s))return false;
		int id = 0;
		for (int i = 0; s[i]; ++i) {
			int &nxt = trie_nodes[id][s[i] - 'a'];
			--freq[id];
			if (freq[id] == 1) {
				trie_nodes[id][s[i] - 'a'] = -1;
			}
			id = nxt;
		}
		NodeCnt -= strlen(s);
		--freq[id];
		--isEnd[id];
		NumberOfDistinctWords -= (isEnd[id] == 0);
		return true;
	}
	virtual bool Search(const char*s) {
		mock().actualCall("Search").withParameter("s", s);
		return false;
	}
};

TEST_GROUP(MockTest) {
	void teardown() {
		mock().clear();
	}
};
TEST(MockTest, Test1) {
	mock().expectOneCall("DeleteOccurence").withParameter("s", "ss");
	mock().expectOneCall("Search").withParameter("s", "ss");
	trie * tm = new TrieMock;
	tm->DeleteOccurence("ss");
	mock().checkExpectations();
	delete tm;
}