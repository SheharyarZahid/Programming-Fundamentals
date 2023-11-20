#include<iostream>

using namespace std;

main()
{
    string array;

    int firstElements;
    cout << "Enter the number of elements for the first array (must be 2): ";
    cin >> firstElements;
    
    cout << "Enter " << firstElements << " elements for the first array, one per line:" << endl;

    int firstArray[firstElements];
    
    for (int i = 0; i < firstElements; i++)
    {   
        cin >> firstArray[i]; 
    }

    int secondElements;
    cout << "Enter the number of elements for the second array: ";
    cin >> secondElements;
    
    cout << "Enter " << secondElements << " elements for the second array, one per line:" << endl;

    array += "[" + to_string(firstArray[0]) + ", ";
    
    int secondArray[secondElements];
    for (int i = 0; i < secondElements; i++)
    {   
        cin >> secondArray[i];
        array += to_string(secondArray[i]) + ", "; 
    }
    array += to_string(firstArray[1]) + "]";

    cout << "Resulting array: " << array;
}
