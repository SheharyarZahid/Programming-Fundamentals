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
    int k=0;
for(int i=1;i<=num;i++){
    int n=0;
    for(int j=1;j%j==0 && j/2!=0 && j/2!=3;j++)
    {
        n=j;
        k=n-j;
        result=result*j;
        int o=k/2;
    }
}
    return result;
}