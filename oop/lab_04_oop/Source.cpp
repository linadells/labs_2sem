#include"Header.h"
#include<math.h>
#include<iostream>
using namespace std;
void CVector::set(int xx, int yy, int zz) {
	mX = xx;
	mY = yy;
	mZ = zz;
}
void CVector::setCountVect(int count) {
	CVector::countVect = count;
}
int CVector::getCountVect() { return CVector::countVect; }
void CVector::sumVect(int* x, int* y, int* z) {
	*x = *x + mX;
	*y = *y + mY;
	*z = *z + mZ;
}
void CVector::sumVect(CVector& vect) {
	vect.mX = mX + vect.mX;
	vect.mY = mY + vect.mY;
	vect.mZ = mZ + vect.mZ;
}
void CVector::dedVect(int* x, int* y, int* z) {
	*x = *x - mX;
	*y = *y - mY;
	*z = *z - mZ;
}
int CVector::skalDob(int x, int y, int z) {
	int res = x * mX + y * mY + z * mZ;
	return res;
}
int CVector::skalDob(CVector vect) {
	int res = mX * vect.mX + mY * vect.mY + mZ * vect.mZ;
	return res;
}
void CVector::vectDob(int* x, int* y, int* z) {
	int tempX = *x, tempY = *y, tempZ = *z;
	*x = mY * tempZ - mZ * tempY;
	*y = -(mX * tempZ - mZ * tempX);
	*z = (mX * tempY - mY * tempX);
}
void CVector::dobNaSkal(int s) {
	mX = mX * s;
	mY = mY * s;
	mZ = mZ * s;
}
void CVector::dobNaSkal(double s) {
	mX = mX * s;
	mY = mY * s;
	mZ = mZ * s;
}
double CVector::len() {
	double res = pow(mX * mX + mY * mY + mZ * mZ, 0.5);
	return res;
}
CVector CVector:: operator+(CVector& per) {
	return CVector(mX + per.mX, mY + per.mY, mZ + per.mZ);
}
CVector CVector:: operator-(CVector& per) {
	return CVector(mX - per.mX, mY - per.mY, mZ - per.mZ);
}
double CVector:: operator*(CVector per) {
	double res = mX * per.mX + mY * per.mY + mZ * per.mZ;
	return res;
}
CVector CVector:: operator%(CVector& per) {
	return CVector(mY * per.mZ - mZ * per.mY, -(mX * per.mZ - mZ * per.mX), mX * per.mY - mY * per.mX);
}
ostream& operator<<(ostream& out, const CVector obj) {
	out << "(" << obj.mX << "," << obj.mY << "," << obj.mZ << ")";
	return out;
}
istream& operator>>(istream& in, CVector& obj) {
	in >> obj.mX >> obj.mY >> obj.mZ;
	return in;
}
CVector fri_dobNaSkal(CVector& obj, int s) {
	obj.mX = obj.mX * s;
	obj.mY = obj.mY * s;
	obj.mZ = obj.mZ * s;
	return obj;
}
bool operator>(CVector obj1, CVector obj2) {
	if (obj1.len() > obj2.len()) return true;
	else return false;
}
bool operator<(CVector obj1, CVector obj2) {
	if (obj1.len() < obj2.len()) return true;
	else return false;
}
bool operator==(CVector obj1, CVector obj2) {
	if (obj1.len() == obj2.len()) return true;
	else return false;
}