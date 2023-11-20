#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;
    
    cout << "Enter " << number << " numbers, one per line:"<<endl; 

    if (number <= 0)
    {
        cout << "Invalid input. Please enter a positive number of elements." << endl;
        return 1;
    }

    int arr[number];
    int size = 0;

    for (int i = 0; i < number; i++) 
    {
        int num;
        bool isDuplicate = false;
        cin >> num;

        //// checking for duplicates
        for (int j = 0; j < size; j++) 
        {
            if (arr[j] == num)
            {
                cout << "Already Entered: " << num << endl;
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) 
        {
            arr[size] = num; 
            size++;
        }
    }
    cout << "Unique numbers entered: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
