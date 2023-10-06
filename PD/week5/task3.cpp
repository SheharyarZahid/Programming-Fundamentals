#include<iostream>
using namespace std;
float tax(char vehicletype,float price);
main(){
    float price;
    char vehicletype;
    cout << "Enter the vehicle type code (M, E, S, V, T): ";
    cin >> vehicletype;
    cout << "Enter the price of the vehicle: $";
    cin >> price;
    float result=tax(vehicletype,price);
    cout << "The final price of a vehicle of type " << vehicletype << " after adding the text is $" << result << ".";
}
float tax(char vehicletype,float price){
    float taxrate;
    if(vehicletype=='M'){
    taxrate=6;
    }
    if(vehicletype=='E'){
    taxrate=8;
    }
    if(vehicletype=='S'){
    taxrate=10;
    }
    if(vehicletype=='V'){
    taxrate=12;
    }
    if(vehicletype=='T'){
    taxrate=15;
    }
    float taxamount=price*(taxrate/100);
    price=price+taxamount;
    return price;
}