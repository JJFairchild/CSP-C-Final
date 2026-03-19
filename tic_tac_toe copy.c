// JF & SA, Tic Tac Toe

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int selectSquare() { // Asks the user what square they want to claim
    int choice;
    printf("\nWhat square do you want to select?\n1 2 3 \n4 5 6 \n7 8 9 \n");
    scanf("%d", &choice);

    return choice;
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
            return 1; // Return 1 if the player won
        }
        if (O >= 3) {
            return 2; // Return 2 if the bot won
        }
    }

    int count = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] != ' ') {
            count++;
        }
    }
    if (count == 9) {
        return 3; // Return 3 if it's a tie
    }

    return 0;
}

void printBoard(char* board) { // Displays the board
    printf("\n %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

int playAgain(char* message) { // Determines if the game should run again
    char play;
    while (true) {
        printf("%s", message);
        scanf(" %c", &play);
        if (play == 'Y') {
            return 1;
        } else if (play == 'N') {
            return 0;
        } else {
            printf("That's not a valid input. Try again.\n");
        }
    }
}

void showWin(char* board, char winner) {
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

    char new_board[9] = 
    {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    int winners[8];
    int count = 0;
    for (int i=0; i<8; i++) {
        int tiles = 0;
        for (int j=0; j<3; j++) {
            if (board[win_combos[i][j]] == winner) {
                tiles++;
            }
        }
        if (tiles >= 3) {
            winners[count] = i;
            count++;
        }
    }
    for (int i=0; i<count; i++) {
        for (int j=0; j<3; j++) {
            new_board[win_combos[winners[i]][j]] = winner;
        }
    }
    printBoard(new_board);
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
    while (true) {
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
        int win = checkWin(board);
        if (win == 1) {
            showWin(board, 'X');
            int play_again = playAgain("\nCongrats, you win! Play again? (Y/N): ");
            if (play_again == 1) {
                for (int i=0; i<9; i++) { // Erase the board for future playthroughs
                    board[i] = ' ';
                }
                continue;
            } else {
                break;
            }
        } else if (win == 3) {
            printBoard(board);
            int play_again = playAgain("\nLooks like it's a tie! Play again? (Y/N): ");
            if (play_again == 1) {
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
        win = checkWin(board);
        if (win == 2) {
            showWin(board, 'O');
            int play_again = playAgain("\nYou lost, womp womp! Play again? (Y/N): ");
            if (play_again == 1) {
                for (int i=0; i<9; i++) {
                    board[i] = ' ';
                }
                continue;
            } else {
                break;
            }
        } else if (win == 3) {
            printBoard(board);
            int play_again = playAgain("\nLooks like it's a tie! Play again? (Y/N): ");
            if (play_again == 1) {
                for (int i=0; i<9; i++) { // Erase the board for future playthroughs
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