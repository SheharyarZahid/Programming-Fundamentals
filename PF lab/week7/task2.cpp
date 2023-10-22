#include <iostream>

using namespace std;

void generateFibonacci(int length);

main()
{
    int length;
    cout << "Enter the length of the Fibonacci series: ";
    cin >> length;
    
    generateFibonacci(length);

}

void generateFibonacci(int length)
{
    int n1 = 0, n2 = 1;
    int next;
    
    if (length == 1)
        cout << "0";
    
    else if (length == 2)
        cout << "0, 1";
    
    else if (length > 2)
    {    
        cout << "0, 1";
    
        for (int i=length-3; i>=0; i--)
        {
            next = n1 + n2;
        
            cout << ", " << next;
        
            n1 = n2;
            n2 = next;
        }
    }
}