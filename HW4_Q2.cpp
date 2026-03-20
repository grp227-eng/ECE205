#include <iostream>
using namespace std;

void get_input(double scores[], double& diff_deg);
double scores_min(const double scores[], const int size);
double scores_max(const double scores[], const int size);

int main()
{
    double scores[7]; //initializes array of size 7
    double diff_deg;
    int size = 7;
    double min_score, max_score;
    char response;

    do
    {          
        //receive inputs
        get_input(scores, diff_deg);
    
        //calculate min and max scores
        min_score = scores_min(scores, size);
        max_score = scores_max(scores, size);

        double sum=0; //initialize sum to be zero
        double adjusted_sum;

        //for loop adds each element of the array by going through index of each
        for (int i=0; i<size; i++)
        {
            sum = sum + scores[i];
        }

        adjusted_sum = sum - min_score - max_score; //removes min and max values

        double final_score;

        final_score = adjusted_sum*diff_deg*0.6;

        cout << "The diver's score is: " << final_score << endl;
        cout << "Would you like to calculate another score? (Y/n)" << endl;
        cin >> response;

    } while (response =='Y'|| response == 'y');

    return 0;
}

void get_input(double scores[], double& diff_deg)
{
    do
    {
        //degree of difficulty input
        cout << "What is the degree of difficulty of the dive within a range of 1.2-3.8?" << endl;
        cin >> diff_deg;

        //checks that input falls within desired range
        if ((diff_deg < 1.2) || (diff_deg > 3.8))
        {
            cout << "Error. Input is not within range of 1.2-3.8." << endl;
        }
    } while ((diff_deg < 1.2) || (diff_deg > 3.8)); //repeats if invalid input, runs at least once
    
    cout << "Provide the 7 judges' scores within a range of 0-10 (separate each with a space): ";

    //use for loop to add each value corresponding to the index position i
    for (int i=0; i < 7; i++)
    {
        do
        {
            cin >> scores[i];

            //check that input falls within the desired range
            if ((scores[i] < 0) || (scores[i] > 10))
            {
                cout << "Error. Input is not within range of 0-10. Please Re-enter." << endl;
            }
       
        }while ((scores[i] < 0) || (scores[i] > 10)); //repeats if invalid input, runs at least once
    }
}

//function that finds min score (taken from lecture notes)
double scores_min(const double scores[], const int size)
{
    double tmp;

    tmp = scores[0];

    for (int i =0; i < size; i++)
    {
        if (scores[i]<tmp)
        {
            tmp = scores[i];
        }
        else 
        {
            tmp = tmp;
        }
    }

    return tmp;
}

//function that finds max score (adjusted previous function to account for maximum instead of minimum)
double scores_max(const double scores[], const int size)
{
    double tmp;

    tmp = scores[0];

    for (int i =0; i < size; i++)
    {
        if (scores[i]>tmp)
        {
            tmp = scores[i];
        }
        else 
        {
            tmp = tmp;
        }
    }

    return tmp;
}