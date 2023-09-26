#include<iostream>
using namespace std;
void named(string a);
main(){
	string name;
	cout << "Enter Name: ";
	cin >> name;
	named(name);
}
void named(string a){
	while(true){
	cout << a <<endl;
}
}