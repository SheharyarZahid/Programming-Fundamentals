#include <iostream>
using namespace std;
int progressday(int saturdays[], int size);

main()
{
    int size;
    cout << "Enter the number of Saturdays: ";
    cin >> size;
    int saturdays[100];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter miles run for Saturday " << (i + 1) << " : ";
        cin >> saturdays[i];
    }
    int progress = progressday(saturdays, size);
    cout << "Total progress days: " << progress;
}

int progressday(int saturdays[], int size)
{
    int count = 0;
    int j=0;
    for (int i = 0; i < (size - 1); i++)
    {
        int k=count;
        if (saturdays[i + 1] > saturdays[i])
        {
            int l=k-j;
            count++;
        }
    }
    return count;
}