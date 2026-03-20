#include <iostream>
using namespace std;

//global variable
const int rows = 3;
const int cols = 3;

void board_display(const char board[][cols], int rows);
void chosen_move(char board[][cols], int rows, char player);
bool check_win(const char board[][cols], int rows);

int main()
{
    //initializing board
    char board[rows][cols] = {
        {'1', '2', '3'}, 
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char player = 'X'; //sets player X to make first move
    bool done = false; //initialize to false so that true signals a winner
    int count_moves = 0; //initialize moves to 0, only allowed to make 9


    while (done==false && count_moves<9) //while no winner and still available moves
    {
        //shows board
        board_display(board, rows);
        //takes in move and sets it on the board
        chosen_move(board, rows, player);
        //counts how many moves completed
        count_moves = count_moves+1;
        //checks if there is a winner for every move
        done = check_win(board, rows);

        //while no winner and still available moves, alternates between players
        if (done == false && count_moves<9)
        {
            if (player == 'X') 
            {
                player = 'O';
            } 
            else 
            {
                player = 'X';
            }
        }

    }

    //displays final board once winner is found or out of moves
    board_display(board, rows);

    if (done == true)
    {
        //outputs winner if found
        cout << "Player " << player << " wins!" << endl;
    }
    else
    {
        //if run out of moves, outputs a draw
        cout << "It's a draw." << endl;
    }

    return 0;
}

//setting up board display
void board_display(const char board[][cols], int rows)
{
    //iterating through rows
    for (int i = 0; i < rows; i++ ) 
    {
        //iterating through columns
        for (int j=0; j < cols; j++) 
        {
            cout << board[i][j] << " "; //reserving space for numbers and adding spaces between
        }

        cout << endl; //start new line for next row
    }
}

void chosen_move(char board[][cols], int rows, char player)
{
    int choice;
    bool good = false;
    int choice_row_indx, choice_col_indx;

    do
    {
        //prompting player to input position
        cout << "Player " << player << ", enter a postion (1-9): ";
        cin >> choice;

        //calculating indexes of row and column)
        choice_row_indx = (choice -1)/3; //
        choice_col_indx = (choice -1)%3;

        //checking that choice is valid (1-9)
        if ((choice>=1) && (choice<=9))
            //checking that choice isnt already reserved by X or O
            if (board[choice_row_indx][choice_col_indx]!='X' && board[choice_row_indx][choice_col_indx]!='O')
            {
                board[choice_row_indx][choice_col_indx] = player; //setting indx of choice to X or O
                good = true;
            }
            else
            {
                cout << "Position already taken. Please choose again." << endl;
            }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
        
    } while (good != true); //will continue until player successfully makes a move
    
}

bool check_win(const char board[][cols], int rows)
{
    //check that row indexes are set to same character
    for(int i=0; i<rows; i++)
    {
        if ((board[i][0]==board[i][1]) && (board[i][1]==board[i][2]))
        {
            return true; //flags a win
        }
    }

    //check col indexes are set to same character
    for(int j=0; j<cols; j++)
    {
        if ((board[0][j]==board[1][j]) && (board[1][j]==board[2][j]))
        {
            return true;//flags a win
        }
    }

    //check that diag indexes are set to the same character
    if ((board[0][0]==board[1][1]) && (board[1][1]==board[2][2]))
        {
            return true;//flags a win
        }
    else if ((board[0][2]==board[1][1]) && (board[1][1]==board[2][0]))
        {
            return true;//flags a win
        }
    else
    {
        return false;//flags to continue playing
    }

}
