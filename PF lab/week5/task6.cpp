#include <iostream>
#include <conio.h>
using namespace std;

string checkAlphabetCase(char character);

main(){
    char character;

    cout << "Enter a character (A/a): ";
    character=getche();

    cout << endl;

    string a;
    a = checkAlphabetCase(character);
    cout << a;
}

string checkAlphabetCase(char ch){
    if (ch == 'a'){
        return "You have entered small a";
    }
    if (ch == 'A'){
        return "You have entered Capital A";
    }
}