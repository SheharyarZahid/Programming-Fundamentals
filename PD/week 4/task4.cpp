#include<iostream>
using namespace std;
void checkSpeed(int speed);
main(){
	int a;
	cout << "Speed: ";
	cin >> a;
	checkSpeed(a);
}
void checkSpeed(int speed){
	if(speed <= 100){
	cout << "Perfect! You're going good.";
}
	if(speed >100){
	cout << "Halt... YOU WILL BE CHALLENGED!!!";
}
}