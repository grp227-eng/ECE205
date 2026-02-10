#include <iostream>
#include <cmath>
using namespace std;

//Calculating Gravitational Force Between Two Masses
int main()
{
    //initializations
    double m1, m2, d, force, m1Grams, m2Grams;
    char choice; //establishing for do-while
    const double G=6.673E-8;

    cout.setf(ios::scientific); //formatting in scientific notation
    cout.setf(ios::showpoint);
    cout.precision(2);

    //do-while is implemented so that the calculation runs at least once but can run again if prompted to
    do
    {
        //inputs
        cout << "How many kg is m1?" << endl;
        cin >> m1;

        cout << "How many kg is m2?" << endl;
        cin >> m2;

        cout << "What is the distance d between the masses?" << endl;
        cin >> d;

        //Calculations
        m1Grams = m1 * 1000; //converting kg to g
        m2Grams = m2 * 1000; //converting kg to g

        force = (G*m1Grams*m2Grams) / pow(d,2.0); //equation for force

        cout << "The force is " << force << " dynes" << endl;

        //Calculation Repetition
        cout << "Would you like to repeat the calculation with differnet inputs? (y/n)" << endl;
        cin >> choice; 
    } while (choice == 'y' || choice == 'Y'); //repeats if 'y' or 'Y' is entered

    return 0;
}