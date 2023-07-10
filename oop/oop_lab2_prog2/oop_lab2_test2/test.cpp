#include "pch.h"
#include "../oop_lab2_prog2/lab2.h"

TEST(GetGCD, TestCornerCases) {
	unsigned int uiResult = GetGCD(0, 0);
  EXPECT_EQ(uiResult, -1);
}
TEST(GetGCD, TestValidInput) {
	unsigned int uiResult = GetGCD(0, 5);
	EXPECT_EQ(uiResult, 5);
	uiResult = GetGCD(4, 0);
	EXPECT_EQ(uiResult, 4);
	uiResult = GetGCD(18,30);
	EXPECT_EQ(uiResult, 6);
	uiResult = GetGCD(2, 22);
	EXPECT_EQ(uiResult, 2);
}