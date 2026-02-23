#include <iostream>
using namespace std;

void get_input(int& start_time_1, int& end_time_1)
{
    cout << "Provide start time (four digits): " << endl;
    cin >> start_time_1;
    cout << "Provide end time (four digits): " << endl;
    cin >> end_time_1;
}

int time_between(int start_time, int end_time)
{
    int difference, start_tot, end_tot;

    //converting start and end times to minutes
    //since type int, the division will account for whole part and modulo will account for remainder
    start_tot = (start_time/100)*60 + (start_time % 100); 
    end_tot = (end_time/100)*60 + (end_time % 100);

    difference = end_tot - start_tot;

    if (difference < 0) //if negative to account for transition from night to day
    {
        int tot_min_per_day = 24*60;
        
        int intermediate;

        intermediate = tot_min_per_day-start_tot;

        difference = intermediate + end_tot;
    }

    return difference;
}

int main()
{
    int start, end;
    int tot_minutes;

    get_input(start, end);

    tot_minutes = time_between(start, end);

    cout << "The amount of minutes between " << start << " and " << end << " is " << tot_minutes << endl;

    return 0;
}