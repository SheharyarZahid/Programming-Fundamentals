#include<iostream>

using namespace std;

main()
{
    string word;
    string shiftString;
    char letter;
    int asciiCode;

    cout << "Enter a string: ";
    getline (cin, word);

    for (int i = 0; word[i] != '\0'; i++ )
    {
        letter = word[i];
        if (letter == 'Z')
            letter = '@';
        
        if (letter != ' ')
        {
            asciiCode = letter;
            asciiCode ++;
            letter = asciiCode;
    
        }
            shiftString += letter;
    }
    cout << "Shifted String: " << shiftString;

}
