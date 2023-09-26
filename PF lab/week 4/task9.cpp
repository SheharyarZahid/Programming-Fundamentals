#include<iostream>
using namespace std;
void calculateFuel(int a);
main(){
	int dis;
	cout << "Enter the distance: ";
	cin >> dis;
	calculateFuel(dis);
}
void calculateFuel(int a){
	if(a <= 10){
	cout << "Fuel needed: " << 100;
}
	if(a > 10){
	a=a*10;
	cout << "Fuel needed: " << a;
}
}