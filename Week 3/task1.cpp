#include<iostream>
using namespace std;
main(){
	int n;
	int m;
	cout << "Enter the number of sides of the polygon: ";
	cin >> n;
	m=(n-2)*180;
	cout << "The sum of internal angles of a " << n << "-sided polygon is: " << m << " degrees"; 
}