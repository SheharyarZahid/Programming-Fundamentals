#include <iostream>

using namespace std;

int calculateVolleyballGames(string, int, int);

main()
{
    string yearType;
    int holidays, weekends;

    cout << "Enter year type: ";
    cin >> yearType;

    cout << "Enter number of holidays: ";
    cin >> holidays;

    cout << "Enter number of weekends: ";
    cin >> weekends;

    int result;
    result = calculateVolleyballGames(yearType, holidays, weekends);
    cout << result;
}

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
