#include<iostream>
using namespace std;
void flowerShop(int redRose, int whiteRose, int tulip);
main(){
	int a,b,c;
	cout << "Red Rose: ";
	cin >> a;
	cout << "White Rose: ";
	cin >> b;
	cout << "Tulips: ";
	cin >> c;
	flowerShop(a, b, c);
}
void flowerShop(int redRose, int whiteRose, int tulip){
	float a,b,c,price;
	a=redRose*2.00;
	b=whiteRose*4.10;
	c=tulip*2.50;
	price=a+b+c;
	if(price <= 200){
	cout << "Original Price: $" << price << endl;
	cout << "No discount applied.";
}
	if(price > 200){
	cout << "Original Price: $" << price << endl;
	price=price-price*(20.00/100);
	cout << "Price after Discount: $" << price;
}
}