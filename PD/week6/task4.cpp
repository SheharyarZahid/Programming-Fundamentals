#include<iostream>
using namespace std;
string types(char type);
float amountDue(char time,float minutes ,char type);
main(){
    char typed,time;
    float minutes;
    cout << "Enter the service code (R/r for regular, P/p for premium): ";
    cin >> typed;
    if(typed =='p' || typed=='P' || typed == 'R' || typed=='r'){
    if(typed=='p'|| typed=='P'){
    cout << "Enter time of the call (D/d for day, N/n for night): ";
    cin >> time;
    }
    cout << "Enter the number of minutes used: ";
    cin >> minutes;
    string typo=types(typed);
    float amountDued=amountDue(time,minutes,typed);
    cout <<"Service Type: "<< typo<< endl;
    cout <<"Total Minutes Used: "<< minutes<<" minutes"<< endl;
    cout <<"Amount Due: $"<< amountDued;
    }
    else{
        cout << "Enter valid character" << endl;
    }
}
string types(char type)
{
    if (type == 'R' || type == 'r')
    {
        return "Regular";
    }
    if (type == 'P' || type == 'p')
    {
        return "Premium";
    }
}
float amountDue(char time, float minutes, char type)
{
    float min = minutes;
    if (type == 'R' || type == 'r')
    {
        if (min > 50)
        {
            min = min - 50;
            float mins;
            mins = min * 0.2;
            mins = min + 10;
    return mins;

        }
        else
        {
            float mins;
            mins = 10;
    return mins;

        }
    }
    if (type == 'P' || type == 'p')
    {
        if (time == 'D' || time == 'd')
        {
            if (min > 75)
            {
                min = min - 75;
                float mins;
                mins = min * 0.1;
                mins = min + 25;
    return mins;

            }
            else
            {
                float mins;
                mins = 25;
    return mins;

            }
        }
        if (time == 'N' || time == 'n')
        {
            if (min > 100)
            {
                min = min - 100;
                float mins;
                mins = min * 0.05;
                mins = min + 25;
    return mins;
           
            }

            else
            {
                float mins;
                mins = 25;
    return mins;
            }
        }
    }
}