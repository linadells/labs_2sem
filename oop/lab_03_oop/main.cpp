#include<iostream>
#include"Header.h"
using namespace std;
int main() {
	CVector vect(1, 2, 3);
	int x=4, y=5, z=6;
	cout << "x=" << vect.getX() << "\ny=" << vect.getY()<<"\nz=" << vect.getZ()<< "\nlen=" << vect.len();
	vect.sumVect(&x, &y, &z);
	cout << "\nsum with (4,5,6)=(" << x << "," << y << "," << z << ")";
	x = 4, y = 5, z = 6;
	vect.dedVect(&x, &y, &z);
	cout << "\nded with (4,5,6)=(" << x << "," << y << "," << z << ")";
	x = 4, y = 5, z = 6;
	vect.vectDob(&x, &y, &z);
	cout << "\nvect dob with (4,5,6)=(" << x << "," << y << "," << z << ")";
	x = 4, y = 5, z = 6;
	cout << "\nskal dob with (4,5,6)=" << vect.skalDob(x, y, z);
	vect.dobNaSkal(3);
	cout << "\ndob for 3=(" << vect.getX() << "," << vect.getY() << "," << vect.getZ() << ")";
	return 0;
}