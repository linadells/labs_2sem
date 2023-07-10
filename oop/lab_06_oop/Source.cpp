#include"Header.h"
#include<iostream>
#define P 3.14
using namespace std;
void CSolidFigure::PrintName() {
	cout << "Solid figure\n";
}
//циліндр
CCylinder::CCylinder() {
	h = 1;
	r = 1;
}
CCylinder::CCylinder(double h, double r) {
	this->h = h;
	this->r = r;
}
double CCylinder::areaMethod() {
	double sq = 2 * P * r * (r + h);
	this->setArea(sq);
	return sq;
}
double CCylinder::volumeMethod() {
	double vol = 2 * P * r * r * h;
	this->setVolume(vol);
	return vol;
}
void CCylinder::PrintName() {
	cout << "Cylinder\n";
}
//сфера
CSphere::CSphere() {
	r = 1;
}
CSphere::CSphere(double r) {
	this->r = r;
}
double CSphere::areaMethod() {
	double sq = 4 * P * r * r;
	this->setArea(sq);
	return sq;
}
double CSphere::volumeMethod() {
	double vol = 4.0 / 3.0 * r * r * r * P;
	this->setVolume(vol);
	return vol;
}
void CSphere::PrintName() {
	cout << "Sphere\n";
}
//куб
CCube::CCube() {
	this->a = 1;
}
CCube:: CCube(double a) {
	this->a = a;
}
double CCube::areaMethod() {
	double sq = 6 * a * a;
	this->setArea(sq);
	return sq;
}
double CCube::volumeMethod() {
	double vol = a * a * a;
	this->setVolume(vol);
	return vol;
}
void CCube::PrintName() {
	cout << "Cube\n";
}