#include"Header.h"
#include<math.h>
void CVector::set(int xx, int yy, int zz) {
	mX = xx;
	mY = yy;
	mZ = zz;
}
void CVector:: sumVect(int* x, int* y, int* z) {
	*x = *x + mX;
	*y = *y + mY;
	*z = *z + mZ;
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
void CVector::vectDob(int* x, int* y, int* z) {
	int tempX=*x, tempY=*y, tempZ=*z;
	*x = mY * tempZ - mZ * tempY;
	*y = -(mX * tempZ - mZ * tempX);
	*z = (mX * tempY - mY * tempX);
}
void CVector::dobNaSkal(int s) {
	mX = mX * s;
	mY = mY * s;
	mZ = mZ * s;
}
double CVector::len() {
	double res = pow(mX * mX + mY * mY + mZ * mZ, 0.5);
	return res;
}