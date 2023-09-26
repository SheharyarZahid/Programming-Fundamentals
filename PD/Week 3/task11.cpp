#include<iostream>
using namespace std;
main(){
	int age;
	int moves;
	cout << "Enter the person's age: ";
	cin >> age;
	cout << "Enter the number of times they've moved: ";
	cin >> moves;
	moves=moves+1;
	age=age/moves;
	cout << "Average number of years lived in the same house: " << age;
	
}