//takes user input for a list of characters ('0' will end selection)
//stores characters in a vector
//create a function that will delete and repeated entries
//create a function that will sort the vector in decreasing order (z-a)
//          use selection sort

#include <iostream>
#include <vector>
using namespace std;

void deleteRepeatedChars(vector<char> &myVector);
void selectionSort(vector<char> &myVector);

int main()
{
    vector<char> myVector;
    char input;

    cout << "Please enter a character (a-z). Enter 0 to end input." << endl;
    cin >> input;

    while (input != '0')
    {
        myVector.push_back(input);

        cout << "Please enter a character (a-z). Enter 0 to end input." << endl;
        cin >> input;
    }

    selectionSort(myVector);

    deleteRepeatedChars(myVector);

    cout << "Array with repeated characters removed and ordered reversely (z-a):" << endl;

    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }

    return 0;
}

void deleteRepeatedChars(vector<char> &myVector)
{
    for (int i = 0; i < myVector.size(); i++)
    {
  	    for (int j = i + 1; j < myVector.size(); j++)
        {
			if(myVector[i] == myVector[j])
            {
                int n = myVector.size();
                
                for(int k = j; k < n-1; k++)
                {
                    myVector[k] = myVector[k+1];
                }
        
                myVector.resize(myVector.size()-1);
                j--; 
                
            }
        }
    }

}

void selectionSort(vector<char> &myVector)
{
    int n = myVector.size();

    for (int i = 0; i < n - 1; i++)
    {
        int max_idx = i; //assume current position holds maximum element

        //iterate through unsorted portion to find actual maximum
  	    for (int j = i + 1; j < n; j++)
        {
            if(myVector[j] > myVector[max_idx])
            {
                max_idx = j;
            }
        }

        swap(myVector[i], myVector[max_idx]); //move maximum element to corrent position
    }
}
