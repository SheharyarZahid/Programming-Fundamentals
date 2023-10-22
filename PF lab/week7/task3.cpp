#include <iostream>

using namespace std;

int totalDigits(int number);

main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    int result;
    result = totalDigits(number);
    cout << "Total number of digits: " << result;

}

int totalDigits(int number)
{
    int count=0;

    if (number < 0) 
        number = -number;
    
    do
    {
        count += 1;
        number /= 10;

    }while (number > 0);

    return count;

}