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




