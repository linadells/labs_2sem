#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
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

template <typename T>
class cString {
	vector<T> str;
public:
	//конструктори
	cString(vector<T> text) {
		str = text;
	}
	//методи
	/*void deleteElem(T sym) {
		T temp[256];
		try {
			if (!quantElem(sym))
				throw cDeletingElem();
		}
		catch (const cDeletingElem& del) {
			cout << "Error:" << del.getMessage();
		}
		for (int i = 0, j = 0; j < str.size(); j++) {
			if (str[j] != sym) {
				temp[i] = str[j];
				i++;
			}
		}
		for (int i = 0; i < str.size(); i++) {
			str[i] = temp[i];
		}
	}
	int quantElem(T sym) {
		int num = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == sym) {
				num++;
			}
		}
		return num;
	}
	void insertStr(int pos, const T* ins) {
		try {
			if (pos > str.size())
				throw cInserting();
		}
		catch (const cInserting& ins) {
			cout << "Error:" << ins.getMessage();
		}
		T temp[256];
		for (int i = 0; i < pos; i++) {
			temp[i] = str[i];
		}
		for (int i = 0; i < strlen(ins); i++) {
			temp[pos + i] = ins[i];
		}
		for (int i = pos; i < str.size(); i++) {
			temp[strlen(ins) + i] = str[i];
		}
		for (int i = 0; i < str.size(); i++) {
			str[i] = temp[i];
		}
	}*/
	int searchStr(cString& sear) {
		auto it = str.begin();
		it = search(str.begin(), str.end(), sear.str.begin(), sear.str.end());
		return (it - str.begin() + 1);
	}
	void sortIncrease() {
		sort(str.begin(), str.end());
	}
	void sortDecrease() {
		sort(str.begin(), str.end(), greater<T>());
		//reverse(str.begin(), str.end());
	}
	bool isStart(cString& start) {
		return equal(str.begin(), str.begin()+start.str.size(), start.str.begin());
	}
	bool isEnd(cString& ending)
	{
		return equal(str.end()- ending.str.size(), str.end(), ending.str.begin());
	}
	string returnStr() {
		string retStr(str.begin(), str.end());
		return retStr;
	}
	//оператори
	/*cString& operator=(const cString& copy) {
		if (&copy == this)
			return *this;
		delete[] str;
		str = copy.str;
		return *this;
	}
	cString& operator=(cString&& copy) {
		if (&copy == this)
			return *this;
		delete[] str;
		str = copy.str;
		copy.str = NULL;
		return *this;
	}
	cString operator+ (cString dod) {
		cString temp;
		for (int i = 0; i < this->str.size(); i++) {
			temp.str[i] = this->str[i];
		}
		for (int i = 0; i < dod.str.size(); i++) {
			temp.str[i + this->str.size()] = dod.str[i];
		}
		return temp;
	}
	cString operator- (cString vid) {
		try {
			if (!strcmp(vid.getStr(), ""))
				throw cDeletingStr();
		}
		catch (const cDeletingStr& del) {
			cout << "Error:" << del.getMessage();
			return 0;
		}
		if (this->str.size() < vid.str.size())
			return *this;
		int pos = searchStr(vid.str);
		if (!pos) return *this;
		cString temp(str.size() - vid.str.size() + 1);
		for (int i = 0; i < pos; i++) {
			temp.str[i] = str[i];
		}
		for (int i = pos; i < temp.size; i++) {
			temp.str[i] = str[i + vid.size - 1];
		}
		return temp;
	}
	bool operator==(cString obj) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != obj.str[i])
				return false;
		}
		return true;
	}*/
	T operator[](int i) {
		return str[i];
	}
	friend ostream& operator<< (ostream& out, const cString& obj) {
		for_each(obj.str.begin(), obj.str.end(), [](const T el) {cout << el; });
		return out;
	}
	friend istream& operator>>(istream& in, cString& obj) {
		T temp[256];
		in >> temp;
		for (int i = 0; i < strlen(temp); i++) {
			obj.str[i] = temp[i];
		}
		return in;
	}
	bool operator<(cString& comp) {
		return lexicographical_compare(str.begin(), str.end(), comp.str.begin(), comp.str.end());
	}
};

