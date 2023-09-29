#include<iostream>
using namespace std;
void tpChecker(int a, int b);
main(){
	int a,b;
	cout << "Number of people in the household: ";
	cin >> a;
	cout << "Number of rolls of TP: ";
	cin >> b;
	tpChecker(a , b);
}
void tpChecker(int a , int b){
	b=b*500;
	a=a*57;
	b=b/a;
	if(b < 14){
	cout << "Your TP will only last " << b << " days, buy more!";
}
	if(b >= 14){
	cout << "Your TP will last " << b << " days, no need to panic!";
}
}