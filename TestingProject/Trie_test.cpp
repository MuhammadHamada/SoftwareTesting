#include "CppUTest\TestHarness.h"
#include "Trie.h"
#include<iostream>
using namespace std;

TEST_GROUP(TrieTestGroup) {
	trie*t;
	void setup() {
		t = new trie();
	}
	void teardown() {
		delete t;
	}
};

TEST(TrieTestGroup, Test1) {
	CHECK_FALSE(t->Search("ahmed"));
}


TEST(TrieTestGroup, Test2) {
	t->Insert("ahmed");
	CHECK_EQUAL(t->Search("ahmed"), true);
}

TEST(TrieTestGroup, Test3) {
	t->Insert("ahmed");
	t->Insert("hamada");
	LONGS_EQUAL(2, t->getNumberOfDistinctWords());
}

TEST(TrieTestGroup, Test4) {
	t->Insert("ahmed");
	t->Insert("aho");
	t->Insert("ahh");
	LONGS_EQUAL(7, t->getNumberOfNodes());
}
TEST(TrieTestGroup, Test5) {
	CHECK_FALSE(t->DeleteOccurence("ahmed"));
}
TEST(TrieTestGroup, Test6) {
	t->Insert("hamada");
	CHECK(t->DeleteOccurence("hamada"));
}
TEST(TrieTestGroup, Test7) {
	string s = "hamada";
	string expected = "ham";
	t->Insert("ham");
	t->Insert("ha");
	t->Insert("h");
	STRCMP_EQUAL(expected.c_str(), t->getLongestPrefix(s.c_str()).c_str());
}
TEST(TrieTestGroup, Test8) {

	string s = "hamada";
	string expected = "HAM";
	t->Insert("ham");
	t->Insert("ha");
	STRCMP_NOCASE_EQUAL(expected.c_str(), t->getLongestPrefix(s.c_str()).c_str());
}
TEST(TrieTestGroup, Test9) {
	t->Insert("magdy");
	t->Insert("magdy");
	UNSIGNED_LONGS_EQUAL(1, t->getNumberOfDistinctWords());
}
TEST(TrieTestGroup, Test10) {
	string s = "sobeih";
	string expected = "sob";
	t->Insert("so");
	t->Insert("sobeih");
	STRNCMP_EQUAL(expected.c_str(), t->getLongestPrefix(s.c_str()).c_str(), (int)expected.size());
}
TEST(TrieTestGroup, Test11) {
	t->Insert("sobeih");
	t->Insert("magdy");
	t->Insert("hamada");
	t->DeleteOccurence("hamada");
	LONGS_EQUAL(2, t->getNumberOfDistinctWords());
}
TEST(TrieTestGroup, Test12) {
	t->Insert("sobeih");
	t->Insert("magdy");
	t->Insert("hamada");
	t->DeleteOccurence("magdy");
	LONGS_EQUAL(12, t->getNumberOfNodes());
}