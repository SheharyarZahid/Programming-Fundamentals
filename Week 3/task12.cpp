#include<iostream>
using namespace std;
main(){
	int squares;
	int h;
	int w;
	cout << "Number of square meters you can paint: ";
	cin >> squares;
	cout << "Width of the single wall (in meters): ";
	cin >> h;
	cout << "Height of the single wall (in meters): ";
	cin >> w;
	h=h*w;
	squares=squares/h;
	cout << "Number of walls you can paint: " << squares;
}