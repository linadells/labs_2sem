#include<iostream>
#include<exception>
#include"Header.h"
using namespace std;
int main() {
	const int iElem[5] = { 1,2,3,4,5 }, iElem2[2] = { 6,7 };
	cString<char>* el = new cString<char>(2, "a");
	const short int shElem[2] = {1,2};
	cString<char>* objChar = new cString<char>(5, "char");
	cString<int>* objInt = new cString<int>(5, iElem);
	cString<int>* objInt2 = new cString<int>(2, iElem2);
	cString<short int>* objShInt = new cString<short int>(2, shElem);
	cout << "Char str:" << *objChar << endl;
	cout << "Int str:" << *objInt << endl;
	cout << "Short int str:" << *objShInt << endl;
	objInt->sortDecrease();
	cout << "Int string sorted decreasly:" << *objInt << endl;
	cout << "3 sym in char string:" << (*objChar)[2] << endl;
	objShInt->deleteElem(2);
	cout << "Short int string without '2':" << *objShInt << endl;
	if (*objInt == *objInt2) cout << *objInt << "is the same as " << *objInt2 << endl;
	else cout << *objInt << " isn`t the same as " << *objInt2 << endl;
	cout << *objInt << "+" << *objInt2 << "=";
	cout<< *objInt + *objInt2<<endl;
	cString<char> obj(5, "char");
	cout << "Letter 'a' is in " << FindElementInArray<char>(*objChar, 'a', objChar->getSize())
		<< " position in string " <<*objChar<< endl;
	cout << "'5' is in " << FindElementInArray<const int>(iElem, 5, 5)
		<< " position in array " << endl;
	return 0;
}