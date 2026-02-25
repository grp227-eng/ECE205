#include <iostream>
using namespace std;

void get_input(int& start_time_1, int& end_time_1)
{
    cout << "Provide start time in 24 hour notation (four digits): " << endl;
    cin >> start_time_1;
    cout << "Provide end time in 24 hour notation (four digits): " << endl;
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

char convert_start(int& h_start)
{
    char x;

    if (h_start >= 12)
    {
        x = 'P';

        if (h_start>12)
        {
            h_start = h_start-12;
        }
    }
    else
    {
        x = 'A';
    }

    return x;
}

char convert_end(int& h_end)
{
    char y;

    if (h_end >= 12)
    {
        y = 'P';

        if (h_end>12)
        {
            h_end = h_end-12;
        }
    }
    else
    {
        y = 'A';
    }

    return y;
}


int main()
{
    int start, end;
    int min_start, min_end, tot_minutes;
    int h_start, h_end;
    char x, y;
    
    get_input(start, end); //gets input

    tot_minutes = time_between(start, end);

    h_start = start/100;
    h_end = end/100;

    x=convert_start(h_start);

    y=convert_end(h_end);


    min_start = start % 100;
    min_end = end % 100;

    cout << min_start << endl;
    cout << min_end << endl;

    tot_minutes = time_between(start, end);

    cout << "The start time in 12 hour format: " << h_start << ":" << min_start << " " << x << "M" << endl;
    cout << "The end time in 12 hour format: " << h_end << ":" << min_end << " " << y << "M" << endl;
    cout << "The difference in minutes is: " << tot_minutes << " minutes" << endl;

    return 0;
}