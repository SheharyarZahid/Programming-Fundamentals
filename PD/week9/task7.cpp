#include<iostream>

using namespace std;

main()
{
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;
    
    cout << "Enter the elements of the array:" << endl;
    
    // input
    int arr[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    /// sorting from task-5
    int min = 0;
    for (int i = 0; i < length; i++) 
    {
        int minIndex = i;           
        for (int j = i + 1; j < length; j++) 
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];          
        arr[i] = arr[minIndex];     
        arr[minIndex] = temp;       
    }
    // checking if consective int are same :] 
    bool flag = true;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] != (arr[i + 1] - 1))
            flag = false;
    }
    cout << "Can be arranged: " << flag;
}
