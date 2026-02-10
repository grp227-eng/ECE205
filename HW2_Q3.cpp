#include <iostream>
using namespace std;

int main()
{
    //initializations
    double height, weight, hatSize, jacketSize, waistSize;
    int age;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //inputs
    cout << "What is your height in inches?" << endl;
    cin >> height;

    cout << "What is your weight in lbs?" << endl;
    cin >> weight;

    cout << "What is your age?" << endl;
    cin >> age;

    //Calculations
    hatSize = (2.9*weight) / height;

    jacketSize = (height*weight) / 288.0;

    for(int i=40; i <= age;  i=i+10) //i=i+10 accounts for 10 year increments
        jacketSize = jacketSize + (0.125);

    waistSize = weight/5.7;

    for (int n=30; n<=age; n=n+2) //n=n+2 account for 2 year increments
        waistSize = waistSize + 0.1;

    //Outputs
    cout << "The hat size is " << hatSize << "\n"
         << "The jacket size is " << jacketSize << "\n"
         << "The waist size is " << waistSize << endl;
        
    return 0;
}