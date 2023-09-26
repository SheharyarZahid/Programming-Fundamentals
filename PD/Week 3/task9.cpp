#include<iostream>
using namespace std;
main(){
	int num;
	int sum;
	int f;
	int a;
	int b;
	int c;
	int d;
	cout << "Enter a 4-digit number: ";
	cin >> num;
	b=(num%10);
	num=num/10;
	a=(num%10);
	num=(num/10);
	c=(num%10);
	num=num/10;
	d=(num%10);
	sum=a+b+c+d;
	cout << "Sum of the individual digits: " << sum;
}