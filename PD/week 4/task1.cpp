#include<iostream>
using namespace std;
void IsEqual(int a, int b);
main(){
	int a,b;
	cout << "Enter the first number: ";
	cin >> a;
	cout << "Enter the second number: ";
	cin >> b;
	IsEqual(a,b);
}
void IsEqual(int a, int b){
	if(a==b){
	cout << "true";
	}
	if(a!=b){
	cout << "false";
	}
}