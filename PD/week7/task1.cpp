#include<iostream>
using namespace std;
main(){
    int i=0;
    cout <<"Enter desired number of rows: ";
    int iteratenum;
    cin >> iteratenum;
    for (iteratenum;iteratenum>=1;iteratenum--){
        for(i=0;i<iteratenum;i++){
        cout<<"*";
        }
        cout << endl;
    }
}