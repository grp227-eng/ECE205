#include <iostream>
using namespace std;

int main ( )
{
    //setting variable types
    int totalTimeSeconds, seconds, hours, minutes;
    double realHours, realMinutes;

    ////collecting input
    cout << "Total Time in Seconds:" << endl;
    cin >> totalTimeSeconds;
    
    //time calculations
    hours = totalTimeSeconds / 3600;
    minutes = (totalTimeSeconds % 3600) / 60;
    seconds = (totalTimeSeconds % 3600) % 60;

    realHours = double(totalTimeSeconds) / 3600; 
    realMinutes = double(totalTimeSeconds) / 60; 

    //found in textbook as a way to set number of decimal points
    cout.setf(ios::fixed);  //found in textbook
    cout.setf(ios::showpoint);
    cout.precision(4);
    
    //outputs
    cout << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds" << endl; //output of integer values
    cout << realHours << " hours and " << realMinutes << " minutes" <<endl; 
    
    return 0;
}