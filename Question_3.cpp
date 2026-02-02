#include <iostream>
#include <iomanip> //found in textbook for establishing table
using namespace std;

int main( )
{
    //setting variable types
    int numberOfMonths;
    double monthlyPayment, interestRate, principal, monthlyInterest, totalInterest, totalPaid, monthlyPrincipalPaid;

    //found in textbook as a way to set number of decimal points
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //establishing header for table, found formatting in textbook sections about arrays
    cout << left << setw(7) << "Month #"
         << right << setw(12) << "Interest"
         << right << setw(15) << "Principal" 
         << right << setw(15) << "Balance" 
         << right << setw(18) << "Total Interest"
         << right << setw(15) << "Total Paid" << endl;
    
    //setting/initializing values
    interestRate = 0.015;
    principal = 1000;
    numberOfMonths = 0;
    totalInterest = 0;
    totalPaid = 0;
   
    while (principal > 0)
        {
            //interest calculations
            monthlyInterest = interestRate * principal;
            totalInterest = totalInterest + monthlyInterest;
            //increment operator
            numberOfMonths++;

            //monthly payment calculations
            if ((principal + monthlyInterest) <= 50 )
                {
                    monthlyPayment = monthlyInterest + principal;
                }
            else
                {
                    monthlyPayment = 50;
                }

            principal = principal - (monthlyPayment - monthlyInterest);
            totalPaid = totalPaid + monthlyPayment;
            monthlyPrincipalPaid = monthlyPayment - monthlyInterest;

            //establishing column outputs for table, found formatting in textbook sections about arrays
            cout << right << setw(7) << numberOfMonths
                 << right << setw(5) << "$" << right << setw(7) << monthlyInterest 
                 << right << setw(8) << "$" << right << setw(7) << monthlyPrincipalPaid 
                 << right << setw(8) << "$" << right << setw(7) << principal 
                 << right << setw(10) << "$" << right << setw(8) << totalInterest 
                 << right << setw(7) << "$" << right << setw(8) << totalPaid << endl;
        }

    return 0;
}