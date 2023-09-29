#include<iostream>
using namespace std;
void longestTime(int h, int m);
main(){
	int h,m;
	cout << "Enter the number of hours: ";
	cin >> h;
	cout << "Enter the number of minutes: ";
	cin >> m;
	longestTime(h, m);	
}
void longestTime(int h, int m){
	if(h*60 < m){
	cout << m;
}
	if(h*60 > m){
	cout << h;
}
}