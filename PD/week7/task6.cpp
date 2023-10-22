#include<iostream>
using namespace std;
int primorial(int num);
main(){
    cout <<"Enter Number: ";
    int num;
    cin >> num;
    int number=primorial(num);
cout << number;
}
int primorial(int num){
    int result=1;
for(int i=1;i<=num;i++){
    for(int j=1;j%j==0 && j/2!=0 && j/2!=3;j++)
    {
        result=result*j;
    }
}
    return result;
}