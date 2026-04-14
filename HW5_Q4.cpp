#include <iostream>
using namespace std;

//Define a class named PrimeNumber
//default constructor sets prime number to 1
//another constructor allows caller to set the prime number
//add function to get the prime number
//overload the prefix and postfix and ++, -- operators so they return a PrimeNumber object 
//that is the next largest prime number and the next smallest prime number

class PrimeNumber
{
public:

    //Default Constructor
    PrimeNumber()
    {
        prime_num = 1;
    }

    //Parameterized Constructor
    PrimeNumber(int n)
    {
        prime_num = n;
    }

    //gets private variable and makes it public
    int get_prime_num()
    {
        return prime_num;
    }

    bool isPrime(int n);
    PrimeNumber operator++();
    PrimeNumber operator++(int);
    PrimeNumber operator--();
    PrimeNumber operator--(int);

private:
    int prime_num;

};

int main()
{
    PrimeNumber p(13);      // constructor with value

    cout << "Initial prime number: " << p.get_prime_num() << endl;

    // Test Prefix Increment
    ++p;
    cout << "After pre-increment: " << p.get_prime_num() << endl;

    // Test Postfix Increment
    p++;
    cout << "After post-increment: " << p.get_prime_num() << endl;

    // Test Prefix Decrement
    --p;
    cout << "After pre-decrement: " << p.get_prime_num() << endl;

    // Test Postfix Decrement
    p--;
    cout << "After post-decrement: " << p.get_prime_num() << endl;

    return 0;
}


//found online for relationship (as recommened in class)
bool PrimeNumber::isPrime(int n)
{
    if (n <= 1)
    {            
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

//prefix increment
PrimeNumber PrimeNumber::operator++()
{
    int n = prime_num + 1; //establishing that temporary var is not prime_num

    while (!isPrime(n)) //if not a prime number
    {
        n++; //increment 
    }

    prime_num = n; //setting object to new number

    return PrimeNumber(prime_num); //return object
}

//postfix increment
PrimeNumber PrimeNumber::operator++(int) //int is dummy variable to distinguish functions
{
    int orig_num = prime_num; //save current value
    int n = prime_num + 1; //establishing that temporary var is not prime_num

    while (!isPrime(n)) //if not a prime number
    {
        n++; //increment 
    }

    prime_num = n; //setting prime_num to new number

    return PrimeNumber(orig_num);
}

//prefix decrement
PrimeNumber PrimeNumber::operator--()
{
    int n = prime_num - 1; //establishing that temporary var is not prime_num

    while (n>=2 && !isPrime(n)) //if not a prime number and not 1
    {
        n--; //decrement 
    }

    prime_num = n; //setting object to new number

    return PrimeNumber(prime_num); //return object
}

//postfix decrement
PrimeNumber PrimeNumber::operator--(int) //int is a dummy variable to distinguish functions
{
    int orig_num = prime_num; //save current value
    int n = prime_num - 1; //establishing that temporary var is not prime_num

    while (n>=2 && !isPrime(n)) //if not a prime number and not 1
    {
        n--; //decrement 
    }

    prime_num = n; //setting object to new number

    return PrimeNumber(orig_num); //return object
}