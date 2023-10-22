#include <iostream>

using namespace std;

int frequencyChecker(int number, int digit);


main()
{
    int number, digit;

    cout << "Enter a number: ";
    cin >> number;
    
    cout << "Enter the digit to check: ";
    cin >> digit;
    
    int result = frequencyChecker(number, digit);
    cout << "Frequency: " << result;

}


int frequencyChecker(int number, int digit)
{
    int frequency=0;
    int n;
    while(number > 0)
    {
        n = number % 10;
        
        if (n == digit)
            frequency += 1;
       
        number /= 10;
    }
    return frequency;
}