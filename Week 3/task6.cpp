#include<iostream>
using namespace std;
main(){
	int size;
	int cost;
	int area;
	cout << "Enter the size of the fertilizer bag in pounds: ";
	cin >> size;
	cout << "Enter the cost of the bag: $" ;
	cin >> cost;
	cout << "Enter the area in square feet that can be covered by the bag: ";
	cin >> area;
	size = cost/size;
	area = cost/area;
	cout << "Cost of fertilizer per pound: $" << size << endl;
	cout << "Cost of fertilizing per square foot: $" << area;
}