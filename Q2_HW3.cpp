#include <iostream>
#include <cmath>
using namespace std;

void area_tri(double a, double b, double c, double& area, double& perimeter)
{
    //sum of any two sides is greater that the third side
    if ((a+b)>c && (a+c)>b && (b+c)>a && a>0 && b>0 && c>0)
    {
        double s;

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        perimeter = a+b+c;
        s = perimeter/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    else
    {
        perimeter = 0;
        area = 0;
    }
    //return not needed for call-by-reference parameters
}

int main()
{
    double a, b, c, area, perimeter;
    
    cout << "Provide the length of side a:" << endl;
    cin >> a;
    cout << "Provide the length of side b:" << endl;
    cin >> b;
    cout << "Provide the length of side c:" << endl;
    cin >> c;
    
    area_tri(a, b, c, area, perimeter);

    cout << "The area of the triangle is: " << area << endl;
    cout << "The perimeter of the triangle is: " << perimeter << endl;

    return 0;
}
