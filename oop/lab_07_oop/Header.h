#pragma once
#include<iostream>
using namespace std;
class CSolidFigure {
protected:
	double area, volume;
public:
	virtual ~CSolidFigure() {}
	void setArea(double area) { this->area = area; }
	void setVolume(double volume) { this->volume = volume; }

	virtual double getArea() const = 0;
	virtual double getVolume() const = 0;
	virtual void PrintName() = 0;
};

class CCylinder : public CSolidFigure {
	double h, r;
public:
	CCylinder();
	CCylinder(double h, double r);

	double getArea();
	double getVolume();
	void PrintName();

	double getH() { return h; }
	double getR() { return r; }
	void setH(double h) { this->h = h; }
	void setR(double r) { this->r = r; }
};

class CSphere : public CSolidFigure {
	double r;
public:
	CSphere();
	CSphere(double r);

	double getArea();
	double getVolume();
	void PrintName();

	double getR() { return r; }
	void setR(double r) { this->r = r; }
};

class CCube : public CSolidFigure {
	double a;
public:
	CCube();
	CCube(double a);

	double getArea();
	double getVolume();
	void PrintName();

	double getA() { return a; }
	void setA(double a) { this->a = a; }
};

void searchMinAndMax(unique_ptr<CSolidFigure>* figure, int quant, 
	double& minArea,	double& maxArea, double& minVolume, double& maxVolume);

