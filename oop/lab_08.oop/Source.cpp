#define _CRT_SECURE_NO_WARNINGS
#include"Header.h"
#include<string.h>
using namespace std;
cString::cString() {
	this->size = 256;
	this->str = new char[size];
	this->str = NULL;
}
cString::cString(int size) {
	this->size = size;
	this->str = new char[size];
}
cString::cString(int size, const char* str) {
	this->size = size;
	this->str = new char[size];
	for (int i = 0; i < size; i++) {
		this->str[i] = str[i];
	}
}
void cString::deleteElem(char sym) {
	char temp[256];
	try {
		if (!quantElem(sym))
			throw cDeletingElem();
	}
	catch(const cDeletingElem& del){
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
void cString::deleteElemNum(int num) {
	char temp[256];
	try {
		if (num>size)
			throw cDeletingElem();
	}
	catch (const cDeletingElem& del) {
		cout << "Error:" << del.getMessage();
	}
	size--;
	for (int i = 0; i < size; i++) {
		if (i!=num) {
			temp[i] = str[i];
			i++;
		}
	}
	strcpy(str, temp);
}
int cString::quantElem(char sym) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] == sym) {
			num++;
		}
	}
	return num;
}
void cString::sortIncrease() {
	for (int step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < size; i++) {
			if (str[i] < str[min_idx])
				min_idx = i;
		}
		char temp = str[step];
		str[step] = str[min_idx];
		str[min_idx] = temp;
	}
}
void cString::sortDecrease() {
	for (int step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < size; i++) {
			if (str[i] > str[min_idx])
				min_idx = i;
		}
		char temp = str[step];
		str[step] = str[min_idx];
		str[min_idx] = temp;
	}
}
void cString::insertStr(int pos, const char* ins) {
	try {
		if (pos > size)
			throw cInserting();
	}
	catch(const cInserting& ins){
		cout << "Error:" << ins.getMessage();
	}
	int newSize = size + strlen(ins);
	char temp[256];
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
int cString::searchStr(const char* search) {
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
char cString::getSym(int num) {
	return str[num];
}
cString::cString(const cString& copy) {
	str = new char[copy.size];
	size = copy.size;
	str = copy.str;
}
cString& cString::operator=(const cString& copy) {
	if (&copy == this)
		return *this;
	delete[] str;
	str = new char[copy.size];
	size = copy.size;
	str = copy.str;
	return *this;
}
cString::cString(cString&& copy) {
	size = copy.size;
	str = copy.str;
	copy.size = 0;
	copy.str = NULL;
}
cString& cString:: operator=(cString&& copy) {
	if (&copy == this)
		return *this;
	delete[] str;
	size = copy.size;
	str = copy.str;
	copy.size = 0;
	copy.str = NULL;
	return *this;
}
cString:: ~cString() {
	size = 0;
	if (str) {
		delete[] str;
	}
}
cString cString:: operator+ (cString dod) {
	cString temp(this->size + dod.size - 1);
	for (int i = 0; i < this->size - 1; i++) {
		temp.str[i] = this->str[i];
	}
	for (int i = 0; i < dod.size; i++) {
		temp.str[i + this->size - 1] = dod.str[i];
	}
	return temp;
}
cString cString:: operator- (cString vid) {
	try {
		if (!strcmp(vid.getStr(), ""))
			throw cDeletingStr();
	}
	catch(const cDeletingStr& del){
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
ostream& operator<< (ostream& out, const cString& obj) {
	try {
		if (!strcmp(obj.getStr(), ""))
			throw cOutputing();
	}
	catch (const cOutputing& out) {
		cout << "Error:" << out.getMessage();
	}
	for (int i = 0; i < obj.size; i++) {
		out << obj.str[i];
	}
	return out;
}
istream& operator>>(istream& in, cString& obj) {
	char temp[256];
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
char cString::operator[](int i) {
	return *(str + i);
}