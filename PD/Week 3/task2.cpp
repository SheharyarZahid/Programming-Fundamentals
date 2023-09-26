#include<iostream>
using namespace std;
main(){
	int min;
	int sec;
	cout << "Number of Minutes: ";
	cin >> min;
	cout << "Frames per Second: ";
	cin >> sec;
	min=min*sec*60;
	cout << "Total Number of Frames: " << min;
}