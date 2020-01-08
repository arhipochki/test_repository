void DrawGameBoard(char gameBoard[5][5]); // Print out gameboard
int PlaceItem(char gameBoard[5][5], int pos, const char* player); // Place player's or cpu's item into the board and checking if it's possible
int CheckGameBoard(char gameBoard[5][5], const char* player); // Checking, if anyone won
int FullGameBoard(char gameBoard[5][5]); // Checking, if board is full