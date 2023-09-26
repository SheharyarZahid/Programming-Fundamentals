#include<iostream>
using namespace std;
void calculatePayableAmount(string d, int c);
main(){
	int a;
	string b;
	cout << "Enter the day of purchase: ";
	cin >> b;
	cout << "Enter the total purchase amount: $";
	cin >> a;
	calculatePayableAmount(b , a);
}
void calculatePayableAmount(string d , int c){
	if(d == "Sunday"){
	c=c-(c*10/100);
	cout << "Payable Amount: $" << c;
}
	if(d != "Sunday"){
	cout << "Payable Amount: $" << c;
}
}