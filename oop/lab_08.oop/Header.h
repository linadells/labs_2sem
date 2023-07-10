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
	void deleteElemNum(int num);
	//гетери
	char getSym(int num);
	const char* getStr() const { return str; }
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
class cDeletingElem {
public:
	cDeletingElem() = default;
	const char* getMessage() const {
		return "Deleting non-existing symbol\n";
	}
};
class cInserting {
public:
	cInserting() = default;
	const char* getMessage() const {
		return "Inserting to non-existing position\n";
	}
};
class cDeletingStr {
public:
	cDeletingStr() = default;
	const char* getMessage() const {
		return "Deleting empty string\n";
	}
};
class cInputing {
public:
	cInputing() = default;
	const char* getMessage() const {
		return "Too big string\n";
	}
};
class cOutputing {
public:
	cOutputing() = default;
	const char* getMessage() const {
		return "Error of outputing\n";
	}
};
class cMemory : bad_alloc {
public:
	cMemory() = default;
	const char* what() const {
		return "Lack of free memory\n";
	}
};