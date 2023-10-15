#include<iostream>
using namespace std;
string findZodiacSign(int day, string month);
main(){
   int day;
    string month;
    cout << "Enter the day of birth: ";
    cin >> day;
    cout <<"Enter the month of birth (e.g., January, February): ";
    cin >> month;
string sign= findZodiacSign(day, month);
    cout <<"Zodiac Sign: "<< sign;
}
string findZodiacSign(int day, string month)
{
    string sign;
    string months = month;
    if ((months == "March" && day >= 21) || (months == "April" && day <= 19))
    {
        sign = "Aries";
        return sign;
    }
    if ((months == "April" && day >= 20) || (months == "May" && day <= 20))
    {
        sign = "Taurus";
        return sign;
    }
    if ((months == "May" && day >= 21) || (months == "June" && day <= 20))
    {
        sign = "Gemini";
        return sign;
    }
    if ((months == "June" && day >= 21) || (months == "July" && day <= 22))
    {

        sign = "Cancer";

        return sign;
    }
    if ((months == "July" && day >= 23) || (months == "August" && day <= 22))
    {
        sign = "Leo";

        return sign;
    }
    if ((months == "August" && day >= 23) || (months == "September" && day <= 22))
    {
        sign = "Virgo";

        return sign;
    }
    if ((months == "December" && day >= 22) || (months == "January" && day <= 19))
    {
        sign = "Capricon";

        return sign;
    }
    if ((months == "September" && day >= 23) || (months == "October" && day <= 22))
    {
        sign = "Libra";

        return sign;
    }
    if ((months == "October" && day >= 23) || (months == "November" && day <= 21))
    {
        sign = "Scorpio";

        return sign;
    }
    if ((months == "January" && day >= 20) || (months == "February" && day <= 18))
    {
        sign = "Aquarius";
        return sign;
    }
    if ((months == "November" && day >= 22) || (months == "December" && day <= 21))
    {
        sign = "Sagittarius";

        return sign;
    }
}