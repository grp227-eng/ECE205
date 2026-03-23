#include <iostream>
using namespace std;

void fillUp(int a[], const int size = 50, int& numberUsed);
int min_val(int a[], int numberUsed);
double computeAverage(const int a[], int numberUsed);

int main()
{
    int a[50], numberUsed, size, min_num, avg;
    fillUp(a, size, numberUsed);
    min_num = min_val(a, numberUsed);
    avg = computeAverage(a, numberUsed);


    cout << "The minimum value is: " << min_num << endl;
    cout << "The average is: " << avg << endl;

    return 0;
}

void fillUp(int a[], const int size = 50, int& numberUsed)
{
    cout << "List the non-negative integers separated by a space and mark the end with a negative number: ";

    int next, index=0;
    cin >> next;

    while ((next >=0) && (index < size))
    {
        if (next <= 100)
        {
            a[index] = next;
            index++;
            cin >> next;
        }
    }

    numberUsed = index;
}

int min_val(int a[], int numberUsed)
{
	

	int tmp;

	tmp = a[0];

	for (int i = 0; i < numberUsed; i++)

	{
		if (a[i] < tmp)

		{
			tmp = a[i];
		}

		else
		{
			tmp = tmp;
		}

	}
	return tmp;
}

double computeAverage(const int a[], int numberUsed)
{
    double total = 0;
    for (int index = 0; index < numberUsed; index++)
    total = total + a[index];
    
    if (numberUsed > 0)
    {
    return (total/numberUsed);
    }
    else
    {
    cout << "ERROR: number of elements is 0 in computeAverage.\n"
    << "computeAverage returns 0.\n";
    return 0;
    }
    }