#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<iostream>
using namespace std;
int main() {
	const int num = 3;
	double minVol, maxVol, minArea, maxArea;
	unique_ptr<CSolidFigure> figure[] = {make_unique<CCube>(5), make_unique<CCylinder>(2,3), make_unique<CSphere>(4)};
	for (int i = 0; i < num; i++) {
		figure[i]->PrintName();
		cout << "Area:" << figure[i]->getArea() << "\nVolume:" << figure[i]->getVolume() << endl<<endl;
	}
	searchMinAndMax(figure, num, minArea, maxArea, minVol, maxVol);
	cout << "Min volume:" << minVol << "\nMax volume:" << maxVol << "\nMin area:" << minArea << "\nMax area:" << maxArea << endl;
	return 0;
}