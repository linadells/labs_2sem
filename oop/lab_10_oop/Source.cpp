#include"Header.h"
#include<map>
#include<iostream>
#include<unordered_set>
#include<queue>
int main() {
	int menu=0;
	while (menu != 5) {
		cout << "Menu:\n1-operations with cString\n2-oprations with std::map\n"
			"3-operations with std::unordered_multiset\n4-operations with std::priority_queue"
			"\n5-end program\nEnter your choise:";
		cin >> menu;
		if (menu == 1) {
			cout << "\ncString vith using std::vector\n\n";
			cString<char> obj({ 's','t','r','i','n','g' });
			cString<char> obj2({ 't','e','s','t' });
			cString<char> vect({ 's','t','r' });
			string str = vect.returnStr();
			cout << "String:" << obj << endl;
			cout << vect << " in " << obj << " is in " << obj.searchStr(vect) << " position\n";
			if (obj.isStart(vect)) {
				cout << obj << " begins with " << vect << endl;
			}
			else {
				cout << obj << " doesn't begin with " << vect << endl;
			}
			if (obj.isEnd(vect)) {
				cout << obj << " ends with " << vect << endl;
			}
			else {
				cout << obj << " doesn't end with " << vect << endl;
			}
			if (obj < obj2) {
				cout << obj << " is before " << obj2 << " in lexicographical oder " << endl;
			}
			else {
				cout << obj2 << " is before " << obj << " in lexicographical oder " << endl;
			}
			cout << "Returned string:" << str << endl;
			obj.sortIncrease();
			cout << "String sorted increasly:" << obj << endl;
			obj.sortDecrease();
			cout << "String sorted decreasly:" << obj << endl;
			getchar();
			getchar();
			system("CLS");
		}
		if (menu == 2) {
			cout << "\nMap\n\n";
			map<int, string> words = { {1, "flower"}, {2, "tree"}, {3, "sun"} };
			map<int, string>::iterator it;
			int key;
			cout << "Words in map:\n";
			for (it=words.begin(); it!=words.end(); ++it) {
				cout << it->first<<" - "<< it->second << endl;
			}
			words.insert(make_pair(4, "house"));
			cout << "\nAdding word with key:" << words[4] << endl;
			words[5] = "sky";
			cout << "Adding word without key:" << words[5] << endl;
			cout << "\nWords in map with added word:\n";
			for (int i = 1; i <= words.size(); i++) {
				cout << i<< " - "<< words[i] << endl;
			}
			cout << "\nEnter key to find element:";
			cin >> key;
			it = words.find(key);
			if (it != words.end())
				cout << it->second;
			else
				cout << "There aren`t words with such keys\n";

			cout << "\nEnter key to delete element:";
			cin >> key;
			it = words.find(key);
			if (it==words.end())
				cout << "There aren`t words with such keys\n";
			else {
				words.erase(key);
				it = words.find(key);
				if (it != words.end())
					cout << "Cannot delete an element\n";
				for (it = words.begin(); it != words.end(); it++) {
					cout << it->first << " - " << it->second << endl;
				}
			}
			cout << "\nWords copied from map:\n";
			for (auto& el: words) {
				cout << el.second << endl;
			}
			getchar();
			getchar();
			system("CLS");
		}
		if (menu == 3) {
			cout << "\nUnodered multiset\n\n";
			unordered_multiset<char> syms = { 'a', 'b', 'c'};
			unordered_multiset<char>::iterator it;
			cout << "\nSyms:\n";
			for (it = syms.begin(); it != syms.end(); it++) {
				cout << *it << endl;
			}
			syms.insert('a');
			it = syms.find('a');
			cout << "\nInserting " << *it << endl;
			cout << "\nSyms with added sym:\n";
			for (it = syms.begin(); it != syms.end(); it++) {
				cout << *it << endl;
			}
			cout << "\nEnter sym you want to find:";
			char t;
			cin >> t;
			it = syms.find(t);
			if (it != syms.end())
			{
				cout << "Sym is founded\n";
			}
			else {
				cout << "Therearen`t such sym in set\n";
			}
			cout << "\nEnter sym you want to delete:";
			cin >> t;
			it = syms.find(t);
			if (it != syms.end())
			{
				syms.erase(t);
				cout << "Set without " << t << endl;
				for (it = syms.begin(); it != syms.end(); it++) {
					cout << *it << endl;
				}
			}
			else {
				cout << "\nTherearen`t such sym in set\n";
			}
			syms.clear();
			char arr[] = { 's','y', 'm','s' };
			cout << "Set copied from array:\n";
			for (auto& el : arr) {
				cout << el;
			}
			getchar();
			getchar();
			system("CLS");
		}
		if (menu == 4) {
			cout << "\nPriority queue\n\n";
			int arr[] = { 5,10,7,6,30 };
			priority_queue<int> nums;
			for (int i = 0; i < 5;i++){
				nums.push(arr[i]);
			}
			cout << "Enter num you want to add to queue:";
			int el;
			cin >> el;
			nums.push(el);
			cout << "Nums:\n";
			while(!nums.empty()) {
				cout << nums.top()<<endl;
				nums.pop();
			}
		}
		getchar();
		getchar();
		system("CLS");
	}
	return 0;
}
