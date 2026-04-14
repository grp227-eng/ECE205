#include <iostream>
using namespace std;

//define class called Pizza
//member variables: deep_dish, hand_tossed, pan, small, medium, large, num_toppings
//use consts for type and size
//include mutator functions in class
//create void function outputDescription() that outputs textual description of pizza
//create function computePrice() that computes cost pizza and returns it as a double

//small = $10 + $2 per topping
//medium = $14 + $2 per topping
//large = $17 + $2 per topping

class Pizza
{
public:
    //define const parameters
    static const int deep_dish = 1;
    static const int hand_tossed = 2;
    static const int pan = 3;
    static const int small = 1;
    static const int medium = 2;
    static const int large = 3;

    //statis keeps values constant in every object/function of the class

    //mutator
    void set_type(int type1 )
    {
        type = type1;
    }

    void set_size(int size1 )
    {
        size = size1;
    }

    void set_toppings(int toppings1 )
    {
        toppings = toppings1;
    }

    //accessor
    int get_type()
    {
        return type;
    }

    int get_size()
    {
        return size;
    }

    int get_toppings()
    {
        return toppings;
    }

    void get_input();
    double compute_price();
    void output_description();

private:
    int type;
    int size;
    int toppings;
};

int main()
{
    Pizza P1;
    P1.set_type(2);
    P1.set_size(3);
    P1.set_toppings(1);

    double cost1 = P1.compute_price();

    cout << "Pizza 1" << endl;
    P1.output_description();
    
    cout << "My total cost is: $" << cost1 << endl;

    cout << endl;

    Pizza P2;
    P2.get_input();

    double cost2 = P2.compute_price();

    cout << "Pizza 2" << endl;
    P2.output_description();
    
    cout << "My total cost is: $" << cost2 << endl;

    return 0;
}

void Pizza::get_input()
{
    cout << "Enter the type of pizza (1 for Deep Dish, 2 for Hand Tossed, 3 for Pan): ";
    cin >> type;

    cout << endl;

    cout << "Enter the size of pizza (1 for Small, 2 for Medium, 3 for Large): ";
    cin >> size;

    cout << endl;

    cout << "Enter the number of toppings desired: ";
    cin >> toppings;

    cout << endl;
}

double Pizza::compute_price()
{
    double cost;

    if (size == 1)
    {
        cost = 10 + 2*toppings;
    }
    else if (size == 2)
    {
        cost = 14 + 2*toppings;
    }
    else if (size == 3)
    {
        cost = 17 + 2*toppings;
    }

    return cost;
}

void Pizza::output_description()
{
    if (type == 1)
    {
        cout << "Pizza Type: Deep Dish" << endl;
    }
    else if (type == 2)
    {
        cout << "Pizza Type: Hand Tossed" << endl;
    }
    else
    {
        cout << "Pizza Type: Pan" << endl;
    }

    if (size == 1)
    {
        cout << "Pizza Size: Small" << endl;
    }
    else if (size == 2)
    {
        cout << "Pizza Size: Medium" << endl;
    }
    else
    {
        cout << "Pizza Size: Large" << endl;
    }

    cout << "Number of Pepperoni or Cheese Toppings: " << toppings << endl;
}