#include<iostream>
using namespace std;
main(){
	int win;
	int draw;
	int lose;
	int points;
	cout << "Enter the number of wins = ";
	cin >> win;
	cout << "Enter the number of draws = ";
	cin >> draw;
	cout << "Enter the number of lose = ";
	cin >> lose;
	points = (win*3)+(lose*0)+(draw*1);
	cout << "Pakistan has obtained " << points << " points in the Asia Cup tournament"; 
	
}