#include<iostream>
using namespace std;
void passorfail(int marks);
main(){
	int m;
	cout << "Enter your score: ";
	cin >> m;
	passorfail(m);
}
void passorfail(int marks){
	if(marks > 50){
	cout << "Pass";
}
	if(marks <= 50){
	cout << "Fail";
}
}