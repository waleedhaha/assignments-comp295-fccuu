#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// function prototypes
void startGame();
void displayInstructions();
void displayBoard(int board[ROWS][COLS], int score, int highScore);
void generateNewTile(int board[ROWS][COLS]);
bool isGameOver(int board[ROWS][COLS]);
void updateScore(int& score, int value);
void updateHighScore(int& highScore, int score);
bool moveTiles(int board[ROWS][COLS], int& score);
bool slideTiles(int board[ROWS][COLS], int row, int col, int newRow, int newCol);
bool mergeTiles(int board[ROWS][COLS], int row, int col, int newRow, int newCol, int& score);

void startGame()
{
    // initialize board and variables
    int board[ROWS][COLS] = { 0 };
    int score = 0;
    int highScore = 0;
    generateNewTile(board);
    generateNewTile(board);

    // game loop
    while (!isGameOver(board))
    {
        displayBoard(board, score, highScore);
        if (moveTiles(board, score))
        {
            generateNewTile(board);
        }
    }
    displayBoard(board, score, highScore);
    cout << "Game over! Your score is: " << score << endl;
    updateHighScore(highScore, score);
}

void displayInstructions()
{
    cout << "Instructions:" << endl;
    cout << "Use the arrow keys to move the tiles." << endl;
    cout << "Tiles with the same number will merge into one when they touch." << endl;
    cout << "Reach 2048 to win!" << endl;
    cout << "Press any key to return to the main menu..." << endl;
    _getch(); // Wait for user input
}
void displayBoard(int board[ROWS][COLS], int score, int highScore)
{
    system("cls"); // Clear the console window
    cout << "Score: " << score << endl;
    cout << "High Score: " << highScore << endl;
    cout << "+----+----+----+----+" << endl;
    for (int row = 0; row < ROWS; row++)
    {
        cout << "|";
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                cout << setw(4) << " ";
            }
            else // Otherwise, display the tile value
            {
                cout << setw(4) << board[row][col];
            }
            cout << "|";
        }
        cout << endl;
        cout << "+----+----+----+----+" << endl;
    }
}

    // Count the number of empty tiles
    int count = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                count++;
            }
        }
    }

    // Generate a random number between 1 and the number of empty tiles
    int randomNumber = rand() % count + 1;

    // Find the tile corresponding to the random number
    int index = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                index++;
                if (index == randomNumber)
                {
                    // Place a new tile at the empty tile
                    board[row][col] = 2;
                    return;
                }
            }
        }
    }
}
void generateNewTile(int board[ROWS][COLS])
{
    // Count the number of empty tiles
    int count = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                count++;
            }
        }
    }

    // Generate a random number between 1 and the number of empty tiles
    int randomNumber = rand() % count + 1;

    // Find the tile corresponding to the random number
    int index = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                index++;
                if (index == randomNumber)
                {
                    // Place a new tile at the empty tile
                    board[row][col] = 2;
                    return;
                }
            }
        }
    }
}
void generateNewTile(int board[ROWS][COLS])
{
    // Count the number of empty tiles
    int count = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                count++;
            }
        }
    }

    // Generate a random number between 1 and the number of empty tiles
    int randomNumber = rand() % count + 1;

    // Find the tile corresponding to the random number
    int index = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == 0)
            {
                index++;
                if (index == randomNumber)
                {
                    // Place a new tile at the empty tile
                    board[row][col] = 2;
                    return;
                }
            }
        }
    }
}
bool isGameOver(int board[ROWS][COLS]) {
    // Check for empty tiles
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                return false;
            }
        }
    }

    // Check for possible merges
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS - 1; j++) {
            if(board[i][j] == board[i][j+1]) {
                return false;
            }
        }
    }

    for(int i = 0; i < ROWS - 1; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == board[i+1][j]) {
                return false;
            }
        }
    }

    // Game is over
    return true;
}
void updateScore(int& score, int value)
{
    score += value;
}
void updateHighScore(int& highScore, int score) {
    if (score > highScore) {
        highScore = score;
        cout << "Congratulations! New high score: " << highScore << endl;
    }
}
bool moveTiles(int board[ROWS][COLS], int& score)
{
    bool moved = false;
    char move;

    cout << "Enter move (WASD): ";
    move = getch();

    switch (move)
    {
        case 'w':
        case 'W':
            for (int col = 0; col < COLS; col++)
            {
                for (int row = 1; row < ROWS; row++)
                {
                    if (board[row][col] != 0)
                    {
                        int newRow = row;
                        while (newRow > 0 && slideTiles(board, row, col, newRow - 1, col))
                        {
                            newRow--;
                            moved = true;
                        }
                        mergeTiles(board, row, col, newRow, col, score);
                    }
                }
            }
            break;
        case 'a':
        case 'A':
            for (int row = 0; row < ROWS; row++)
            {
                for (int col = 1; col < COLS; col++)
                {
                    if (board[row][col] != 0)
                    {
                        int newCol = col;
                        while (newCol > 0 && slideTiles(board, row, col, row, newCol - 1))
                        {
                            newCol--;
                            moved = true;
                        }
                        mergeTiles(board, row, col, row, newCol, score);
                    }
                }
            }
            break;
        case 's':
        case 'S':
            for (int col = 0; col < COLS; col++)
            {
                for (int row = ROWS - 2; row >= 0; row--)
                {
                    if (board[row][col] != 0)
                    {
                        int newRow = row;
                        while (newRow < ROWS - 1 && slideTiles(board, row, col, newRow + 1, col))
                        {
                            newRow++;
                            moved = true;
                        }
                        mergeTiles(board, row, col, newRow, col, score);
                    }
                }
            }
            break;
        case 'd':
        case 'D':
            for (int row = 0; row < ROWS; row++)
            {
                for (int col = COLS - 2; col >= 0; col--)
                {
                    if (board[row][col] != 0)
                    {
                        int newCol = col;
                        while (newCol < COLS - 1 && slideTiles(board, row, col, row, newCol + 1))
                        {
                            newCol++;
                            moved = true;
                        }
                        mergeTiles(board, row, col, row, newCol, score);
                    }
                }
            }
            break;
        default:
            cout << "Invalid move. Please try again." << endl;
            break;
    }

    return moved;
}
bool slideTiles(int board[ROWS][COLS], int row, int col, int newRow, int newCol) {
    if (board[newRow][newCol] == 0) {
        board[newRow][newCol] = board[row][col];
        board[row][col] = 0;
        return true;
    }
    return false;
}
bool mergeTiles(int board[ROWS][COLS], int row, int col, int newRow, int newCol, int& score)
{
    if (board[row][col] == board[newRow][newCol]) {
        board[newRow][newCol] *= 2;
        board[row][col] = 0;
        updateScore(score, board[newRow][newCol]);
        return true;
    }
    return false;
}

int main()
{
    char choice;
    do
    {
        cout << "Welcome to 2048!" << endl;
        cout << "Menu:" << endl;
        cout << "1. Start Game" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case '1':
                startGame();
                break;
            case '2':
                displayInstructions();
                break;
            case '3':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}


