#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter the number of boxes: ";
    cin >> size;
    int dimensions[100];
    cout << "Enter the dimensions of the boxes (length, width, height):" << endl;
    int i = 0;
    for (i; i < (3 * size); i++)
    {
        cin >> dimensions[i];
    }
    int volume = 1;
    int result = 0;
    for (int x = 0; x < (3 * size); x++)
    {
        volume = volume * dimensions[x];
        if ((x + 1) % 3 == 0)
        {
            result = result + volume;
            volume = 1;
        }
    }
    cout << "Total volume of all boxes: " << result;
}