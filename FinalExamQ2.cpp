//store database for books using a vector
//keep track of author, title, and publication year (store as strings)

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int menu();

class Book
{
    public:
        void addBook();

    private:
        string author;
        string title;
        string year;
};

int main()
{
    Book book1;

    vector<string> v;

    int choice = menu();

    if (choice == 1)
    {
        v.push_back(book1.author);
        v.push_back(book1.title);
        v.push_back(book1.year);
    }
    else if (choice == 2)
    {
        delete(string name, vector<string> &v)
    }
    else if (choice == 3)

    else
    {
        exit(1);
    }
    

}

int menu()
{
    int choice;

    cout << "Select from the following choices (Input a number):" << endl;
    cout << "1. Add new book" << endl;
    cout << "2. Delete book" << endl;
    cout << "3. Print list sorted by author" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;

    return choice;
}

void Book::addBook()
{
    cout << "Enter author: ";
    cin >> author;

    cout << "Enter Title: ";
    cin >> title;

    cout << "Enter date: ";
    cin >> year;
}

void delete(string name, vector<string> &v)
{
    for(int i = 0; i<v.size(); i++)
        if (v[i] == name)
            delete v[i];
}



