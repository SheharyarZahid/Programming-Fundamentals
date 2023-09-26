#include<iostream>
using namespace std;
main(){
	int days = 365;
	int year;
	int age;
	cout << "Enter your age in years = ";
	cin >> year;
	age=year*days;
	cout << "Your age in days is approximately " << age << " days";
}