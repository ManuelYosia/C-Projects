#include <stdio.h>
#include <string.h>
#include <conio.h>  
#include <stdlib.h>

const int NOUGHT = 1;
const int CROSSES = 2;
const char BORDER = ':';
const char EMPTY = '-';

const int convertTo25[9] = {
    6,7,8,
    11,12,13,
    16,17,18
};


const int winCondition[8][3] = {
    {6,7,8},
    {11,12,13},
    {16,17,18},
    {6,11,16},
    {7,12,17},
    {8,13,18},
    {6,12,18},
    {8,12,16}
};

char status = '1';

char turn;

void validate(char* board);
/*
    Board

    3 3 3 3 3
    3 0 0 0 3
    3 0 0 0 3
    3 0 0 0 3
    3 3 3 3 3

    *board size 25
    *Every array member multiples of 5 make new line
    *3 for the border
    *0 for arena 
*/

void initializeBoard(char* board) {
    for (int i = 0; i < 25; i++)
    {
        board[i] = BORDER;
    }
    for (int i = 0; i < 9; i++)
    {
        board[convertTo25[i]] = EMPTY;
    }
    
}

void printBoard(char* board)
{

    for (int i = 0; i < 25; i++)
    {
        if (i != 0 && i%5==0)
        {
            printf("\n\n");
        }
        printf("%4c", board[i]);
    }

    printf("\n");
}

//second, we need to know the user move with user input
/*
    user input conditions:
    1. user need to input position of the cell, if user input not valid print not valid
        valid conditions:
            *user input must be equal with convertTo25 array.
            *if user input target border position it will repeat the input
    2. user and computer only have 1 chance move
*/
void userMove(char* board)
{
    if(status == '0') return;
    turn = 'x';

    int moveChance, move;
    char userInput[4];

    moveChance = 0;

    while (moveChance == 0)
    {
        puts("enter position between 1 and 9");
        fgets(userInput, 3, stdin);
        fflush(stdin);

        //if string not valid
        if(strlen(userInput) != 2)
        {
            puts("String not valid!");
            continue;
        }

        //if invalid input
        if (sscanf(userInput,"%d",&move) != 1)
        {
            puts("Invalid input");
            continue;
        }
        
        //if move range invalid
        if(move < 1 || move > 9)
        {
            puts("Invalid range");
            continue;
        }

        move--;
        if(board[convertTo25[move]] != EMPTY)
        {
            puts("Square not available");
            continue;
        }

        moveChance = 1;
    }
    board[convertTo25[move]] = 'X';
    validate(board);
}

void computerMove(char* board)
{  
    if(status == '0') return;
    turn = 'o';

    int randMove, freeIndex, availableMove[9];

    freeIndex = 0;

    for (int i = 0; i < 9; i++)
    {
        if (board[convertTo25[i]] == EMPTY)
        {
            availableMove[freeIndex] = i;
            freeIndex++;
        }
    }
    randMove = (rand() % freeIndex);
    
    board[convertTo25[availableMove[randMove]]] = 'O';
    validate(board);
}

void validate(char* board) {
    char a, b, c;

    for (int i = 0; i < 8; i++)
    {
        a = board[winCondition[i][0]];
        b = board[winCondition[i][1]];
        c = board[winCondition[i][2]];

        if (a == EMPTY || b == EMPTY || c == EMPTY)
        {
            continue;
        }
        
        if (a == b && b == c)
        {   
            status = '0';
        }
    }
}

int main()
{
    char board[25];

    initializeBoard(board);
    
    while (status == '1')
    {
        printBoard(board);
        userMove(board);
        computerMove(board);
    }
    
    if(turn == 'x')
    {
        printBoard(board);
        puts("\tUser Win");
    }else if (turn == 'o')
    {
        printBoard(board);
        puts("\tComputer Win");
    }
    
    
    return 0;
}
