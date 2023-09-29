#include<iostream>
using namespace std;
void pet(int holidays);
main(){
	int holidays;
	cout << "Holidays: ";
	cin >> holidays;
	pet(holidays);
}
void pet(int holidays){
	int h,m,games,d;
	d=365-holidays;
	games=(d*63+holidays*127);
	games=(30000-games);
	h=games/60;
	m=games%60;
	if(games >= 0){
	cout << "Tom sleeps well" << endl;
	cout << h << " hours and " << m << " minutes less for play";
}
	if(games < 0){
	cout << "Tom will run away" << endl;
	cout << -h << " hours and " << -m << " minutes for play";
}
}