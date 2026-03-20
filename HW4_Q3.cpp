#include <iostream>
using namespace std;

//global variables establishing row and column size
const int rows = 10, cols = 4;

void seat_display(const char plane[][cols], int rows);
void seat_chosen(char plane[][cols], int rows);

int main()
{
    char response;

    char plane[rows][cols]; //initialize 2D array dimensions

    //for loop iterates through columns and sets each row to a letter
    for (int i=0; i<rows; i++)
    {
        plane[i][0] = 'A';
        plane[i][1] = 'B';
        plane[i][2] = 'C';
        plane[i][3] = 'D';
    }

    do
    {
        seat_display(plane, rows); //displays seating
        seat_chosen(plane, rows); //prompts for seat reservation

        cout << "Would you like to make another selection? (Y/N) ";
        cin >> response;

    } while (response == 'Y' || response == 'y'); //allows for multiple selections to be made
    
    cout << "Finalized Seating: " << endl;
    seat_display(plane, rows); //displays final seating arrangement

    return 0;
}

//setting up seat display without any reservations
void seat_display(const char plane[][cols], int rows)
{
    for (int i = 0; i < rows; i++ ) //counts rows 1-10
    {
        cout << (i+1) << " "; //displays row number (need to add once since index starts at 0)
        
        for (int j=0; j < cols; j++) //reserves spot to display letters for columns per row and separated with a space
        {
            cout << plane[i][j] << " ";
        }

        cout << endl; //start new line for next row
    }

}


void seat_chosen(char plane[][cols], int rows)
{
    int chosen_row, col_indx;
    char chosen_col;
    bool good = false;

    do
    {
        //takes inputs
        do
        {
            cout << "Please enter desired row number: ";
            cin >> chosen_row;

            //checks if valid choice
            if ((chosen_row < 1) || (chosen_row > rows))
            {
                cout << "Invalid choice." << endl;
            }

        } while ((chosen_row < 1) || (chosen_row > rows)); //will prompt until a valid choice is entered

        do
        {
            cout << "Please enter desired seat: ";
            cin >> chosen_col;

            //establishing column index for chosen seat (accounts for case sensitivity)
            if ((chosen_col == 'A') || (chosen_col == 'a')) 
            {
                col_indx = 0; //sets A as column index 0
            }
            else if ((chosen_col == 'B') || (chosen_col == 'b'))
            {
                col_indx = 1; //sets B as column index 1
            }
            else if ((chosen_col == 'C') || (chosen_col == 'c'))
            {
                col_indx = 2; //sets C as column index 2
            }
            else if ((chosen_col == 'D') || (chosen_col == 'd'))
            {
                col_indx = 3; //sets D as column index 3
            }
            else //case for different letter input
            {
                col_indx = -1;
                cout << "Invalid choice." << endl;
            }
        } while(col_indx == -1); //will prompt until valid choice is input

        //reserving seat
    
        //checks that chosen row and seat are valid
        
        if (plane[chosen_row-1][col_indx] != 'X') //if index of seat is not set to 'X'
        {
            plane[chosen_row-1][col_indx] = 'X'; //sets position to 'X'

            cout << "Your seat has been reserved." << endl;

            good = true;
        }
        else //in case index is already set to 'X'
        {
            cout << "That seat is unavailable. Please select another." << endl;
        }
       
    } while (good != true); //will continue until a valid and unreserved seat is chosen

}