#include<iostream>

using namespace std;

main()
{
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;

    cout << "Enter the elements of the array:" << endl;
    int arr[length];

    for (int i = 0; i < length; i++)
        cin >> arr[i];

    int num = 0;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (length == 2)
        {
            num = 2;
            if (arr[i] > num)
            {
                flag = true;
                count++;
            }
            else 
                flag = false;
                break;
        }
        else
        {
            num = 3;
            if (arr[i] > num)
            {
                flag = true;
                count++;
            }
            else
                flag = false;
        }
    }
    
    count++;
    if (flag == false)
        count = -1;
    cout << "Special value: " << count;
}
