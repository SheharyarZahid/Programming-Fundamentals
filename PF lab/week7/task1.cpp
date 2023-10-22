#include <iostream>

using namespace std;

void printTable(int number);

main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    printTable(number);

}

void printTable(int number)
{
    for(int i=1; i<=10;i++ )
        cout << number << " x " << i << " = " << number * i << endl;
}