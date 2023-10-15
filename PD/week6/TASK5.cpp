#include<iostream>

using namespace std;

float calculateFruitPrice(string fruit, string dayOfWeek, double
quantity);

main()
{
    string fruit;
    cout << "Enter the fruit name: ";
    cin >> fruit;
    
    string dayOfWeek;
    cout << "Enter the day of the week (e.g., Monday, Sunday): ";
    cin >> dayOfWeek;

    double quantity;
    cout << "Enter the quantity: ";
    cin >> quantity;
    
    float cost;
    cost = calculateFruitPrice(fruit, dayOfWeek, quantity);
    if (cost != 0)
        cout << cost;
}

float calculateFruitPrice(string fruit, string dayOfWeek, double quantity)
{
    float cost;

    if (dayOfWeek == "Sunday" || dayOfWeek == "Saturday")
    {
        if (fruit == "banana")
        {
            cost = quantity * 2.70;
            return cost;
        }

        else if (fruit == "apple")
        {
            cost = quantity * 1.25;
            return cost;
        }

        else if (fruit == "orange")
        {
            cost = quantity * 0.90;
            return cost;
        }

        else if (fruit == "grapefruit")
        {
            cost = quantity * 1.60;
            return cost;
        }

        else if (fruit == "kiwi")
        {
            cost = quantity * 3.00;
            return cost;
        }

        else if (fruit == "pineapple")
        {
            cost = quantity * 5.60;
            return cost;
        }

        else if (fruit == "grapes")
        {
            cost = quantity * 4.20;
            return cost;
        }

        else
            cout << "error";
        return 0;
    }

    else if (dayOfWeek == "Monday" || dayOfWeek == "Tuesday" || dayOfWeek == "Wednesday" || dayOfWeek == "Thursday" || dayOfWeek == "Friday")
    {
        if (fruit == "orange")
        {
            cost = quantity * 0.85;
            return cost;
        }

        else if (fruit == "kiwi")
        {
            cost = quantity * 2.70;
            return cost;
        }

        else if (fruit == "apple")
        {
            cost = quantity * 1.20;
            return cost;
        }
        if (fruit == "banana")
        {
            cost = quantity * 2.50;
            return cost;
        }

        else if (fruit == "grapefruit")
        {
            cost = quantity * 1.45;
            return cost;
        }

        else if (fruit == "pineapple")
        {
            cost = quantity * 5.50;
            return cost;
        }
        else if (fruit == "grapes")
        {
            cost = quantity * 3.85;
            return cost;
        }
        else
            cout << "error";
        return 0;
    }

    else
        cout << "error";
    return 0;
}