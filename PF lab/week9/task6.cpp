#include<iostream>

using namespace std;

main()
{
    int elements;
    string res;

    cout << "Enter the number of elements: ";
    cin >> elements;

    int numbers[elements];

    cout << "Enter " << elements << " numbers, one per line:" << endl;    

    int max = 0;
    for (int i = 0; i < elements; i++)
    {
        cin >> numbers[i];
        if (numbers[i] > max) 
            max = numbers[i];
    }
    cout << "The largest number entered is: " << max;
}

