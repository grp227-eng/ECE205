#include <iostream>
using namespace std;

class Book
{
public:

    Book()
    {
        type = type;
        pub_year = pub_year;
        isbn = isbn;
    }

    // Mutators (setters)
    void setCat(string type1)
    {
        type = type1;
    }

    void setDate(int year1)
    {
        pub_year = year1;
    }

    void setISBN(int isbn1)
    {
        isbn = isbn1;
    }

    // Accessors (getters)
    string getCat()
    {
        return type;
    }

    int getDate()
    {
        return pub_year;
    }

    int getISBN()
    {
        return isbn;
    }

    void get_input();
    void output();

private:
    string type;
    int pub_year;
    int isbn;
};

void Book::get_input()
{
    cout << "Enter the category: ";
    cin >> type;

    cout << endl;

    cout << "Enter the publishing year: ";
    cin >> pub_year;

    cout << endl;

    cout << "Enter the ISBN: ";
    cin >> isbn;

    cout << endl;
}

void Book::output()
{
    if ((type == "history") || (type == "History") )
    {
        if (pub_year > 1950)
        {
            cout << "The book with ISBN " << isbn << " is available." << endl;
        }
        else {
            cout << "The book with ISBN " << isbn << " is not available." << endl;
        }
    }
    else
    {
        cout << "The book with ISBN " << isbn << " is not available." << endl;
    }
}

int main()
{
    Book B1;
    B1.get_input();
    B1.output();
    return 0;
}
