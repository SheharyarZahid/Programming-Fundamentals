#include<iostream>
#include<windows.h>
using namespace std;
float pyramidVolume(float length, float width, float height, string unit);
main(){
	float length,width,height;
	string unit;
	cout << "Enter the length of the pyramid (in meters): ";
	cin >> length;
	cout << "Enter the width of the pyramid (in meters): ";
	cin >> width;
	cout << "Enter the height of the pyramid (in meters): ";
	cin >> height;
	cout << "Enter the desired output unit (millimeters, centimeters, meters, kilometers): ";
	cin >> unit;
	float result=pyramidVolume(length,width,height,unit);
	cout << "The volume of the pyramid is: " << result << " cubic " << unit;
}
float pyramidVolume(float length, float width, float height, string unit){
	float result =(length*width*height)/3;
	if(unit=="millimeters"){
	result=result*1000000000;
	}
	if(unit=="centimeters"){	
	result=result*1000000;
	}
	if(unit=="kilometers"){
	cout << result << endl;
	result=result/1000000000;
	}
	return result;
}