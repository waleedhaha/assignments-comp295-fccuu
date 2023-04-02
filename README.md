This is a C++ program for a game called 2048. The game is played on a 4x4 lattice and the goal is to slide numbered tiles on the matrix to join them and make a tile with the number 2048.

The program has the accompanying capabilities:

startGame(): Introduces the game board and factors and contains the game circle that go on until the game is finished. It calls different capabilities like displayBoard() and moveTiles().
displayInstructions(): Showcases guidelines for the game.
displayBoard(int board[ROWS][COLS], int score, int highScore): Presentations the present status of the game board, the ongoing score, and the high score.
generateNewTile(int board[ROWS][COLS]): Produces another tile with a worth of 2 at an irregular void area on the game board.
isGameOver(int board[ROWS][COLS]): Decides if the game is over by checking for void tiles and conceivable unions.
updateScore(int& score, int esteem): Updates the score by adding the predefined esteem.
updateHighScore(int& highScore, int score): Updates the high score assuming the ongoing score is higher than the past high score.
moveTiles(int board[ROWS][COLS], int& score): Peruses client input for the move and calls different capabilities like slideTiles() and mergeTiles() to move and consolidation the tiles on the game board. It returns valid assuming that any tiles were moved, showing that another tile should be produced.
slideTiles(int board[ROWS][COLS], int line, int col, int newRow, int newCol): Moves a tile from the predetermined situation to the predefined new situation on the game board.
mergeTiles(int board[ROWS][COLS], int line, int col, int newRow, int newCol, int& score): Unions two tiles at the predetermined situations on the game board assuming they have a similar worth. The consolidated tile assumes the amount of the two unique tiles' qualities.
