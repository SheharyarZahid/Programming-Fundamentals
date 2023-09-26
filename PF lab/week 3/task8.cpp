#include<iostream>
using namespace std;
main(){
	float volt;
	float current;
	float power;
	cout << "Enter voltage (in volts) = ";
	cin >> volt;
	cout << "Enter current (in amperes) = ";
	cin >> current;
	power = current*volt;
	cout << "The power is " << power << " watts.";
}