// JF & SA, Tic Tac Toe

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int selectSquare() {
    int choice;

    printf("What square do you want to select?\n1 2 3 \n4 5 6 \n7 8 9 \n");
    scanf("%d", &choice);

    return choice; // asks the user what square they want to claim
}

int checkWin(char* board) {
    // All possible winning combinations
    int win_combos[8][3] = 
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},

        {0, 4, 8},
        {2, 4, 6},
        
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, 
    };

    // Counts Xs and Os to determine a winner
    for (int i=0; i<8; i++) {
        int X = 0;
        int O = 0;
        for (int j=0; j<3; j++) {
            if (board[win_combos[i][j]] == 'X') {
                X++;
            }
            if (board[win_combos[i][j]] == 'O') {
               O++;
            }
        }
        if (X >= 3) {
            return 1; // return 1 if the player won
        }
        if (O >= 3) {
            return 2; // return 2 if the bot won
        }
    }
    return 0;  // return 0 if no one won    
}

void printBoard(char* board) { // Displays the board
    printf(" %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

int main() {
    // Initialize variables
    srand(time(NULL));
    char board[9] = 
    {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '    
    };

    // Main loop
    bool running = true;
    while (running) {
        printBoard(board);

        // Player square choice
        int choice = selectSquare()-1;
        if (board[choice] == ' ') {
            board[choice] = 'X';
        } else {
            printf("That square is occupied! Try again.\n");
            continue;
        }

        // Win check #1
        if (checkWin(board) == 1) {
            char play;
            printBoard(board);
            printf("Congrats, you win! Play again? (Y/N): ");
            scanf(" %c", &play);
            if (play == 'Y') {
                for (int i=0; i<9; i++) { // Erase the board for future playthroughs
                    board[i] = ' ';
                }
                continue;
            } else {
                break;
            }
        }

        // Bot square choice (creates a list of available square indexes and chooses one randomly)
        int count = 0;
        int available_squares[9];
        for (int i = 0; i <= 9; i++) {
            if (board[i] == ' ') {
                available_squares[count] = i;
                count++;
            }
        }
        
        int index = rand() % count; 
        board[available_squares[index]] = 'O';

        // Win check #2
        if (checkWin(board) == 2) {
            char play;
            printBoard(board);
            printf("You lost, womp womp! Play again? (Y/N): ");
            scanf("%s", &play);
            if (play == 'Y') {
                for (int i=0; i<9; i++) {
                    board[i] = ' ';
                }
                continue;
            } else {
                break;
            }
        }
    }

    return 0;
}