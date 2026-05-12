//Define a class for operating on complex numbers named Complex
//member variables, type double, re and im
//default constructor that initializes re and im to zeros
//custom constructor that takes 2 numbers as arguments and sets the values of re and im
//

#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    public:
        //Constructor
        Complex(double reVal, double imVal);

        Complex(double reVal);

        //Default COnstructor
        Complex();

        //function that returns size of vector madee by complex numbers
        double calculateMagnitude(double re, double im);

        //functions to add/subtract complex numbers
        Complex add(Complex c1, Complex c2);
        Complex subtract(Complex c1, Complex c2);

        //Multiply
        Complex multiply(Complex c1, Complex c2);

        //Divide
        Complex divide(Complex c1, Complex c2);

        //Display complex numbers:
        void display();

    private:
        double re;
        double im;
};

int main()
{
    Complex c1(2, 3), c2;

    Complex sum = add(c1, c2);
    Complex difference = subtract(c1, c2);

    return 0;
}

Complex::Complex(double reVal, double imVal)
{
    re = reVal;
    im = imVal;
}

Complex::Complex(double reVal)
{
    re = reVal;
    im = 0;
}

Complex::Complex()
{
    re = 0;
    im = 0;
}

 double Complex::calculateMagnitude(double re, double im)
 {
     //Pythagorean Theorem
     double size = sqrt((re*re) + (im*im));

     return size;
 }

 Complex Complex::add(Complex c1, Complex c2)
 {
    Complex result;

    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;

   return result;
 }

 Complex Complex::subtract(Complex c1, Complex c2)
 {
    Complex result;

    result.re = c2.re - c1.re;
    result.im = c2.im - c1.im;

    return result;
 }

 Complex Complex::multiply(Complex c1, Complex c2)
 {
    Complex result;

    result.re = (c1.re*c2.re - c1.im*c2.im);

    result.im = (c1.re*c2.im + c1.im*c2.re);

    return result;

 }

 Complex Complex::divide(Complex c1, Complex c2)
 {
    Complex result;

    result.re = (c1.re*c2.re + c1.im*c2.im) / (c2.re*c2.re + c2.im*c2.im);

    result.im = (c1.im*c2.re - c1.re*c2.im) / (c2.re*c2.re + c2.im*c2.im);

    return result;
 }
 

void Complex::display()
{
	if (im < 0)
		cout << re << "-" << im << "i" << endl;
	else
		cout << re << "+" << im << "i" << endl;
}

