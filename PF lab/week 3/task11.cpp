#include<iostream>
using namespace std;
main(){
	int decade = 360;
	int population;
	int rate;
	int final;
	cout << "Enter the current population = ";
	cin >> population;
	cout << "Enter the birth rate(per month) = ";
	cin >> rate;
	final=(rate*decade)+population;
	cout << "The population in three decades will be: " << final;
	
}