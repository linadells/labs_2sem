#pragma once
#include<iostream>
#include<stdio.h>
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
	int size;
	T* str;
public:
	//конструктори
	cString() {
		this->size = 256;
		this->str = new T[size];
		this->str = NULL;
	}
	cString(int size) {
		this->size = size;
		this->str = new T[size];
	}
	cString(int size, const T* str) {
		this->size = size;
		this->str = new T[size];
		for (int i = 0; i < size; i++) {
			this->str[i] = str[i];
		}
	}
	cString(const cString& copy) {
		str = new T[copy.size];
		size = copy.size;
		str = copy.str;
	}
	cString(cString&& copy) {
		size = copy.size;
		str = copy.str;
		copy.size = 0;
		copy.str = NULL;
	}
	//методи
	void deleteElem(T sym){ 
		T temp[256];
		try {
			if (!quantElem(sym))
				throw cDeletingElem();
		}
		catch (const cDeletingElem& del) {
			cout << "Error:" << del.getMessage();
		}
		int newSize = size - quantElem(sym);
		for (int i = 0, j = 0; j < size; j++) {
			if (str[j] != sym) {
				temp[i] = str[j];
				i++;
			}
		}
		size = newSize;
		for (int i = 0; i < size; i++) {
			str[i] = temp[i];
		}
	}
	int quantElem(T sym) {
		int num = 0;
		for (int i = 0; i < size; i++) {
			if (str[i] == sym) {
				num++;
			}
		}
		return num;
	}
	void sortIncrease() {
		for (int step = 0; step < size - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < size; i++) {
				if (str[i] < str[min_idx])
					min_idx = i;
			}
			T temp = str[step];
			str[step] = str[min_idx];
			str[min_idx] = temp;
		}
	}
	void sortDecrease() {
		for (int step = 0; step < size - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < size; i++) {
				if (str[i] > str[min_idx])
					min_idx = i;
			}
			T temp = str[step];
			str[step] = str[min_idx];
			str[min_idx] = temp;
		}
	}
	void insertStr(int pos, const T* ins) {
		try {
			if (pos > size)
				throw cInserting();
		}
		catch (const cInserting& ins) {
			cout << "Error:" << ins.getMessage();
		}
		int newSize = size + strlen(ins);
		T temp[256];
		for (int i = 0; i < pos; i++) {
			temp[i] = str[i];
		}
		for (int i = 0; i < strlen(ins); i++) {
			temp[pos + i] = ins[i];
		}
		for (int i = pos; i < size; i++) {
			temp[strlen(ins) + i] = str[i];
		}
		size = newSize;
		for (int i = 0; i < size; i++) {
			str[i] = temp[i];
		}
	}
	int searchStr(const T* search) {
		int i, j = 0;
		for (i = 0; i < size && j != strlen(search); i++) {
			if (str[i] == search[j]) {
				j++;
			}
		}
		if (j == strlen(search)) {
			return i - strlen(search);
		}
		else {
			return 0;
		}
	}
	void deleteElemNum(int num) {
		T temp[256];
		try {
			if (num > size)
				throw cDeletingElem();
		}
		catch (const cDeletingElem& del) {
			cout << "Error:" << del.getMessage();
		}
		size--;
		for (int i = 0; i < size; i++) {
			if (i != num) {
				temp[i] = str[i];
				i++;
			}
		}
		strcpy(str, temp);
	}
	//гетери
	const T* getStr() const { return str; }
	int getSize() { return size; }
	//присвоЇнн€ 
	cString& operator=(const cString& copy) {
		if (&copy == this)
			return *this;
		delete[] str;
		str = new T[copy.size];
		size = copy.size;
		str = copy.str;
		return *this;
	}
	cString& operator=(cString&& copy) {
		if (&copy == this)
			return *this;
		delete[] str;
		size = copy.size;
		str = copy.str;
		copy.size = 0;
		copy.str = NULL;
		return *this;
	}
	//оператори
	cString operator+ (cString dod) {
		cString temp(this->size + dod.size);
		for (int i = 0; i < this->size; i++) {
			temp.str[i] = this->str[i];
		}
		for (int i = 0; i < dod.size; i++) {
			temp.str[i + this->size] = dod.str[i];
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
		if (size < vid.size)
			return *this;
		int pos = searchStr(vid.str);
		if (!pos) return *this;
		cString temp(size - vid.size + 1);
		for (int i = 0; i < pos; i++) {
			temp.str[i] = str[i];
		}
		for (int i = pos; i < temp.size; i++) {
			temp.str[i] = str[i + vid.size - 1];
		}
		return temp;
	}
	bool operator==(cString obj) {
		for(int i=0;i<size;i++){
			if(str[i]!=obj.str[i])
			return false;
		}
		return true;
	}
	T operator[](int i) {
		return *(str + i);
	}
	friend ostream& operator<< (ostream& out, const cString& obj) {
		for (int i = 0; i < obj.size; i++) {
			out << obj.str[i];
		}
		return out;
	}
	friend istream& operator>>(istream& in, cString& obj) {
		T temp[256];
		in >> temp;
		try {
			if (strlen(temp) > obj.size)
				throw cInputing();
		}
		catch (const cInputing& inp) {
			cout << "Error:" << inp.getMessage();
		}
		strcpy(obj.str, temp);
		return in;
	}
};

template <typename T>
int FindElementInArray(T* arr, int size, T elem) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) return i + 1;
	}
	return size;
}
template <typename T>
int FindElementInArray(cString<T> arr, T elem, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) return i + 1;
	}
	return size;
}