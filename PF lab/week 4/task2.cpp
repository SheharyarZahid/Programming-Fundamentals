#include<iostream>
using namespace std;
void inchesToFeet(float a);
main(){
	float inch;
	cout << "Enter the measurement in inches: ";
	cin >> inch;
	inchesToFeet(inch);
}
void inchesToFeet(float a){
	a=a/12;
	cout << "Equivalent in feet: " << a;
}