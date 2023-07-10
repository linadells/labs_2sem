#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	CCylinder cylinder(3, 4);
	CCube cube(5);
	CSphere sphere(4);
	ofstream out("out.txt");
	double a, b;
	
	out << "Culinder \nHight:" << cylinder.getH() << "\nRasius:" << cylinder.getR() <<
		"\nArea:" << cylinder.areaMethod() << "\nVolume:" << cylinder.areaMethod()
		<< "\n\nCube \nLength:" << cube.getA() <<
		"\nArea:" << cube.areaMethod() << "\nVolume:" << cube.areaMethod()
		<< "Sphere \n" << "\nRasius:" << sphere.getR() <<
		"\nArea:" << sphere.areaMethod() << "\nVolume:" << sphere.areaMethod();

	cylinder.PrintName();
	cout << "Enter R and H:";
	cin >> a>>b;
	cylinder.setR(a);
	cylinder.setH(b);
	cout << "Area:" << cylinder.areaMethod() << "\nVolume:" << cylinder.volumeMethod()<<endl<<endl;

	cube.PrintName();
	cout << "Enter A:";
	cin >> a;
	cube.setA(a);
	cout << "Area:" << cube.areaMethod() << "\nVolume:" << cube.volumeMethod()<<endl << endl;

	sphere.PrintName();
	cout << "Enter R:";
	cin >> a;
	sphere.setR(a);
	cout << "Area:" << sphere.areaMethod() << "\nVolume:" << sphere.volumeMethod()<<endl << endl;
	return 0;
}