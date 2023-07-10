#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;
class cString {
	int size;
	char* str;
public:
	//конструктори
	cString();
	cString(int size);
	cString(int size, const char* str);
	cString(const cString& copy);
	cString(cString&& copy);
	//методи
	void deleteElem(char sym);
	int quantElem(char sym);
	void sortIncrease();
	void sortDecrease();
	void insertStr(int pos, const char* ins);
	int searchStr(const char* search);
	//гетери
	char getSym(int num);
	char* getStr() { return str; }
	//присвоЇнн€ 
	cString& operator=(const cString& copy);
	cString& operator=(cString&& copy);
	~cString();
	//оператори
	cString operator+ (cString dod);
	cString operator- (cString dod);
	char operator[](int i);
	friend ostream& operator<< (ostream& out, const cString& obj);
	friend istream& operator>>(istream& in, cString& obj);
};