#include <iostream>
#include <cmath>

void evaluateEquation(int a, int b, int c);

using namespace std;

main()
{
    int a, b, c;

    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    cout << "Enter the value of c: ";
    cin >> c;

    evaluateEquation(a, b, c);
}

void evaluateEquation(int a, int b, int c)
{
    int determinant = (b * b) - 4 * a * c;

    if (determinant > 0)
    {
        double secondAnswer = (-b + sqrt(determinant)) / (2 * a);
        double firstAnswer = (-b - sqrt(determinant)) / (2 * a);
        cout << "Solutions: x = " << secondAnswer << " and x = " << firstAnswer;
    }

    if (determinant == 0)
    {
        double answer = -b / (2 * a);
        cout << "Solution: x = " << answer;
    }
	
    else
    {
        double secondAnswer = (sqrt(-(determinant)) / (2 * a));
        double firstAnswer = (-b / (2 * a));
        cout << "Complex Solutions: x = " << firstAnswer << " + " << secondAnswer << "i and x = " << firstAnswer << " - " << secondAnswer << "i";
    }

}