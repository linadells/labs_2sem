#include<iostream>
#include"Header.h"
using namespace std;
int CVector::countVect = 0;
int main() {
	CVector first, second(1, 2, 3), third(4, 5, 6);
	cout << "You created " << CVector::getCountVect() << " vectors\n";
	cout << "Enter coordinates of vector:";
	cin >> first;
	cout << "Sum of " << second << " and " << third << " is " << second + third << "\n"
		<< "Vect dob of " << first << " and " << second << " is " << first % second << "\n"
		<< "Scal dob of " << first << " and " << second << " is " << first * second << "\n";
	second = first;
	cout << "5 * " << first << " is " << fri_dobNaSkal(second, 5) << "\n";
	if (first > second) cout << first << " is bigger than " << second;
	else if (first == second) cout << first << " is the same as " << second;
	else cout << second << " is bigger than " << first;
	return 0;
}