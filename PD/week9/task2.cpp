#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter how many words you want to enter: ";
    cin >> size;
    string letters[100];
    int i = size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter word " << (i + 1) << " : ";
        cin >> letters[i];
    }
    char word;
    cout << "Enter the letter you want to count: ";
    cin >> word;
    string collect;
    int counter = 0;
    for (int x = 0; x < i; x++)
    {
        collect = letters[x];
        for (int y = 0; collect[y] != '\0'; y++)
        {
            if (word == collect[y])
            {
                counter++;
            }
        }
    }
    cout << word << " shows up " << counter << " times in the data.";
}
