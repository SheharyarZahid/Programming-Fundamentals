#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter the length of the array: ";
    cin >> size;
    cout << "Enter the elements of the array (left or right):"<< endl;
    string directions[100];
    for (int i = 0; i < size; i++)
    {
        cin >> directions[i];
    }
    int totalRotation = 0;
    for (int i = 0; i < size; i++)
    {
        if (directions[i] == "left")
        {
            totalRotation -= 90;
        }
        else if (directions[i] == "right")
        {
            totalRotation += 90;
        }
    }
    int rotations = totalRotation / 360;
    if (rotations<0)
    cout << "Number of full rotations: " << rotations << endl;
}
