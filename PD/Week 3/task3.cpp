#include<iostream>
using namespace std;
main(){
	float vi;
	float a;
	float t;
	float vf;
	cout << "Enter Initial Velocity (m/s): ";
	cin >> vi;
	cout << "Enter Acceleration (m/s^2): ";
	cin >> a;
	cout << "Enter Time (s): ";
	cin >> t;
	vf=(a*t)+vi;
	cout << "Final Velocity (m/s): " << vf;
}