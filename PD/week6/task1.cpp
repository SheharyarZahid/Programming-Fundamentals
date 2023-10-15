#include<iostream>
using namespace std;
string decideActivity(string temperature,string humidity);
main(){
    string temperature,humidity;
    cout << "Enter temperature (warm or cold): ";
    cin >> temperature;
    cout << "Enter humidity (dry or humid): ";
    cin >> humidity;
    string activity=decideActivity(temperature,humidity);
    cout << "Recommended activity: " << activity;
}
string decideActivity(string temperature, string humidity)
{
    string activity;
    if (temperature == "warm" && humidity == "dry")
    {
        activity = "Play tennis";
        return activity;
    }
    if (temperature == "cold" && humidity == "humid")
    {
        string activities = "Watch TV";
        return activities;
    }
    if (temperature == "warm" && humidity == "humid")
    {
        activity = "Swim";
        return activity;
    }
    if (temperature == "cold" && humidity == "dry")
    {
        string activities = "Play basketball";
        return activities;
    }
}