#include <iostream>
using namespace std;
main()
{
    cout << "Enter the weights of the 10 packages: " << endl;
    int weights[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        cin >> weights[i];
    }
    int j;
    int collect;
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (weights[i] > weights[j])
            {
                collect = weights[i];
                weights[i] = weights[j];
                weights[j] = collect;
            }
        }
    }
    cout << "Sorted array in ascending order: [";
    for (int i = 0; i < 10; i++)
    {
        if (i != 9)
        {
            cout << weights[i] << ", ";
        }
        else
        {
            cout << weights[i] << "]";
        }
    }
}