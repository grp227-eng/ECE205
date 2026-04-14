#include <iostream>
#include <vector>
using namespace std;

//Complete Programming Project 6.7 from Ch. 6 (Q2 from homework)
//Add Order class that contains private vector of type Pizza
//Order class represents entire order (multiple pizzas)
//write function that can add pizzas to the order
//write function that outputs everthing in order and the total cost

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

    //Default Constructor
    Pizza()
    {
        type = hand_tossed;
        size = small;
        toppings = 0;
    }

    //Parameterized Constructor
    Pizza(int t, int s, int top)
    {
        type = t;
        size = s;
        toppings = top;
    }

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

    double compute_price();
    void output_description();
    void get_input();

private:
    int type;
    int size;
    int toppings;
};

class Order
{
public:
    void add_pizza(const Pizza& p)
    {
        //to add an element to a vector, use the member function push_back
        Pizzas.push_back(p);
    }

    void add_pizza(int type, int size, int toppings)
    {
        Pizza p(type, size, toppings);
        Pizzas.push_back(p);
    }

    void outputOrder()
    {
        double totalPrice = 0.0;

        if (Pizzas.empty())
        {
            cout << "No pizzas in the order." << endl;
        }

        for (int i=0; i < Pizzas.size(); i++)
        {
            cout << "Pizza #" << i+1 << ": ";
            Pizzas[i].output_description();

            cout << "Price: $" << Pizzas[i].compute_price() << endl;
            
            totalPrice += Pizzas[i].compute_price();
        }

        cout << "Total Order Price: $" << totalPrice << endl;
        cout << "------------------------------" << endl;
    }

private:
   vector<Pizza> Pizzas; 

};

int main()
{
    Order order;
    char response;
    int n = 0;

    cout << "Pizza Order" << endl;

    do {
        int size, toppings, type;

        Pizza new_pizza;

        new_pizza.get_input();

         //Output detail for pizza1
        cout << "----Pizza " << ++n << "----" << endl;
        new_pizza.output_description();
        cout << "Price: $" <<new_pizza.compute_price() << endl;

        cout << endl;

        order.add_pizza(new_pizza);

        cout << endl;

        cout << "Would you like to add another pizza to your order? (y/n)" << endl;
        cin >> response;

        cout << endl;

    }while(response == 'Y' || response == 'y');

    cout << "----Order Summary----" << endl;
    order.outputOrder();

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