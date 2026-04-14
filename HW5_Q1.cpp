#include <iostream>
using namespace std;

//define class called BicycleSpeedometer
//class will track distance traveled, travel time, average spedd
//member variables: distance traveled (miles), time taken (in minutes)
//mutator function: set distance and time
//member function: compute average speed (miles per hour)
//Test program: creates the class, reads input values for member varialbes, outputs average speed

//Followed Lecture Notes

class BicycleSpeedometer
{
public:
    //mutator (used to manipulate private variables)

    void set_distance(double distance1)
    {
        distance = distance1;
    }

    void set_time(double time1)
    {
        time = time1;
    }

    //accessor (used to make private variables available for mutator to manipulate)
    double get_distance()
    {
        return distance;
    }

    double get_time()
    {
        return time;
    }

    double average_speed();
    void display();

private:
    double distance;
    double time;
    double avg_speed;
};

int main()
{
    BicycleSpeedometer B1;

    B1.set_distance(130.0);
    B1.set_time(500.0);
    B1.average_speed();
    B1.display();

    return 0;
}

double BicycleSpeedometer::average_speed()
{
    double hours = time/60.0;
    avg_speed = distance / hours;
    
    return avg_speed;
}

void BicycleSpeedometer::display()
{
    cout << "When traveling " << distance << " miles for " << time << " minutes, the average speed is " << avg_speed << " miles per hour." << endl;
}