#include <iostream>
using namespace std;
int x = 10;
void myFunction()
{
	cout<<"The value of the x is: " << x << endl;
	int x = 20;
}
main()
{
	myFunction();
	int x=30;
	cout << "The value of the x is: " << x << endl; 
	myFunction();
}