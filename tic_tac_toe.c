// JF & SA, Tic Tac Toe

#include <stdio.h>
#include <stdbool.h>

int select_square() {
    int choice;

    printf("What square do you want to select?\n 1 | 2 | 3 \n-----------\n 4 | 5 | 6 \n-----------\n 7 | 8 | 9 \n");
    scanf("%d", &choice);

    return choice;
}

int check_win(char* board) {
    
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
    
    //return 0 if no one won
    //return 1 if the player won
    //return 2 if the bot won
} 

int main() {

    char board[9] = 
    {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '    
    };

    bool running = true;
    while (running) {
        int choice = select_square()-1;
        if (board[choice] != ' ') {
            board[choice] = 'X';
        } else {
            printf("That square is occupied! Try again.\n");
            continue;
        }

        if (check_win(board) == 1) {
            char play;
            printf("Congrats, you win! Play again? (Y/N): ");
            scanf("%s", &play);
            if (play == 'Y') {
                char board[9] = 
                {
                    ' ', ' ', ' ',
                    ' ', ' ', ' ',
                    ' ', ' ', ' '
                };
                continue;
            } else {
                break;
            }
        }

        int count = 0;
        char available_squares[8];
        for (int i = 0; i <= 8; i++) {
            if (board[i] == ' ') {
                available_squares[count] = board[i];
                count++;
            }
        }
    }

    return 0;
}