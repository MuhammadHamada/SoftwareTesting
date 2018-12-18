#include <iostream>
#include <algorithm> 
#include <cmath>
#include "CppUTest/TestHarness.h"
#include "MathUtilities.h"

using namespace std;

TEST_GROUP(MathUtilsTestGroup)
{
	MathUtilities * mathP;
	void setup()
	{
		mathP = new MathUtilities();
	}

	void teardown()
	{
		delete mathP;
	}
};


TEST(MathUtilsTestGroup, Test1)
{
	CHECK_EQUAL(3, mathP->gcd(6, 9));
	CHECK_EQUAL(1, mathP->gcd(10000, 23));
	CHECK_EQUAL(100, mathP->gcd(10000, 100));
	CHECK_EQUAL(13, mathP->gcd(13, 143));
	CHECK_EQUAL(13, mathP->gcd(26, 143));
}

TEST(MathUtilsTestGroup, Test2)
{
	LONGS_EQUAL(18, mathP->lcm(6, 9));
	LONGS_EQUAL(230000, mathP->lcm(10000, 23));
	LONGS_EQUAL(10000, mathP->lcm(10000, 100));
	LONGS_EQUAL(143, mathP->lcm(13, 143));
	LONGS_EQUAL(286, mathP->lcm(26, 143));
}

TEST(MathUtilsTestGroup, Test3)
{
	LONGS_EQUAL(9, mathP->powerr(3, 2));
	LONGS_EQUAL(25, mathP->powerr(5, 2));
	LONGS_EQUAL(216, mathP->powerr(6, 3));
	LONGS_EQUAL(100000, mathP->powerr(10, 5));
	LONGS_EQUAL(121, mathP->powerr(11, 2));
}

TEST(MathUtilsTestGroup, Test4)
{
	LONGS_EQUAL((1ll << 32), mathP->powerr(2, 32));
}

TEST(MathUtilsTestGroup, Test5)
{
	CHECK(mathP->isPrime(2));
	CHECK(mathP->isPrime(3));
	CHECK(mathP->isPrime(5));
	CHECK(mathP->isPrime(7));
	CHECK(mathP->isPrime(11));
	CHECK(mathP->isPrime(13));
	CHECK(mathP->isPrime(17));
	CHECK(mathP->isPrime(1e9 + 7));
}

TEST(MathUtilsTestGroup, Test6)
{
	CHECK_FALSE(mathP->isPrime(10));
	CHECK_FALSE(mathP->isPrime(15));
	CHECK_FALSE(mathP->isPrime(18));
	CHECK_FALSE(mathP->isPrime(49));
	CHECK_FALSE(mathP->isPrime(56));
	CHECK_FALSE(mathP->isPrime(1000));
	CHECK_FALSE(mathP->isPrime(1234));
	CHECK_FALSE(mathP->isPrime(1e9));
}

TEST(MathUtilsTestGroup, Test7)
{
	DOUBLES_EQUAL(12.56637061, mathP->circleArea(2), 0.000001);
	DOUBLES_EQUAL(530.9291585, mathP->circleArea(13), 0.1);
	DOUBLES_EQUAL(31415.92654, mathP->circleArea(100), 0.1);
	DOUBLES_EQUAL(314159265.4, mathP->circleArea(10000), 0.1);
}

TEST(MathUtilsTestGroup, Test8)
{
	DOUBLES_EQUAL(12.56637061, mathP->circleArea(2), 0.000001);
	DOUBLES_EQUAL(530.9291585, mathP->circleArea(13), 0.000001);
	DOUBLES_EQUAL(31415.92654, mathP->circleArea(100), 0.0000000001);
	DOUBLES_EQUAL(314159265.4, mathP->circleArea(10000), 0.000001);
}

TEST(MathUtilsTestGroup, Test9)
{
	UNSIGNED_LONGS_EQUAL(3, mathP->nCr(3, 1));
	UNSIGNED_LONGS_EQUAL(35, mathP->nCr(7, 4));
	UNSIGNED_LONGS_EQUAL(45, mathP->nCr(10, 2));
	UNSIGNED_LONGS_EQUAL(50, mathP->nCr(50, 49));
}

TEST(MathUtilsTestGroup, Test10)
{
	UNSIGNED_LONGS_EQUAL(3, mathP->nPr(3, 1));
	UNSIGNED_LONGS_EQUAL(840, mathP->nPr(7, 4));
	UNSIGNED_LONGS_EQUAL(90, mathP->nPr(10, 2));
}



TEST(MathUtilsTestGroup, Test11)
{
	vector<int> expectedDivisors;
	int arr[] = { 1,2,3,4,6,9,12,18,36 };
	for (int i = 0; i < 9; i++) {
		expectedDivisors.push_back(arr[i]);
	}
	vector<int> divs = mathP->getDivisors(36);
	CHECK(expectedDivisors.size() == divs.size());
	for (int i = 0; i < divs.size(); i++)
	{
		LONGS_EQUAL(expectedDivisors[i], divs[i]);
	}
}

TEST(MathUtilsTestGroup, Test12)
{
	vector<int> expectedDivisors;
	int arr[] = { 1, 1000000007 };
	for (int i = 0; i < 2; i++) {
		expectedDivisors.push_back(arr[i]);
	}
	vector<int> divs = mathP->getDivisors(1000000007);
	CHECK(expectedDivisors.size() == divs.size());
	for (int i = 0; i < divs.size(); i++)
	{
		LONGS_EQUAL(expectedDivisors[i], divs[i]);
	}
}