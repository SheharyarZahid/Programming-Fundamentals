#include<iostream>
using namespace std;
main(){
	float vp;
	float fp;
	int vn;
	int fn;
	float f;
	cout << "Enter vegetable price per kilogram (in coins): ";
	cin >> vp;
	cout << "Enter fruit price per kilogram (in coins): ";
	cin >> fp;
	cout << "Enter total kilograms of vegetables: ";
	cin >> vn;
	cout << "Enter total kilograms of fruits: ";
	cin >> fn;
	f=((vp*vn)+(fp*fn))/1.94;
	cout << "Total earnings in Rupees (Rps): " << f;
}