#pragma once
#include<stdlib.h>
class CVector {
	int mX;
	int mY;
	int mZ;
public:
	CVector() {
		mX = 1;
		mY = 1;
		mZ = 1;
	}
	CVector(int x, int y, int z) {
		mX = x;
		mY = y;
		mZ = z;
	}
	CVector(char x, char y, char z) {
		mX = x-48;
		mY = y-48;
		mZ = z-48;
	}
	int getX() { return mX; };
	int getY() { return mY; };
	int getZ() { return mZ; };
	void set(int xx, int yy, int zz);
	void sumVect(int* x, int* y, int* z);
	void dedVect(int* x, int* y, int* z);
	int skalDob(int x, int y, int z);
	void vectDob(int* x, int* y, int* z);
	void dobNaSkal(int s);
	double len();
};