#include<iostream>
using namespace std;
main(){
	int hours;
	int seconds;
	cout << "Enter time in hours = ";
	cin >> hours;
	seconds= hours*60*60;
	cout << hours << " hours is equivalent to " << seconds << " seconds";
}