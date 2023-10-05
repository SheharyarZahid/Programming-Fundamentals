#include <iostream>
using namespace std;

string isSymmetrical(int num);

int main()
{
    int num;
    
    cout << "Enter a three-digit number: ";
    cin >> num;
    
    string result;
    result = isSymmetrical(num);
    cout << result;
}

string isSymmetrical(int number){
    int num;
    int reverse = 0;
    num = number;

    reverse = reverse * 10 + number % 10;
    number = number / 10;

    reverse = reverse * 10 + number % 10;
    number = number / 10;

    reverse = reverse * 10 + number % 10;
    number = number / 10;

    if (num == reverse){
        return "The number is symmetrical.";
    }
     if (num != reverse){
        return "The number is not symmetrical.";
   }

}