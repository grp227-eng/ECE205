#include <iostream>
using namespace std;

void weight_input(int& lbs, int& oz)
{
    cout << "For a weight in pounds and ounces, input the value for the pounds:" << endl;
    cin >> lbs;
    cout << "For a weight in pounds and ounces, input the value for the ounces:" << endl;
    cin >> oz;
}

void convert(int lbs, int oz, int& kg, int& g)
{
    double kg_tot, lbs_tot;

    lbs_tot = lbs + (oz/16.0);
    kg_tot = lbs_tot/2.2046;

    //assigning kg as an int will chop off the decimal portion
    kg = kg_tot;
    g = (kg_tot - kg) * 1000;
}

void display_output(int lbs, int oz, int kg, int g)
{
    cout << lbs << "lbs " << oz << "oz would be converted to " << kg << "kg " << g << "g" << endl;
}

int main()
{
    int lbs, oz, kg, g;
    char response;

    do{
        weight_input(lbs, oz);
        convert(lbs, oz, kg, g);
        display_output(lbs, oz, kg, g);

        cout << "Would you like to give another input? (y/n)" << endl;
        cin >> response;
    } while(response == 'Y' || response == 'y');

    return 0;
}