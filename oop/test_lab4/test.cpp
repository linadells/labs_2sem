#include "pch.h"
#include "../lab_04_oop/Header.h"
int CVector::countVect = 0;
TEST(TestSumOp, TestName) {
	CVector first, second(1, 2, 3), third(4, 5, 6);
	first = second + third;
	EXPECT_EQ(first.getX(), 5);
	EXPECT_EQ(first.getY(), 7);
	EXPECT_EQ(first.getZ(), 9);
}
TEST(TestDedOp, TestName) {
	CVector first, second(1, 2, 3), third(4, 5, 6);
	first = third - second;
	EXPECT_EQ(first.getX(), 3);
	EXPECT_EQ(first.getY(), 3);
	EXPECT_EQ(first.getZ(), 3);
}
TEST(TestSkalDobOp, TestName) {
	CVector first, second(1, 2, 3);
	int res = first * second;
	EXPECT_EQ(res, 6);
}
TEST(TestVectDobOp, TestName) {
	CVector first, second(1, 2, 3), third(4, 5, 6);
	first = third % second;
	EXPECT_EQ(first.getX(), 3);
	EXPECT_EQ(first.getY(), -6);
	EXPECT_EQ(first.getZ(), 3);
}
TEST(TestDobNaSkal, TestName) {
	CVector first(1, 2, 3);
	fri_dobNaSkal(first, 3);
	EXPECT_EQ(first.getX(), 3);
	EXPECT_EQ(first.getY(), 6);
	EXPECT_EQ(first.getZ(), 9);
}
TEST(TestBigger, TestName) {
	CVector first(1, 2, 3), second(4, 5, 6);
	bool res = first > second;
	EXPECT_EQ(res, 0);
	res = second > first;
	EXPECT_EQ(res, 1);
}
TEST(TestSmaller, TestName) {
	CVector first(1, 2, 3), second(4, 5, 6);
	bool res = first < second;
	EXPECT_EQ(res, 1);
	res = second < first;
	EXPECT_EQ(res, 0);
}
TEST(TestEqual, TestName) {
	CVector first(1, 2, 3), second(4, 5, 6);
	bool res = first == second;
	EXPECT_EQ(res, 0);
	first = second;
	res = second == first;
	EXPECT_EQ(res, 1);
}