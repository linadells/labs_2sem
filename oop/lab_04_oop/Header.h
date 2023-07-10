#pragma once
#include<stdlib.h>
#include<iostream>
using namespace std;
class CVector {
	int mX, mY, mZ;
	static int countVect;
public:
	CVector() :mX(1), mY(1), mZ(1) { CVector::countVect++; };
	CVector(int x, int y, int z) : mX(x), mY(y), mZ(z) { CVector::countVect++; };
	CVector(char x, char y, char z) : mX(x - 48), mY(y - 48), mZ(z - 48) { CVector::countVect++; };
	static void setCountVect(int count);
	static int getCountVect();
	int getX() { return mX; };
	int getY() { return mY; };
	int getZ() { return mZ; };
	void set(int xx, int yy, int zz);
	void sumVect(int* x, int* y, int* z);
	void sumVect(CVector& vect);
	void dedVect(int* x, int* y, int* z);
	int skalDob(int x, int y, int z);
	int skalDob(CVector vect);
	void vectDob(int* x, int* y, int* z);
	void dobNaSkal(int s);
	void dobNaSkal(double s);
	double len();
	CVector operator+(CVector& per);
	CVector operator-(CVector& per);
	double operator*(CVector per);
	CVector operator%(CVector& per);
	friend ostream& operator<<(ostream& out, const CVector obj);
	friend istream& operator>>(istream& in, CVector& obj);
	friend CVector fri_dobNaSkal(CVector& obj, int s);
	friend bool operator>(CVector obj1, CVector obj2);
	friend bool operator<(CVector obj1, CVector obj2);
	friend bool operator==(CVector obj1, CVector obj2);
};