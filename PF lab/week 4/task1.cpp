#include<iostream>
using namespace std;
void calculateFuel(float f);
main(){
	float fuel;
	cout << "Enter the distance: ";
	cin >> fuel;
	calculateFuel(fuel);
}
void calculateFuel(float f){
	f=f*10;
	cout << "Fuel needed: " << f;
}