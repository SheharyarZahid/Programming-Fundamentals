#include<iostream>
using namespace std;
string calculateHotelPrices(string month, int numberOfStays);
main(){
    string month;
    int stays;
    cout <<"Enter the month (May, June, July, August, September, October): ";
    cin >> month;
    cout << "Enter the number of stays: ";
    cin >> stays;
    string result= calculateHotelPrices( month, stays);
    cout << result;
}
string calculateHotelPrices(string month, int numberOfStays)
{
    float studio_Discount, apartment_Discount;
    float value;
    if (month == "May" || month == "October")
    {
        value = 50;
        studio_Discount = 50;
        apartment_Discount = 65;
        if (numberOfStays > 7)
        {
            int Discountstudio;
            Discountstudio = value - value * 0.05;
            studio_Discount = Discountstudio;
        }
        if (numberOfStays > 14)
        {
            int Discountstudio;
            Discountstudio = value - value * 0.3;
            int discounttwo;
            discounttwo = apartment_Discount - (apartment_Discount * 0.1);
            apartment_Discount = discounttwo;
        }
        studio_Discount = studio_Discount * numberOfStays;
        int numberOfStay = numberOfStays;
        apartment_Discount = apartment_Discount * numberOfStay;
    }
    if (month == "June" || month == "September")
    {
        value = 75.20;
        int discountstudio;
        studio_Discount = value;
        discountstudio=studio_Discount;
        int appartdiscount;
        apartment_Discount = 68.70;
        appartdiscount=apartment_Discount;
        if (numberOfStays > 14)
        {
            int Discountstudio;
            studio_Discount = value - value * 0.2;
            int discounttwo;
            discounttwo = apartment_Discount - (apartment_Discount * 0.1);
            apartment_Discount = discounttwo;
        }
        studio_Discount = studio_Discount * numberOfStays;
        int numberOfStay = numberOfStays;
        apartment_Discount = apartment_Discount * numberOfStay;
    }
    if (month == "July" || month == "August")
    {
        value = 76;
        studio_Discount = value;
        int Discountstudio = studio_Discount;
        apartment_Discount = 77;
        if (numberOfStays > 14)
        {
            int discounttwo;
            discounttwo = apartment_Discount - (apartment_Discount * 0.1);
            apartment_Discount = discounttwo;
        }
        studio_Discount = studio_Discount * numberOfStays;
        int numberOfStay = numberOfStays;
        apartment_Discount = apartment_Discount * numberOfStay;
    }

    return "Apartment: " + to_string(apartment_Discount) + "$.\nStudio: " + to_string(studio_Discount) + "$.";
}