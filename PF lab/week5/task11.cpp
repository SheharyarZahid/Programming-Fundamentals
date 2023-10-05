#include <iostream>

using namespace std;

string calculatePoolState(float v, float p1, float p2, float h);

main(){
    float volume, firstPipe, secondPipe, hoursAbsent;
    
    cout << "Enter volume of the pool in liters: ";
    cin >> volume;

    cout << "Enter flow rate of the first pipe per hour: ";
    cin >> firstPipe;

    cout << "Enter flow rate of the second pipe per hour: ";
    cin >> secondPipe;

    cout << "Enter hours that the worker is absent: ";
    cin >> hoursAbsent;
    string a;
    a = calculatePoolState(volume, firstPipe, secondPipe, hoursAbsent);
    cout << a;
}

string calculatePoolState(float v, float p1, float p2, float h){

    float full;
    full = (p1 * h) + (p2 * h);
    float fullPercentage;
    fullPercentage = (full / v) * 100;

    float percentageP1;
    percentageP1 = p1 * h / full * 100;
    float percentageP2;
    percentageP2 = p2 * h / full * 100;


    if (full <= v){
        string a;
        a = "The pool is " + to_string(int(fullPercentage)) + "% full. Pipe 1: " + to_string(int(percentageP1)) + "%. " + "Pipe 2: " + to_string(int(percentageP2)) + "%.";
        return a;
             }
    if (full > v){
        string b;
        b ="For " + to_string(h) + " hours, the pool overflows with " + to_string(int(full - v)) + " liters.";
        return b;
    }

}