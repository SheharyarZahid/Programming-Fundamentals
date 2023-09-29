#include<iostream>
using namespace std;
void Reverse(string a);
main(){
	string b;
	cout << "Enter 'true' or 'false': ";
	cin >> b;
	Reverse(b);
}
void Reverse(string a){
	if(a=="true"){
	cout<< "false";
}
	if (a=="false"){
	cout << "true";
}
}