#include<iostream>

using namespace std;

main()
{
    int elements;
    string res;

    cout << "Enter the number of resistors in the series circuit: ";
    cin >> elements;

    float numbers[elements];

    cout << "Enter the resistance values (in ohms) of the " << elements << " resistors, one per line:" << endl;    
    
    float resistance = 0;
    for (int i = 0; i < elements; i++)
    {
        cin >> numbers[i];
        resistance += numbers[i];   
    }
    cout << "The total resistance of the series circuit is " << resistance << " ohms.";
}

