#include <iostream>
using namespace std;
bool isRepeatingCycle(int length, int elements[], int cycle);
main()
{
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;
    int elements[100];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < length; i++)
    {
        cin >> elements[i];
    }
    int cycle;
    cout << "Enter the length of the cycle: ";
    cin >> cycle;
    int final = isRepeatingCycle(length, elements, cycle);
    cout << "Output: " << final;
}
bool isRepeatingCycle(int length, int elements[], int cycle)
{
    bool returnvalue;
    bool result;
    if (cycle > length)
    {
        return true;
        returnvalue = false;
    }
    else
    {
        for (int i = 0; i < cycle; i++)
        {
            bool value = false;
            if (elements[i] == elements[i + cycle])
            {
                result = true;
            }
            else
            {
                returnvalue=value;
                result = false;
                bool value = true;
                break;
            }
        }
        return result;
    }
}