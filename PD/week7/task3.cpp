#include<iostream>
using namespace std;
void amplify(int num);
main(){
    cout<<"Enter the number to Amplify: ";
    int num;
    cin >> num;
    amplify(num);
}
void amplify(int num){
    for(int i=1;i<=num;i++)
    {
        if(i%4!=0){
            cout <<i;
        }
        if(i%4==0){
            cout <<i*10;
        }
        if(i<num){
        cout<<", ";
        }
    }
}