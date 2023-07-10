#include<stdio.h>
unsigned int GetGCD(unsigned int uiFirst, unsigned int uiSecond) {
	if (!uiFirst && !uiSecond) {
		printf("Both values can`t be 0\n");
		return -1;
	}
	if (!uiSecond) {
		return uiFirst;
	}
	unsigned int uiTemp = 0;
	while (uiSecond) {
		uiTemp = uiSecond;
		uiSecond = uiFirst % uiSecond;
		uiFirst = uiTemp;
	}
	return uiFirst;
}