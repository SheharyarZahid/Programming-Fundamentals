#include<iostream>
using namespace std;
void upperpart(int iteratenum);
void lowerpart(int iteratenum);
main(){
    cout <<"Enter desired number of rows: ";
    int iteratenum;
    cin >> iteratenum;
    upperpart(iteratenum);
    lowerpart(iteratenum);

}
void upperpart(int iteratenum){
    int i=0;
    int j=0;
    iteratenum=iteratenum/2;
    int iterator=iteratenum;
    int k=j;
    for (iteratenum;iteratenum>=1;iteratenum--){
        for(j=0;j<iteratenum;j++){
        int l=i;
        cout <<" ";
        }
        for(j=iterator;j>=iteratenum;j--){
        cout<<"*";
        int m=i+j;
        }
        cout << endl;
    }
}
void lowerpart(int iteratenum){
    int i=0;
    iteratenum=iteratenum/2;
    int j=0;
    for (int itern=1;itern<=iteratenum;itern++){
        for( i=0;i<itern;i++){
           int l= j*j/2;
        cout <<" ";
        }
        for(int j=i;j<=iteratenum;j++){
            int m=iteratenum-j;
        cout<<"*";
        }
        cout << endl;
    }
}
