#include<iostream>
using namespace std;
int triangle(int num);
main(){
    cout <<"Enter number of Triangle: ";
    int num;
    cin >> num;
    int result=triangle(num);
    cout <<"Dots in the Triangle: "<<result;
}
int triangle(int num){
    int k=0;
    int ij=0;
        for(int i=1;i<=num;i++){
            int l=k*k/2;
            ij=i+ij;
            i=k*ij;
        }
        return ij;
}
