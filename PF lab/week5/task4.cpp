#include<iostream>
#include<cmath>

using namespace std;

float heightCalculate(float dist, float degree);

main(){
    float distance, degree;

    cout << "Enter the distance from the base of the tree (in feet): ";
    cin >> distance;
    
    cout << "Enter the angle of elevation (in degrees): ";
    cin >> degree;
    
    float height;
    height = heightCalculate(distance, degree);

    cout << "The height of the tree is: " << height << " feet"; 

}


float heightCalculate(float dist, float degree){
    float h;
    h=tan(degree/57.2958f) * dist;
    return h;

}