char symbol;

#define SYMBOL(player) (strcmp(player, "player")) ? (symbol = 'O') : (symbol = 'X')

void DrawGameBoard(char gameBoard[5][5]) { // length = sizeof(gameBoard)/sizeof(char)
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            putchar(gameBoard[row][col]);
        }
        putchar('\n');
    }
}

int PlaceItem(char gameBoard[5][5], int pos, const char* player) {
    char* warning;
    
    SYMBOL(player);

    if (symbol == 'X') {
        warning = "Impossible position.\n";
    }
    else {
        warning = "";
    }

    switch (pos) {
    case 1:
        if (gameBoard[0][0] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[0][0] = symbol;
        }
        return 1;
    case 2:
        if (gameBoard[0][2] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[0][2] = symbol;
        }
        return 1;
    case 3:
        if (gameBoard[0][4] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[0][4] = symbol;
        }
        return 1;
    case 4:
        if (gameBoard[2][0] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[2][0] = symbol;
        }
        return 1;
    case 5:
        if (gameBoard[2][2] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[2][2] = symbol;
        }
        return 1;
    case 6:
        if (gameBoard[2][4] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[2][4] = symbol;
        }
        return 1;
    case 7:
        if (gameBoard[4][0] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[4][0] = symbol;
        }
        return 1;
    case 8:
        if (gameBoard[4][2] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[4][2] = symbol;
        }
        return 1;
    case 9:
        if (gameBoard[4][4] != ' ') {
            printf("%s", warning);
            return 0;
        }
        else {
            gameBoard[4][4] = symbol;
        }
        return 1;
    default:
        printf("Incorrect pos, try again.\n");
        return 0;
    }
}

int CheckGameBoard(char gameBoard[5][5], const char* player) {
    
    SYMBOL(player);

    return  (gameBoard[0][0] + gameBoard[0][2] + gameBoard[0][4] == 3 * symbol) || 
            (gameBoard[2][0] + gameBoard[2][2] + gameBoard[2][4] == 3 * symbol) ||
            (gameBoard[4][0] + gameBoard[4][2] + gameBoard[4][4] == 3 * symbol) ||
            (gameBoard[0][0] + gameBoard[2][0] + gameBoard[4][0] == 3 * symbol) ||
            (gameBoard[0][2] + gameBoard[2][2] + gameBoard[4][2] == 3 * symbol) ||
            (gameBoard[0][4] + gameBoard[2][4] + gameBoard[4][4] == 3 * symbol) ||
            (gameBoard[0][0] + gameBoard[2][2] + gameBoard[4][4] == 3 * symbol) ||
            (gameBoard[0][4] + gameBoard[2][2] + gameBoard[4][0] == 3 * symbol);
}

int FullGameBoard(char gameBoard[5][5]) {
    return  (gameBoard[0][0] != ' ' && gameBoard[0][2] != ' ' && gameBoard[0][4] != ' ' && 
            gameBoard[2][0] != ' ' && gameBoard[2][2] != ' ' && gameBoard[2][4] != ' ' &&
            gameBoard[4][0] != ' ' && gameBoard[4][2] != ' ' && gameBoard[4][4] != ' ');
}