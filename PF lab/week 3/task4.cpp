#include<iostream>
using namespace std;
main(){
	float charge;
	float time;
	float current;
	cout << "Enter the charge in Coulomb(Q) = ";
	cin >> charge;
	cout << "Enter the time in second = ";
	cin >> time;
	current = charge/time;
	cout << "The current(I) is = " << current << " Amperes";
}