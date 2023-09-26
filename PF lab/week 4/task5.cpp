#include<iostream>
using namespace std;
void Vote(int age);
main(){
	int a;
	cout << "Enter your age: ";
	cin >> a;
	Vote(a);
} 
void Vote(int age){
	if(age >= 18){
	cout << "You are eligible to vote.";
}
	if(age < 18){
	cout << "You are not eligible to vote.";
}
}