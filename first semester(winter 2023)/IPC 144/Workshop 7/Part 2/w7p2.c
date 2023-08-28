/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Gyeongrok oh
Student ID#: 119140226
Email      : goh3@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define max_path_length 70
#define min_path_length 10

#include <stdio.h>

struct playerInfo {
    int numberOfLive;
    char characterSymbol, movesHistory[max_path_length + 1];
};

struct gameInfo {
    int pathLength;
    int numberOfMove;
    int bombs[max_path_length], treasure[max_path_length], playerHistory[max_path_length];
};

int main(void)
{
    printf("================================\n"
           "         Treasure Hunt!"
         "\n================================\n\n");
        
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    
    struct playerInfo player;
    
    printf("Enter a single character to represent the player: ");
    scanf("%c&*c", &player.characterSymbol);
    
    do {
        printf("Set the number of lives: ");
        scanf("%d&*c", &player.numberOfLive);
    
        if (player.numberOfLive < 1 || player.numberOfLive > 10) {
    
            printf("     Must be between 1 and 10!\n");
        }
        else {
    
        }
    } while (player.numberOfLive < 1 || player.numberOfLive > 10);
    
    printf("Player configuration set-up is complete\n\n");
    
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    struct gameInfo game;
    
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
    
        if (game.pathLength < min_path_length || game.pathLength > max_path_length || game.pathLength % 5 != 0) {
    
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        else {
    
        }
    } while (game.pathLength < min_path_length || game.pathLength > max_path_length || game.pathLength % 5 != 0);
    
    int min_move = player.numberOfLive, max_move = game.pathLength * 0.75, i, treasure = 0, move = 0, flag;
    
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.numberOfMove);
    
        if (game.numberOfMove < min_move || game.numberOfMove > max_move) {
    
            printf("    Value must be between %d and %d\n",min_move, max_move);
        }
        else {
    
        }
    } while (game.numberOfMove < min_move || game.numberOfMove > max_move);
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n"
        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
       
    for (i = 0; i < game.pathLength; i += 5) {
    
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4], &game.bombs[i + 5]);
    
    }
    printf("BOMB placement set\n");
    
    printf("\nTREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n"
        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
      
    for (i = 0; i < game.pathLength; i += 5) {
    
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4], &game.treasure[i + 5]);
    }
    
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.characterSymbol);
    printf("   Lives      : %d\n", player.numberOfLive);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");

    for (i = 1; i <= game.pathLength; i++) {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    
    for (i = 1; i < game.pathLength + 1; i++) {
        printf("%d", game.treasure[i]);
    }
    
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    for (i = 1; i <= game.pathLength + 1; i++) {
       game.playerHistory[i] = 0;
    }

    do {
        printf("  ");

        flag = 1;

        for (i = 1; i <= game.pathLength; i++) {
            if (move == 0) {
                printf("-");
                player.movesHistory[i] = '-';
            }
            else {
                printf("%c", player.movesHistory[i]);
            }
        }

        printf("\n  ");

        for (i = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0) {
                printf("%d", i / 10);
            }
            else {
                printf("|");
            }
        }

        printf("\n  ");

        for (i = 1; i <= game.pathLength; i++) {
            if (i / 10 > 0) {
                printf("%d", i % 10);
            }
            else {
                printf("%d", i);
            }
        }

        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numberOfLive, treasure, game.numberOfMove);
        printf("+---------------------------------------------------+\n");

        if (player.numberOfLive == 0 || game.numberOfMove == 0) {
            flag += 1;
        }
        else {

        }

        while (flag == 1) {
            do {
                printf("Next Move [1-%d]: ", game.pathLength);
                scanf("%d", &move);

                if (move < 1 || move > game.pathLength) {
                    printf("  Out of Range!!!\n");
                }
                else {
                    printf("\n");
                }
            } while (move < 1 || move > game.pathLength);

            if (game.playerHistory[move] == 1) {
                printf("===============> Dope! You've been here before!\n\n");
            }
            else if (game.bombs[move] == 1 && game.treasure[move] == 1) {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n"
                    "===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                game.playerHistory[move] = 1;
                game.numberOfMove -= 1;
                player.numberOfLive -= 1;
                treasure += 1;
                player.movesHistory[move] = '&';
            }
            else if (game.bombs[move] == 1 && game.treasure[move] == 0) {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                game.playerHistory[move] = 1;
                player.numberOfLive -= 1;
                game.numberOfMove -= 1;
                player.movesHistory[move] = '!';
            }
            else if (game.bombs[move] == 0 && game.treasure[move] == 1) {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                game.playerHistory[move] = 1;
                treasure += 1;
                game.numberOfMove -= 1;
                player.movesHistory[move] = '$';
            }
            else {
                printf("===============> [.] ...Nothing found here... [.]\n\n");
                game.playerHistory[move] = 1;
                game.numberOfMove -= 1;
                player.movesHistory[move] = '.';
            }

            if (player.numberOfLive == 0 || game.numberOfMove == 0) {
                printf("No more LIVES remaining!\n\n");
            }
            else {

            }

            for (i = 1; i < move + 2; i++) {
                printf(" ");
            }

            printf("%c\n", player.characterSymbol);

            flag -= 1;
        }
    } while (!(player.numberOfLive == 0 || game.numberOfMove == 0) || flag == 0);

    printf("\n##################\n"
           "#   Game over!   #\n"
           "##################\n");

    printf("\nYou should play again and try to beat your score!\n");

    return 0;
}

