#include <iostream>
using namespace std;

int main ( )
{
    //setting variable types
    int numberOfDependents, unionDues, healthInsurance;
    double hours, grossPay, netPay, hourlyRate, socialSecurity, federal, state, bethlehem;
    
    hourlyRate = 36.75;

    //collecting inputs
    cout << "How many dependents do you have?" << endl;
    cin >> numberOfDependents;

    cout << "How many hours did you work this week?" << endl;
    cin >> hours;

    //if else statement calculating gross pay in regards to overtime or no overtime
    if (hours > 40)
        {
            grossPay = (40 * hourlyRate) + ((hours - 40) * (1.5 * hourlyRate));
        }
    else
        {
            grossPay = 40 * hourlyRate;
        }

    //if else statement establishing health insurance based on number of dependents
    if (numberOfDependents >= 2)
        { 
            healthInsurance = 40;
        }
    else
        {
            healthInsurance = 0;
        }

    //calculations of taxes
    socialSecurity = 0.06 * grossPay;
    federal = 0.15 * grossPay;
    state = 0.04 * grossPay;
    bethlehem = 0.01 * grossPay;
    unionDues = 20;

    //calculation of net pay; gross pay - taxes
    netPay = grossPay - (socialSecurity + federal + state + bethlehem + unionDues + healthInsurance);

    //found in textbook as a way to set number of decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //outputs
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Social Security Deduction: $" << socialSecurity << endl;
    cout << "Federal Income Deduction: $" << federal << endl;
    cout << "State Deduction: $" << state << endl;
    cout << "Bethlehem Local Deduction: $" << bethlehem << endl;
    cout << "Union Dues: $" << unionDues << endl;
    cout << "Health Insurance: $" << healthInsurance << endl;
    cout << "Net Pay: $" << netPay << endl;

    return 0;
}