#pragma once
class CSolidFigure {
protected:
	double area, volume;
public:
	void setArea(double area) { this->area = area; }
	void setVolume(double volume) { this->volume = volume; }
	double getArea() { return area; }
	double getVolume() { return volume; }
	void PrintName();
};

class CCylinder : protected CSolidFigure {
	double h, r;
public:
	CCylinder();
	CCylinder(double h, double r);
	double areaMethod();
	double volumeMethod();
	void PrintName();
	double getH() { return h; }
	double getR() { return r; }
	void setH(double h) { this->h = h; }
	void setR(double r) { this->r = r; }
};

class CSphere : protected CSolidFigure {
	double r;
public:
	CSphere();
	CSphere(double r);
	double areaMethod();
	double volumeMethod();
	void PrintName();
	double getR() { return r; }
	void setR(double r) { this->r = r; }
};

class CCube : protected CSolidFigure {
	double a;
public:
	CCube();
	CCube(double a);
	double areaMethod();
	double volumeMethod();
	void PrintName();
	double getA() { return a; }
	void setA(double a) { this->a = a; }
};