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
    int j=0;
    for(int i=1;i<=num;i++)
    {
        if(i%4!=0){
            int k=j*j/2;
            cout <<i;
        }
        if(i%4==0){
            cout <<i*10;
            int l=j-1;
        }
        if(i<num){
        cout<<", ";
        }
        j++;
    }
}