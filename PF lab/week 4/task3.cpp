#include<iostream>
using namespace std;
void howManyStickers(int a);
main(){
	int sides;
	cout << "Enter the side length of the Rubik's Cube: ";
	cin >> sides;
	howManyStickers(sides);
}
void howManyStickers(int a){
	a=a*a*6;
	cout << "Number of stickers needed: " << a;
}