///*/////////////////////////////////////////////////////////////////////////
//                          Workshop - #7 (P1)
//Full Name  : Gyeongrok oh
//Student ID#: 119140226
//Email      : goh3@myseneca.ca
//Section    :NGG
//
//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////////*/
//
//#define _CRT_SECURE_NO_WARNINGS
//#define max_path_length 70
//#define min_path_length 10
//
//#include <stdio.h>
//
//struct playerInfo {
//    int numberOfLive;
//    char characterSymbol;
//
//};
//
//struct gameInfo {
//    int pathLength;
//    int numberOfMove;
//    int bombs[max_path_length], treasure[max_path_length];
//};
//
//int main(void)
//{
//    printf("================================\n"
//           "         Treasure Hunt!"
//           "\n================================\n\n");
//
//    printf("PLAYER Configuration\n");
//    printf("--------------------\n");
//    
//    struct playerInfo player;
//
//    printf("Enter a single character to represent the player: ");
//    scanf("%c&*c", &player.characterSymbol);
//
//    do {
//        printf("Set the number of lives: ");
//        scanf("%d&*c", &player.numberOfLive);
//
//        if (player.numberOfLive < 1 || player.numberOfLive > 10) {
//
//            printf("     Must be between 1 and 10!\n");
//        }
//        else {
//
//        }
//    } while (player.numberOfLive < 1 || player.numberOfLive > 10);
//
//    printf("Player configuration set-up is complete\n\n");
//
//    printf("GAME Configuration\n");
//    printf("------------------\n");
//    
//    struct gameInfo game;
//
//    do {
//        printf("Set the path length (a multiple of 5 between 10-70): ");
//        scanf("%d", &game.pathLength);
//
//        if (game.pathLength < min_path_length || game.pathLength > max_path_length || game.pathLength % 5 != 0) {
//
//            printf("     Must be a multiple of 5 and between %d-%d!!!\n", min_path_length, max_path_length);
//        }
//        else {
//
//        }
//    } while (game.pathLength < min_path_length || game.pathLength > max_path_length || game.pathLength % 5 != 0);
//
//    int min_move = player.numberOfLive, max_move = game.pathLength * 0.75;
//
//    do {
//        printf("Set the limit for number of moves allowed: ");
//        scanf("%d", &game.numberOfMove);
//
//        if (game.numberOfMove < min_move || game.numberOfMove > max_move) {
//
//            printf("    Value must be between %d and %d\n", min_move, max_move);
//        }
//        else {
//
//        }
//    } while (game.numberOfMove < min_move || game.numberOfMove > max_move);
//
//    printf("\nBOMB Placement\n");
//    printf("--------------\n");
//    printf("Enter the bomb positions in sets of 5 where a value\n"
//        "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
//        "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
//
//    int i;
//
//
//    for (i = 0; i < game.pathLength; i += 5) {
//
//        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
//        scanf("%d %d %d %d %d", &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4], &game.bombs[i + 5]);
//
//    }
//    printf("BOMB placement set\n");
//
//    printf("\nTREASURE Placement\n");
//    printf("------------------\n");
//    printf("Enter the treasure placements in sets of 5 where a value\n"
//        "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
//        "(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
//
//
//
//    for (i = 0; i < game.pathLength; i += 5) {
//
//
//        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
//        scanf("%d %d %d %d %d", &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4], &game.treasure[i + 5]);
//
//    }
//
//    printf("TREASURE placement set\n\n");
//    printf("GAME configuration set-up is complete...\n\n");
//    printf("------------------------------------\n");
//    printf("TREASURE HUNT Configuration Settings\n");
//    printf("------------------------------------\n");
//    printf("Player:\n");
//    printf("   Symbol     : %c\n", player.characterSymbol);
//    printf("   Lives      : %d\n", player.numberOfLive);
//    printf("   Treasure   : [ready for gameplay]\n");
//    printf("   History    : [ready for gameplay]\n\n");
//    printf("Game:\n");
//    printf("   Path Length: 35\n");
//    printf("   Bombs      : ");
//    for (i = 1; i < game.pathLength + 1; i++) {
//        printf("%d", game.bombs[i]);
//    }
//    printf("\n");
//    printf("   Treasure   : ");
//
//    for (i = 1; i < game.pathLength + 1; i++) {
//        printf("%d", game.treasure[i]);
//    }
//
//    printf("\n\n");
//    printf("====================================\n");
//    printf("~ Get ready to play TREASURE HUNT! ~\n");
//    printf("====================================\n");
//
//
//
//    return 0;
//}
