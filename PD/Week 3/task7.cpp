#include<iostream>
using namespace std;
main(){
	string name;
	float ap;
	float cp;
	float as;
	float cs;
	float charity;
	cout << "Enter the movie name: ";
	cin >> name;
	cout << "Enter the adult ticket price: $";
	cin >> ap;
	cout << "Enter the child ticket price: $";
	cin >> cp;
	cout << "Enter the number of adult tickets sold: ";
	cin >> as;
	cout << "Enter the number of child tickets sold: ";
	cin >> cs;
	cout << "Enter the percentage of the amount to be donated to charity: ";
	cin >> charity;
	cout << "" <<endl;
	ap= (ap*as)+(cp*cs);
	charity= ap/10;
	cp=ap-charity;
	cout << "Movie: " << name << endl;
	cout << "Total amount generated from ticket sales: $" << ap << endl;
	cout << "Donation to charity (10%): $" << charity << endl;
	cout << "Remaining amount after donation: $" << cp;
	
}