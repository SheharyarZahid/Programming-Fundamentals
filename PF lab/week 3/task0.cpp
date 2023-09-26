#include<iostream>
using namespace std;
main(){
	char section;
	float aggregate;
	int RollNo;
	string Name;
	cout << "Enter Your Name = ";
	cin >> Name;
	cout << "Enter your Roll number = ";
	cin >> RollNo;
	cout << "Enter your aggregate = ";
	cin >> aggregate;
	cout << "Enter your Section = " ;
	cin >> section ;
	cout << "Student Information: " << endl;
	cout << "Your Name is = " << Name << endl;
	cout << "Your Roll Number Is = " << RollNo << endl;
	cout << "Your aggregate is = " << aggregate << endl;
	cout << "Your Section Is = " << section;
}