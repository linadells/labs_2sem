#include<iostream>
#include<exception>
#include"Header.h"
using namespace std;
int main() {
	int i=0;
	while (i != 7) {
		cout << "\nMenu:\n1-delete unexisting symbol\n"
			"2-delete empty string\n3-insert string to unexisting position\n"
			"4-create too big array\n5-input invalid data\n"
			"6-output invalid data\n7-end program\n\nEnter your choise:";
		cin >> i;
		cString* obj = new cString(5, "smth");
		cString* empty = new cString(1, "");
		if(i==1)
			obj->deleteElemNum(10);
		if(i==3)
			obj->insertStr(6, "Insert");
		if(i==2)
			*obj - *empty;
		if (i == 4) {
			try {
				cString* arr = new cString[10000000000];
			}
			catch (const bad_alloc& mem) {
				cout << "Error:" << mem.what();
			}
		}
		if (i == 5){
			cout << "Enter string:";
			cin >> *obj;
		}
		if (i == 6) {
			cout << *empty;
		}
	}
	return 0;
}