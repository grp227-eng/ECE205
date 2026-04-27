//takes in a list of integers from the user
//calculates a histogram
//use vectors 
//negative input ends the input
//bins are of size 10
//output histogram to console as a list of bins and the number of values that fall into each

#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> myVector);
void display_hist(vector<int> histogram);

int main()
{
    vector<int> myVector;
    int number;

    cout << "Please enter an integer. A negative integer will signal end of data aquisition. " << endl;
    cin >> number;

    while (number >= 0)
    {
        myVector.push_back(number); //add number to every end of vector

        cout << "Please enter an integer. A negative integer will signal end of data aquisition. " << endl;
        cin >> number;
    };
    
    int max = findMax(myVector);

    vector<int> histogram(max/10 +1, 0);
    //max/10 + 1 calculates how man bins of ten needed  
    //zero makes sure every bin stays empty

    for (int i = 0; i < myVector.size(); i++)
    {
        int bin = myVector[i] / 10; //divides vector element by 10 to determine which bin
        histogram[bin]++; //increments to account for number of elements in bin
    }

    //displays bin output
    display_hist(histogram);

    return 0;
}

int findMax(vector<int> myVector)
{
    int max = 0; //initialize maximum value as 0

    for (int i = 0; i < myVector.size(); i++) //looks at every element in vector
        if (myVector[i] > max) //is the number bigger that the largest so far
            max = myVector[i]; //update max if so

    return max; //return maximum element in vector
}

void display_hist(vector<int> histogram)
{
    for (int i = 0; i < histogram.size(); i++)
    {
        cout << "Bin " << i+1 << " ("<< i*10 << "-" << ((i+1)*10-1) << ")" << " contains " << histogram[i] << endl;
    }
}