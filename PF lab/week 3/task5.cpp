#include<iostream>
using namespace std;
main(){
	float marks;
	float ecat;
	float inter;
	float aggregate;
	string name;
	cout << "Enter student name = ";
	cin >> name;
	cout << "Enter matric marks (out of 1100) = ";
	cin >> marks;
	cout << "Enter intermediate marks (out of 510) = ";
	cin >> inter;
	cout << "Enter ECAT marks(out of 400) = ";
	cin >> ecat;
	aggregate = (10*(marks/1100))+(40*(inter/510))+(50*(ecat/400));
	cout << "Aggregate of "  << name << " is " << aggregate << "%";
}