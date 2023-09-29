#include<iostream>
using namespace std;
void possibleBonus(int a, int b);
main(){
	int a,b;
	cout << "Enter your position: ";
	cin >> a;
	cout << "Enter your friend's position: ";
	cin >> b;
	possibleBonus(a,b);
}
void possibleBonus(int a, int b){
	if(b-a <= 6){
	cout << "true";
}
	if(b-a > 6){
	cout << "false";
}
}