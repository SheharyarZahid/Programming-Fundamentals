#include<iostream>
using namespace std;
bool isPrime(int number);
main(){
    cout <<"Enter Number: ";
   int num;
    cin >>num;
    int result=isPrime(num);
    cout << result;
}
bool isPrime(int number){
    bool fal=false;
    bool var=true;
    if(number%number==0 && number/2!=0 && number/3!=0)
    {
        int value=number/2;
        var=true;
    }
    if( number%2==0 || number%3==0){
        var=false;
        int val=number/3;
    }
return var;
}