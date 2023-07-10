#include"Header.h"
#include"Header1.h"
using namespace std;
int main() {
	cString* str, * str2, * str3;
	str = new cString(11, "testString");
	str2 = new cString;
	str3 = new cString(4, "STR");
	int num;
	cout << "String:" << *str << endl;
	cout << "Quantity of 't':" << str->quantElem('t') << endl;
	str->deleteElem('t');
	cout << "String without 't':" << *str << endl << "Enter new string:";
	cin >> *str;
	str->sortIncrease();
	cout << "Inputed string sorted in alphabet order:" << *str << endl;
	str->sortDecrease();
	cout << "Inputed string sorted in back alphabet order:" << *str << endl;
	str->insertStr(2, "STR");
	cout << "New string:" << *str << endl;
	cout << "''STR'' is after " << str->searchStr("STR") << " letter" << endl;
	cout<<" Enter number of letter you want to type:";
	cin >> num;
	cout << "Letter:" << (*str)[num] << endl<<"Enter string:";
	cin >> *str2;
	cout << "Concatenated strings:" << *str + *str2 << endl;
	str2 = str3;
	cout << "String without 'STR':" << *str - *str2<<endl;
	cString temp(move(*str)), temp2;
	cout << "Created with moving constructor object:" << temp<<endl;
	temp2 = move(temp);
	cout << "Initialised with moving operator = object:" << temp2 << endl;

	cStringUnique* unique;
	unique = new cStringUnique(4, "uni");
	cout << "\n\nUnique:\n" << *unique << endl;
	unique->sortIncrease();
	cout << "Sorted string:" << *unique << endl;
	cout << "Quantity of 'u':" << unique->quantElem('u') << endl;
	return 0;
}