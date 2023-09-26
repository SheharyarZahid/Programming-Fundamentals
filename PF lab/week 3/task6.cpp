#include<iostream>
using namespace std;
main(){
	float size;
	float mb;
	float output;
	cout << "Enter the size in mega bytes (MB) = ";
	cin >> mb;
	size = 1024;
	output = mb*size*size*8;
	cout << mb << " MB is equivalent to " << output << " bits";
}