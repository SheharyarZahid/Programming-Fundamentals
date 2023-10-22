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
    int ij=0;
        for(int i=1;i<=num;i++){
            ij=i+ij;
        }
        return ij;
}
