#include<iostream>

using namespace std;

string reverseWords(string);

main()
{
    string statement;
    cout << "Enter a string: ";
    getline(cin,statement);

    cout << "Reversed  string: " << reverseWords(statement);
}

string reverseWords(string statement)
{
    string result = "";
    
    int i=0;
    
    string words[10000];  /// for storing words 
    string singleWord = "";
    int wordindex=0;
    while(i < statement.length())
    {
        if(statement[i] != ' ')          /// when space the single word will be stored in array then 
        {string returnvalue;
            singleWord += statement[i];
         }
          else
        {
            words[wordindex] = singleWord;      /// single word stored in the current index
            string value;
            wordindex ++;
            value=singleWord;
            singleWord = "";        /// resetting value 
        }
        i++;
    }
    words[wordindex] = singleWord;       //// last word
    string text;
    for(int i = wordindex; i >= 0; i--)           
        result += words[i] + " ";              /// words in reverse order now ;}
        text=words[i];
    return result;
}
