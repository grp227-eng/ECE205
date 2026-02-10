#include <iostream>
#include <cmath> //use for sqrt() and pow()
#include <fstream> //use file stream to implement text file

using namespace std;

int main()
{
    ifstream in; //input file, equivalent to cin
    ofstream out; //output file, equivalent to cout

    int n1, n2, n3, n4, n5;

    //read data from text file, text file in notepad
    in.open("scores.txt"); //open file

    //read in values from file
    in >> n1;
    in >> n2;
    in >> n3;
    in >> n4;
    in >> n5;

    in.close(); //close input file

    double avg = (n1+n2+n3+n4+n5)/5.0;

    double std_dev = sqrt((pow(n1-avg,2)+pow(n2-avg,2)+pow(n3-avg,2)+pow(n4-avg,2)+pow(n5-avg,2))/5.0);

    //write data in text file
    out.open("output.txt");
    
    //setting decimals for output file
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    //setting decimals for output in terminal
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //output to file
    out << "Average: " << avg << endl;
    out << "Standard Deviation: " << std_dev << endl;

    //display result in console
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << std_dev << endl;

    out.close();

    return 0;
}