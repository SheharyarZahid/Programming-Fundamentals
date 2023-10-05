#include<iostream>
#include<cmath>

using namespace std;


main(){
    float numberOne,numberTwo;
    cout << "Enter the first number: ";
    cin >> numberOne;

    cout << "Enter the second number: ";
    cin >> numberTwo;

    float minimum;
    minimum = min(numberOne,numberTwo);
    cout << "The minimum of " << numberOne << " and " << numberTwo << " is: " << minimum; 

}