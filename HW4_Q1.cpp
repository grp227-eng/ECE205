#include <iostream>
using namespace std;

void fillUp(int list[], int size);
int max_val(int list[], int size);
void sorting_bins(int list[], int bin_size, int max_val, int size);

int main()
{
    char response;
    do
    {
        int size;

        //ask for size input
        cout << "Please enter the size of the array: ";
        cin >> size;

        int list[size];

        fillUp(list, size);

        int max_num = max_val(list, size);

        cout << "The Histogram Model is:" << endl;
    
        sorting_bins(list, 10, max_num, size);

        cout << "Would you like to sort another input? (Y/n)" << endl;
        cin >> response;

    } while (response == 'Y' || response == 'y');
    

}

void fillUp(int list[], int size)
{
    cout << "List the non-negative integers separated by a space: ";

    //use for loop to add each value corresponding to the index position i
    for (int i=0; i<size; i++)
        cin >> list[i];
}

//function for finding max value in array (found in lecture notes)
int max_val(int list[], int size)
{
    double tmp;

    tmp = list[0];

    for (int i =0; i < size; i++)
    {
        if (list[i]>tmp)
        {
            tmp = list[i];
        }
        else 
        {
            tmp = tmp;
        }
    }

    return tmp;
}

void sorting_bins(int list[], int bin_size, int max_val, int size)
{
    //find number of bins needed
    int num_bins = (max_val/ bin_size) + 1; //10 is bin size and adding 1 account for any remainder


    for (int i=0; i<num_bins; i++)
    {
        int num_val = 0; //track how many values within bins
        int start_bin = i*10; //starting index of bin (0, 10, 20, ...)
        int end_bin = start_bin +9; //ending index of bin (9, 19, 29, ...)

        //counting how many values in list fall within the corresponding bin
        for (int j=0; j<size; j++)
        {
            if ((list[j] >= start_bin) && (list[j] <= end_bin))
            {
                num_val++;
            }
        }

        cout << "bin" << i+1 << "(" << start_bin << "-" << end_bin << "): " << num_val << " values" << endl;

    }
}

