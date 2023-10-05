#include<iostream>
#include<cmath>

using namespace std;


main(){
    float baseNumber,exponent;
    cout << "Enter the base number: ";
    cin >> baseNumber;

    cout << "Enter the exponent: ";
    cin >> exponent;

    float power;
    power = pow(baseNumber,exponent);
    cout << baseNumber << " raised to the power " << exponent << " is: " << power; 

}