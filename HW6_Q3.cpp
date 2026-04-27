//Sieve of Erathosthenes algorithm to find all prime integers less than
//user given integer
//Use vectors
//output all prime numbers

#include <iostream>
#include <vector>
using namespace std;

vector<int> SieveOfEratosthenes(int n);

int main(){
    int n;
    vector<int> myVector;

    cout << "Enter a cutoff integer: ";
    cin >> n;

    cout << endl;

    myVector = SieveOfEratosthenes(n);

    cout << "All the prime integers less than " << n << " :" << endl;

    for (int i = 0; i < myVector.size(); i++)
    {
        cout << myVector[i] << endl;
    }

    return 0;
}

vector<int> SieveOfEratosthenes(int n)
{
    vector<bool> prime(n+1, true);

    for (int i = 2; i * i<=n; i++)
    {
        if (prime[i] == true)
        {
            for(int j = i*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    vector<int> reserved;

    for(int i = 2; i <= n; i++){
        if(prime[i]){
            reserved.push_back(i);
        }
    }

    return reserved;
}
