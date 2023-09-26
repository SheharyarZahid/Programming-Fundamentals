#include<iostream>
using namespace std;
void addition(int a, int b);
void subtraction(int a, int b);
void multiplication(int a, int b);
void division(int a,int b);
main(){
	int c,d;
	char op;
	cout << "Enter 1st number: ";
	cin >> c;
	cout << "Enter 2nd number: ";
	cin >> d;
	cout << "Enter an operator (+, -, *, /): ";
	cin >> op;
	if(op == '+'){
	addition(c,d);
}
	if(op == '-'){
	subtraction(c,d);
}
	if(op == '*'){
	multiplication(c,d);
}
	if(op == '/'){
	division(c,d);
}
} 
void addition(int a, int b){
	a=a+b;
	cout << "Addition: " << a;
}
void subtraction(int a, int b){
	a=a-b;
	cout << "Subtraction: " << a;
}
void multiplication(int a, int b){
	a=a*b;
	cout << "Multiplication: " << a;
}
void division(int a, int b){
	a=a/b;
	cout << "Division: " << a;
}