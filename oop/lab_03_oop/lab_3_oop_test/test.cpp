#include "pch.h"
#include "../lab_03_oop/Header.h"
TEST(TestSet, Test) {
	CVector test;
	test.set(1, 2, 3);
	EXPECT_EQ(test.getX(), 1);
	EXPECT_EQ(test.getY(), 2);
	EXPECT_EQ(test.getZ(), 3);
}
TEST(TestConstr, TestZam) {
	CVector test;
	EXPECT_EQ(test.getX(), 1);
	EXPECT_EQ(test.getY(), 1);
	EXPECT_EQ(test.getZ(), 1);
}
TEST(TestConstr, TestStand) {
	CVector test(1, 2, 3);
	EXPECT_EQ(test.getX(), 1);
	EXPECT_EQ(test.getY(), 2);
	EXPECT_EQ(test.getZ(), 3);
}
TEST(TestConstr, TestStr) {
	CVector test('1', '2', '3');
	EXPECT_EQ(test.getX(), 1);
	EXPECT_EQ(test.getY(), 2);
	EXPECT_EQ(test.getZ(), 3);
}
TEST(TestSumVect, Test) {
	CVector test;
	int x = 1, y = 2, z = 3;
	test.sumVect(&x, &y, &z);
	EXPECT_EQ(x, 2);
	EXPECT_EQ(y, 3);
	EXPECT_EQ(z, 4);

	test.set(7, 8, 9);
	x = 1, y = 2, z = 3;
	test.sumVect(&x, &y, &z);
	EXPECT_EQ(x, 8);
	EXPECT_EQ(y, 10);
	EXPECT_EQ(z, 12);
}
TEST(TestDedVect, Test) {
	CVector test;
	int x = 1, y = 2, z = 3;
	test.dedVect(&x, &y, &z);
	EXPECT_EQ(x, 0);
	EXPECT_EQ(y, 1);
	EXPECT_EQ(z, 2);

	test.set(7, 8, 9);
	x = 1, y = 2, z = 3;
	test.dedVect(&x, &y, &z);
	EXPECT_EQ(x, -6);
	EXPECT_EQ(y, -6);
	EXPECT_EQ(z, -6);
}
TEST(TestSkalDob, Test) {
	CVector test;
	int iResult = test.skalDob(2,2,2);
	EXPECT_EQ(iResult, 6);
	iResult = test.skalDob(-3, 0, 2);
	EXPECT_EQ(iResult, -1);
	iResult = test.skalDob(0,0,0);
	EXPECT_EQ(iResult, 0);

	test.set(1, 2, 3);
	iResult = test.skalDob(1, 1, 1);
	EXPECT_EQ(iResult, 6);
	iResult = test.skalDob(3, 2, 1);
	EXPECT_EQ(iResult, 10);
}
TEST(TestVectDob, Test) {
	CVector test;
	int x = 1, y = 2, z = 3;
	test.vectDob(&x, &y, &z);
	EXPECT_EQ(x, 1);
	EXPECT_EQ(y, -2);
	EXPECT_EQ(z, 1);

	test.set(7, 8, 9);
	x = 1, y = 2, z = 3;
	test.vectDob(&x, &y, &z);
	EXPECT_EQ(x, 6);
	EXPECT_EQ(y, -12);
	EXPECT_EQ(z, 6);
}
TEST(TestDobNaSkal, Test) {
	CVector test(1, 2, 3);
	test.dobNaSkal(3);
	EXPECT_EQ(test.getX(), 3);
	EXPECT_EQ(test.getY(), 6);
	EXPECT_EQ(test.getZ(), 9);
	test.set(4, 5, 6);
	test.dobNaSkal(-1);
	EXPECT_EQ(test.getX(), -4);
	EXPECT_EQ(test.getY(), -5);
	EXPECT_EQ(test.getZ(), -6);
}
TEST(TestLen, Test) {
	CVector test(1, 2, 3);
	double dResult = test.len();
	EXPECT_DOUBLE_EQ(dResult, pow(14, 0.5));
	test.set(4, -5, 6);
	dResult = test.len();
	EXPECT_DOUBLE_EQ(dResult, pow(77, 0.5));
}


