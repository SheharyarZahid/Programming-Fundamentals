#include<iostream>
using namespace std;
void evenOrOdd(int a);
main(){
	int num;
	cout << "Enter a number: ";
	cin >> num;
	evenOrOdd(num);
}
void evenOrOdd(int a){
	if(a%2 == 0){
	cout << "Number " << a << " is even";
}
	if(a%2 != 0){
	cout << "Number " << a << " is odd";
}
}