#include <iostream>
using namespace std;
bool isSpecialArray(int arr[], int size);
main()
{
    cout << "Enter the size of the array: ";
    int num;
    cin >> num;
    int arr[num];
    cout << "Enter " << num << " elements of the array:" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    bool result = isSpecialArray(arr, num);
    if (result)
    {
        cout << "The array is special";
    }
    else
    {
        cout << "The array is not special";
    }
}

bool isSpecialArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0 && arr[i] % 2 != 0)
        {
            return false;
        }
        else if (i % 2 != 0 && arr[i] % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
