#include<iostream>
using namespace std;
void Discount(string name, float price);
int main() {
    string a;
    float money;  
    cout << "Enter the country's name: ";
    cin >> a; 
    cout << "Enter the ticket price in dollars: $";
    cin >> money;  
    Discount(a, money);
}
void Discount(string name, float price) {
    if (name == "Pakistan") {
        price = price - price * (5.0 / 100);
    }
    if (name == "Ireland") {
        price = price - price * (10.0 / 100);
    }
    if (name == "India") {
        price = price - price * (20.0 / 100);
    }
    if (name == "England") {
        price = price - price * (30.0 / 100);
    }
    if (name == "Canada") {
        price = price - price * (45.0 / 100); 
    }   
    cout << "Final ticket price after discount: $" << price;
}
