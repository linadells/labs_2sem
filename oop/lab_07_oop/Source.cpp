#include"Header.h"
#include<iostream>
#define P 3.14
using namespace std;

void CSolidFigure::PrintName() {
	cout << "Colid figure\n";
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
double CCylinder::getArea() {
	double sq = 2 * P * r * (r + h);
	this->setArea(sq);
	return sq;
}
double CCylinder::getVolume() {
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
double CSphere::getArea() {
	double sq = 4 * P * r * r;
	this->setArea(sq);
	return sq;
}
double CSphere::getVolume() {
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
CCube::CCube(double a) {
	this->a = a;
}
double CCube::getArea() {
	double sq = 6 * a * a;
	this->setArea(sq);
	return sq;
}
double CCube::getVolume() {
	double vol = a * a * a;
	this->setVolume(vol);
	return vol;
}
void CCube::PrintName() {
	cout << "Cube\n";
}

void searchMinAndMax(unique_ptr<CSolidFigure>* figure, int quant, 
	double& minArea, double& maxArea, double& minVolume, double& maxVolume) {
	maxArea = figure[0]->getArea(), minArea = figure[0]->getArea();
	maxVolume = figure[0]->getVolume(), minVolume = figure[0]->getArea();
	for (int i = 1; i < quant; i++) {
		if (figure[i]->getArea() > maxArea) {
			maxArea = figure[i]->getArea();
		}
		if (figure[i]->getArea() < minArea) {
			minArea = figure[i]->getArea();
		}
		if (figure[i]->getVolume() > maxArea) {
			maxVolume = figure[i]->getArea();
		}
		if (figure[i]->getVolume() < minArea) {
			minVolume = figure[i]->getArea();
		}
	}
}
