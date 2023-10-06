#include<iostream>
using namespace std;
int projectTimeCalculation(int neededhours,int workers,int days);
main(){
    int neededhours;
    int workers;
    int days;
    cout << "Enter the needed hours: ";
    cin >> neededhours;
    cout << "Enter the days that the firm has: ";
    cin >> workers;
    cout << "Enter the number of all workers: ";
    cin >> days;
    int remainig_hours=projectTimeCalculation(neededhours,workers,days);
    if(remainig_hours<neededhours){
        remainig_hours=neededhours-remainig_hours;
       cout<< "Not enough time! " << remainig_hours << " hours needed.";
    }
    if(remainig_hours>neededhours){
       remainig_hours=remainig_hours-neededhours;
       cout<< "Yes!" << remainig_hours << " hours left.";
    }
}
int projectTimeCalculation(int neededhours,int workers,int days){
    float remainig_hours=(days*10*workers);
    remainig_hours=remainig_hours-(remainig_hours*(0.1));
    return remainig_hours;
}