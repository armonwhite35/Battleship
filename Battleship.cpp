#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int num;
    cout << "Enter a size for the board: ";
    cin >> num;
    cout << endl;
    int guessRow;
    int guessCol;
    int guesses = 0;
    int ship[num][num];
    srand(time(0)); //used to not obtain the same random number
    int shipRow = rand() % (num-1);//random coordinates
    int shipCol = rand() % (num-1);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)//assigns 0 to values of original matrix
        {
            ship[i][j] = 0;
        }
    }
    ship[shipRow][shipCol] = 1;//random value in original matrix



    char board[num][num];//battleship board
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            board[i][j] = '0';
        }
    }
    while (guesses != 3) {
        for (int i = 0; i < num; i++)//prints board to screen
        {
            for (int j = 0; j < num; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
        cout << "Location (Row [1-" << num << "] column [1-"<< num << "]): ";
        cin >> guessRow >> guessCol;
        cout << endl;
        board[guessRow - 1][guessCol - 1] = 'X';//marks spot that was guessed (-1 because index in matrix starts at 0)
        if ((guessRow - 1) == shipRow && (guessCol - 1) == shipCol)//compares board to original matrix
        {
            cout << "you sunk my battle ship!" << endl;
            board[guessRow - 1][guessCol - 1] = 'O';//marks correct spot
            break;
        }
        if ((guessRow > num || guessRow < 1)|| (guessCol > num || guessCol < 1)) {
            cout << "Invalid Position!" << endl;
        }
        guesses = guesses + 1;
    }


    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}