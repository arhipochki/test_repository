#include <stdio.h>
#include "func.h"
#include <string.h>
#include <time.h>

char gameBoard[5][5] = {
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '},
    {'-', '+', '-', '+', '-'},
    {' ', '|', ' ', '|', ' '}
};

int main(int argc, char* argv) {

    srand(time(NULL));

    int lose = 1;
    int session = 1;
    int choice;
    int cpuChoice;
    const char* player = "player";
    const char* cpu = "cpu";

    printf("\t*** Welcome to 'Tic Tac Toe' game  ***\t\n");
    printf("\t*** If you want to exit: type '-1' ***\t\n");

    DrawGameBoard(gameBoard);

    while (session) {

        scanf_s("%d", &choice);
        if (choice == -1) {
            break;
        }
        
        while (PlaceItem(gameBoard, choice, player) != 1 && !FullGameBoard(gameBoard)) {
            scanf_s("%d", &choice);
            if (choice == -1) {
                break;
            }
        }

        if (CheckGameBoard(gameBoard, player)) {
            DrawGameBoard(gameBoard);
            lose = 0;
            break;
        }

        cpuChoice = 1 + rand() % 9;
        while (PlaceItem(gameBoard, cpuChoice, cpu) != 1 && !FullGameBoard(gameBoard)) {
            cpuChoice = 1 + rand() % 9;
        }

        if (CheckGameBoard(gameBoard, cpu)) {
            DrawGameBoard(gameBoard);
            break;
        }

        DrawGameBoard(gameBoard);
        
        if (FullGameBoard(gameBoard)) {
            lose = 2;
            break;
        }
    }

    if (lose == 1) {
        printf("You lose(\n");
    }
    else if (lose == 2) {
        printf("Draw\n");
    }
    else {
        printf("You won!\n");
    }

    return 0;
}