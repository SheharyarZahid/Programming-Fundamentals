#include <iostream>
#include <string>
using namespace std;

string checkPointPosition(int h, int x, int y);

main() {
    int h, x, y;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    string result = checkPointPosition(h, x, y);
    cout << result;
}
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