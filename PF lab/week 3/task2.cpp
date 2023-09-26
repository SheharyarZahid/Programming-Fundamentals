#include<iostream>
using namespace std;
main(){
	float lb;
	float Kgs = 0.45;
	float final;
	cout << "Enter weight in lbs = ";
	cin >> lb;
	final = lb*Kgs;
	cout << "Weight in Kgs = " << final;
}