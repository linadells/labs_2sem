#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;
class cStringUnique {
	int size;
	unique_ptr<char[]> str;
public:
	cStringUnique();
	cStringUnique(int size);
	cStringUnique(int size, const char* str);
	cStringUnique(const cStringUnique& copy);
	cStringUnique(cStringUnique&& copy);
	void deleteElem(char sym);
	int quantElem(char sym);
	void sortIncrease();
	void sortDecrease();
	void insertStr(int pos, const char* ins);
	int searchStr(const char* search);
	char getSym(int num);
	cStringUnique operator=(const cStringUnique& copy);
	cStringUnique operator=(cStringUnique&& copy);
	cStringUnique operator+ (cStringUnique dod);
	cStringUnique operator- (cStringUnique dod);
	friend ostream& operator<< (ostream& out, const cStringUnique& obj);
	friend istream& operator>>(istream& in, cStringUnique& obj);
};