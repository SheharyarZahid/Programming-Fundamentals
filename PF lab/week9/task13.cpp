#include <iostream>
using namespace std;
void jazzifyChords(string chords[], int numChords);
main()
{
    cout << "Enter the number of chords: ";
    int num;
    cin >> num;
    string chords[num];
    cout << "Enter " << num << " chords, one per line:" << endl;
    for (int i = 0; i < num; i++)
    {
        cin >> chords[i];
    }
    jazzifyChords(chords, num);
    cout << "Jazzified chords: [";
    for (int i = 0; i < num; i++)
    {
        if(i+1==num){
        cout << chords[i] << "]";
        }
        else{
        cout << chords[i] << ", ";
        }
    }
}
void jazzifyChords(string chords[], int numChords)
{
    for (int i = 0; i < numChords; i++)
    {
        if (chords[i].back() != '7')
        {
            chords[i] += "7";
        }
    }
}
