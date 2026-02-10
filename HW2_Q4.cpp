#include <iostream>
#include <ctime> //for srand(time())
#include <cstdlib> //library containing rand()
using namespace std;

int main()
{
    //setting seed
    srand(time(0));

    int f1, f2, f3, f4; 

    f1 = rand() %25 +1; //returns a number between 1 and 25

    do
    {
        f2 = rand() %25 + 1;
    } while (f2 == f1); //will run through once and repeat if there is a match

    do
    {
        f3 = rand() %25 + 1;
    } while(f3 == f1 || f3 == f2); //will run through once and repeat if there is a match

    do
    {
        f4 = rand() %25 + 1;
    } while(f4 == f1 || f4 == f2 || f4 == f3); //will run through once and repeat if there is a match
    
    //Outputs
    cout << "The finalists are " << f1 << ", " << f2 << ", " << f3 << ", and " << f4 << endl;

    return 0;
}