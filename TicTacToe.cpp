/*
    ============================================================
     Mini Game Project : Tic Tac Toe
    ============================================================
     Description : A console-based Tic Tac Toe game written in
                    standard C++ (no external libraries), built
                    to demonstrate core programming concepts:
                        - Loops (for, while)
                        - Arrays (2D board representation)
                        - Conditional logic (win/draw detection)
                    The board is redrawn dynamically after every
                    move, and the game offers a replay option
                    once it ends.

     Compiles with : Dev-C++ (TDM-GCC / MinGW), Code::Blocks,
                      g++ (Linux/Mac), Visual Studio, etc.
                      Pure standard C++ - no platform-specific
                      headers used, so it runs anywhere.
    ============================================================
*/

#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 3;

// ---------------------------------------------------------
// Prints the current state of the board to the console.
// Uses a nested loop to walk through the 2D array.
// ---------------------------------------------------------
void printBoard(char board[SIZE][SIZE])
{
    cout << "\n";
    for (int row = 0; row < SIZE; row++)
    {
        cout << "  ";
        for (int col = 0; col < SIZE; col++)
        {
            cout << " " << board[row][col] << " ";
            if (col < SIZE - 1) cout << "|";
        }
        cout << "\n";
        if (row < SIZE - 1) cout << "  -----------\n";
    }
    cout << "\n";
}

// ---------------------------------------------------------
// Resets the board to blank cells ('1'..'9' as placeholders
// so players can see valid move numbers at the very start).
// ---------------------------------------------------------
void initBoard(char board[SIZE][SIZE])
{
    int num = 1;
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            board[row][col] = '0' + num++;
}

// ---------------------------------------------------------
// Converts a 1-9 cell number to row/col indices.
// ---------------------------------------------------------
void numberToRowCol(int number, int &row, int &col)
{
    number--;               // shift to 0-based
    row = number / SIZE;
    col = number % SIZE;
}

// ---------------------------------------------------------
// Checks whether a move (1-9) is valid: within range and
// pointing to a cell that hasn't been played yet.
// ---------------------------------------------------------
bool isValidMove(char board[SIZE][SIZE], int number)
{
    if (number < 1 || number > SIZE * SIZE) return false;

    int row, col;
    numberToRowCol(number, row, col);

    // A cell still holds a digit ('1'-'9') if it's unplayed
    return (board[row][col] >= '1' && board[row][col] <= '9');
}

// ---------------------------------------------------------
// Places the current player's symbol on the board.
// ---------------------------------------------------------
void makeMove(char board[SIZE][SIZE], int number, char symbol)
{
    int row, col;
    numberToRowCol(number, row, col);
    board[row][col] = symbol;
}

// ---------------------------------------------------------
// Checks all rows, columns and both diagonals for a winner.
// Returns true if 'symbol' has won.
// ---------------------------------------------------------
bool checkWin(char board[SIZE][SIZE], char symbol)
{
    // Rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != symbol) rowWin = false;
            if (board[j][i] != symbol) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // Diagonals
    bool diag1 = true, diag2 = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][i] != symbol) diag1 = false;
        if (board[i][SIZE - 1 - i] != symbol) diag2 = false;
    }

    return diag1 || diag2;
}

// ---------------------------------------------------------
// Checks whether the board is completely filled (no blanks
// left). Used to detect a draw when nobody has won.
// ---------------------------------------------------------
bool isBoardFull(char board[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            if (board[row][col] >= '1' && board[row][col] <= '9')
                return false;
    return true;
}

// ---------------------------------------------------------
// Reads a validated integer from the user (re-prompts on
// bad/non-numeric input).
// ---------------------------------------------------------
int readMoveInput(char board[SIZE][SIZE])
{
    int number;
    while (true)
    {
        cout << "Enter your move (1-9): ";
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (!isValidMove(board, number))
        {
            cout << "That move is not available. Try again.\n";
            continue;
        }

        return number;
    }
}

// ---------------------------------------------------------
// Plays a single round of Tic Tac Toe. Returns once the
// game has a winner or ends in a draw.
// ---------------------------------------------------------
void playGame()
{
    char board[SIZE][SIZE];
    initBoard(board);

    char players[2] = { 'X', 'O' };
    int currentPlayer = 0;
    int movesPlayed = 0;
    const int maxMoves = SIZE * SIZE;

    cout << "\n===== TIC TAC TOE =====\n";
    cout << "Player 1: X   |   Player 2: O\n";
    cout << "Cells are numbered 1-9 as shown below:\n";
    printBoard(board);

    while (movesPlayed < maxMoves)
    {
        char symbol = players[currentPlayer];
        cout << "Player " << (currentPlayer + 1) << " (" << symbol << ")'s turn.\n";

        int move = readMoveInput(board);
        makeMove(board, move, symbol);
        movesPlayed++;

        printBoard(board);

        if (checkWin(board, symbol))
        {
            cout << "*** Player " << (currentPlayer + 1)
                 << " (" << symbol << ") wins! ***\n";
            return;
        }

        if (isBoardFull(board))
        {
            cout << "It's a draw!\n";
            return;
        }

        currentPlayer = 1 - currentPlayer; // switch turns
    }
}

// ---------------------------------------------------------
// Asks the player whether they want another round.
// ---------------------------------------------------------
bool askReplay()
{
    char choice;
    while (true)
    {
        cout << "Play again? (y/n): ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        choice = tolower(choice);
        if (choice == 'y') return true;
        if (choice == 'n') return false;

        cout << "Please enter 'y' or 'n'.\n";
    }
}

int main()
{
    bool playAgain = true;

    while (playAgain)
    {
        playGame();
        playAgain = askReplay();
    }

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}
