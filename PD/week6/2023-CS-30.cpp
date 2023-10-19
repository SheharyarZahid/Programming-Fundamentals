//                             task1
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
//                           task2
float calculateAverage(float marksEnglish, float marksMaths, float marksChemistry, float marksSocialScience, float marksBiology)
{
    float avg;
    avg = marksEnglish + marksBiology + marksChemistry + marksSocialScience + marksMaths;
    avg = (avg / 500) * 100;
    return avg;
}
string calculateGrade(float averageofstudents)
{
    string graded;
    if (averageofstudents >= 90)
    {
    string grade;

        grade = "A+";
    }
    else if (averageofstudents >= 80 && averageofstudents < 90)
    {
    string grade;

        grade = "A";
    }
    else if (averageofstudents >= 70 && averageofstudents < 80)
    {
    string grade;

        grade = "B+";
    }
    else if (averageofstudents >= 60 && averageofstudents < 70)
    {
    string grade;

        grade = "B";
    }
    else if (averageofstudents >= 50 && averageofstudents < 60)
    {
    string grade;

        grade = "C";
    }
    else if (averageofstudents >= 40 && averageofstudents < 50)
    {
    string grade;

        grade = "D";
    }
    else
    {
    string grade;

        grade = "F";
    }
    graded=grade;
    return graded;
}
//                            task3
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
//                              task4
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
        }
        else
        {
            float mins;
            mins = 10;
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
            }
            else
            {
                float mins;
                mins = 25;
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
            }
            else
            {
                float mins;
                mins = 25;
            }
        }
    }
    return mins;
}
//                                 task5
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
        else if (fruit == "orange")
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
//                                           task6
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
//                                  task7
string checkStudentStatus(int examHour, int examMinute, int studentHour, int studentMinute)
{
    int examtime, arrivetime;
    string result;
    examtime = examHour * 60 + examMinute;
    int exam=examtime;
    arrivetime = studentHour * 60 + studentMinute;
    int arrive=arrivetime;
    string returns;
    if (arrivetime == examtime || (examtime - arrivetime) <= 30)
    {
        returns="Ontime";
        result = "On time";
        if ((examtime - arrivetime) <= 30 && (examtime - arrivetime) != 0)
        {
            result = "On time\n" + to_string(examtime - arrivetime) + " minutes before the start";
        }
    }
    if (arrivetime < examtime)
    {
        if (examtime - arrivetime < 60 && (examtime - arrivetime) > 30)
            result = "Early\n" + to_string(examtime - arrivetime) + " minutes before the start";
        if (examtime - arrivetime >= 60)
        {
            int h, m;
            int timeremains = examtime - arrivetime;
            int examedtime=timeremains;
            int hours = timeremains / 60;
            int hour=h;
            h = hours % 10;
            int hoursremain=h;
            if (hours == 1)
            {
            int minutes=m;
                m = 0;
            }
            else
            {
                if (timeremains > 60)
                {
                int minutes=m;
                    m = timeremains - (60 * h);
                }
            }
            result = "Early\n" + to_string(h) + ":" + to_string(m) + " hours before the start";
        }
    }
    if (arrivetime > examtime)
    {
        if (arrivetime - examtime < 60)
        {
            int timeremains = arrivetime - examtime;
            int examedtime=timeremains;
            result = "Late\n" + to_string(timeremains) + " minutes after the start";
        }
        if (arrivetime - examtime >= 60)
        {
            int h, m;
            int hour=h;
            int timeremains = arrivetime - examtime;
            int minutes=m;
            int hours = timeremains / 60;
            h = hours % 10;
            int hoursremain=h;
            if (hours == 1)
            {
                m = 0;
            }
            if (timeremains > 60)
            {
                m = timeremains - (60 * h);
                int minutes=m;
            }
            result = "Late\n" + to_string(hours) + ":" + to_string(m) + " hours after the start";
        }
    }
    return result;
}
//                                    task8
int calculateVolleyballGames(string yearType, int holidays, int weekends)
{
    int answer;

    if (yearType == "leap")
    {
        int holiday;
        holiday = holidays * 0.67;
        int weekend;
        weekend = weekends * 0.75;
        int final;
        final = holiday + weekend;
        answer = 48 - 48 * 0.15;
        answer = answer + final + 1;
        return answer;
    }

    else
    {
        int answer;
        int holiday;
        holiday = holidays * 0.67;
        int weekend;
        weekend = weekends * 0.75;
        int final;
        final = holiday + weekend;
        answer = 48 - 48 * 0.15;
        answer = answer + final;
        answer = answer - answer * 0.15;
        if (answer >= 44)
            answer += 2;
        answer += 1;
        return answer;
    }
}
//                                    task9
string checkPointPosition(int h, int x, int y)
{
    int x_cord;
    x_cord = x;
    int y_cord;
    y_cord = y;
    int h_cord;
    h_cord = h;
    bool onshape = (x_cord == h_cord && y_cord >= h_cord && y_cord <= 3 * h_cord);
     bool onshape1=(x_cord >= 0 && x_cord <= 3 * h_cord && (y_cord == 0 || y_cord == h_cord));
     bool onshape2= (y_cord >= 0 && y_cord <= 4 * h_cord && (x_cord == 0 || x_cord == 2 * h_cord));

    if (onshape || onshape1||onshape2)
    {
        return "Border";
    }
    else if (x_cord > 0 && x_cord < 2 * h_cord && y_cord > 0 && y_cord < 4 * h_cord)
    {
        return "Inside";
    }
    else
    {
        return "Outside";
    }
}
