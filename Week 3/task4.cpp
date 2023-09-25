#include<iostream>
using namespace std;
main(){
	float i;
	float p;
	int f;
	cout << "Enter Imposter Count: ";
	cin >> i;
	cout << "Enter Player Count: ";
	cin >> p;
	f =(i/p)*100;
	cout << "Chance of being an imposter: " << f << "%";
}