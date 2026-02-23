#include <iostream>
using namespace std;


void get_input(int& h1, int& m1)
{
    cout <<"Provide hour input: " << endl;
    cin >> h1; 

    cout << "Provide minute input (include two digits): " << endl;
    cin >> m1;
}

char convert(int& h)
{
    char x;

    if (h >= 12)
    {
        x = 'P';

        if (h>12)
        {
            h = h-12;
        }
    }
    else
    {
        x = 'A';
    }

    return x;
}


int main()
{
    int h, m;
    char x, response; //saving return from convert func in new variable

    do{
        get_input(h, m);

        x = convert(h);

        cout << "The time is: " << h << ":" << m << " " << x << "M" << endl;
        cout << "Would you like to give another input? (y/n)" << endl;
        cin >> response;
    } while(response == 'Y' || response == 'y');

    return 0;
}
