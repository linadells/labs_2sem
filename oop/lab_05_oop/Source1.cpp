#define _CRT_SECURE_NO_WARNINGS
#include"Header1.h"
#include<string.h>
using namespace std;
cStringUnique::cStringUnique() {
	this->size = 256;
	this->str = make_unique<char[]>(size+1);
}
cStringUnique::cStringUnique(int size) {
	this->size = size;
	this->str = make_unique<char[]>(size + 1);
}
cStringUnique::cStringUnique(int size, const char* str) {
	this->size = size;
	this->str = make_unique<char[]>(size+1);
	for (int i = 0; i < size; i++) {
		this->str[i] = str[i];
	}
}
void cStringUnique::deleteElem(char sym) {
	char temp[256];
	int newSize = size - quantElem(sym);
	//cStringUnique temp(newSize);
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
int cStringUnique::quantElem(char sym) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] == sym) {
			num++;
		}
	}
	return num;
}
void cStringUnique::sortIncrease() {
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
void cStringUnique::sortDecrease() {
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
void cStringUnique::insertStr(int pos, const char* ins) {
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
int cStringUnique::searchStr(const char* search) {
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
char cStringUnique::getSym(int num) {
	return str[num];
}
cStringUnique::cStringUnique(const cStringUnique& copy) {
	str = make_unique<char[]>(copy.size + 1);
	size = copy.size;
	for (int i = 0; i < size; i++) {
		str[i] = copy.str[i];
	}
}
cStringUnique cStringUnique::operator=(const cStringUnique& copy) {
	if (&copy == this)
		return *this;
	delete str.get();
	str = make_unique<char[]>(copy.size + 1);
	size = copy.size;
	for (int i = 0; i < size; i++) {
		str[i] = copy.str[i];
	}
	return *this;
}
cStringUnique::cStringUnique(cStringUnique&& copy) {
	size = copy.size;
	for (int i = 0; i < size; i++) {
		str[i] = copy.str[i];
	}
	copy.size = 0;
	copy.str = NULL;
}
cStringUnique cStringUnique:: operator=(cStringUnique&& copy) {
	if (&copy == this)
		return *this;
	delete str.get();
	size = copy.size;
	for (int i = 0; i < size; i++) {
		str[i] = copy.str[i];
	}
	copy.size = 0;
	copy.str = NULL;
	return *this;
}
cStringUnique cStringUnique:: operator+ (cStringUnique dod) {
	cStringUnique temp(this->size + dod.size - 1);
	for (int i = 0; i < this->size - 1; i++) {
		temp.str[i] = this->str[i];
	}
	for (int i = 0; i < dod.size; i++) {
		temp.str[i + this->size - 1] = dod.str[i];
	}
	return temp;
}
cStringUnique cStringUnique:: operator- (cStringUnique vid) {
	if (size < vid.size)
		return *this;
	int pos = searchStr(vid.str.get());
	if (!pos) return *this;
	cStringUnique temp(size - vid.size + 1);
	for (int i = 0; i < pos; i++) {
		temp.str[i] = str[i];
	}
	for (int i = pos; i < temp.size; i++) {
		temp.str[i] = str[pos + vid.size - 1];
	}
	return temp;
}
ostream& operator<< (ostream& out, const cStringUnique& obj) {
	for (int i = 0; i < obj.size; i++) {
		out << obj.str[i];
	}
	return out;
}
istream& operator>>(istream& in, cStringUnique& obj) {
	in >> obj.str.get();
	obj.size = strlen(obj.str.get()) + 1;
	return in;
}