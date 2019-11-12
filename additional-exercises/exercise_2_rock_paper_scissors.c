#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This function can be used to flush all characters that
 * have not been read by scanf from the stdin-stream.
 *
 * There is a method called fflush() but it does not work
 * properly on all operation systems
 */
void my_flush() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * This function returns a random integer in the range of [min, max] OR [max, min]
 *
 * @param min - Lower boundary of range
 * @param max - Upper boundary of range
 *
 * @return Random integer between min and max
 */
int random_integer(int min, int max){
    if (max == min) {
        return min;
    } else if (max < min) {
        int new_min = max;
        max = min;
        min = new_min;
    }
    return (random() % (max - min + 1)) + min;
}

/**
 * This function evaluates the winning side in a Rock-Paper-Scissors game
 *
 * @param players_choice - 0 (Rock), 1 (Paper), 2 (Scissors), 3 (Invalid)
 * @param computers_choice - 0 (Rock), 1 (Paper), 2 (Scissors)
 *
 * @return 1 (Computer won), -1 (Player won), 0 (Draw)
 */
char evaluate_win(char players_choice, char computers_choice){

    if (players_choice == 3) {
        return 1;
    }

    if (players_choice == computers_choice){
        return 0;
    }

    // Only evaluation two cases for computer choice because the
    // case player_choice == computer_choice has already been evaluated
    switch (players_choice){
        case 0:
            switch (computers_choice){
                case 1:
                    // Player: Rock, Computer: Paper
                    return 1;
                default: // case 2:
                    // Player: Rock, Computer: Scissors
                    return -1;
            }
        case 1:
            switch (computers_choice){
                case 0:
                    // Player: Paper, Computer: Rock
                    return -1;
                default: // case 2:
                    // Player: Paper, Computer: Scissors
                    return 1;
            }
        default: // case 2:
            switch (computers_choice){
                case 0:
                    // Player: Scissors, Computer: Rock
                    return 1;
                default: // case 1:
                    // Player: Scissors, Computer: Paper
                    return -1;
            }
    }
}

/**
 * This progam is a Rock-Paper-Scissors game between a human and the computer (random)
 *
 * @return Main-Exit-Code
 */
int main() {
    srand(time(NULL));

    int player_score = 0;
    int computer_score = 0;

    for (int round_number=1; round_number <= 100; round_number++) {

        int computer_choice = random_integer(0, 2);
        char player_input[2];
        int player_choice;

        printf("\nDo you choose rock, paper or scissors? (r/p/s) \n");
        scanf("%1s", player_input);
        my_flush();

        switch (player_input[0]) {
            case 'r':
                printf("You: Rock\n");
                player_choice = 0;
                break;
            case 'p':
                printf("You: Paper\n");
                player_choice = 1;
                break;
            case 's':
                printf("You: Scissors\n");
                player_choice = 2; break;
            default:
                printf("You: Invalid\n");
                player_choice = 3;
                break;
        }

        if (computer_choice == 0) {
            printf("Computer: Rock\n");
        } else if (computer_choice == 1) {
            printf("Computer: Paper\n");
        } else {
            printf("Computer: Scissors\n");
        }

        // Determine the winner: 1 -> Computer won, -1 -> You won, 0 -> Draw
        char winner = evaluate_win(player_choice, computer_choice);

        if (winner == 1) {
            printf("The computer won!\n");
            computer_score++;
        } else if (winner == -1) {
            printf("You won!\n");
            player_score++;
        } else {
            printf("Draw!\n");
        }

        // Give the player the opportunity to exit the game every 10 rounds
        if (round_number % 10 == 0) {
            printf("\n\nScoreboard:\n");
            printf("Computer: %d\n", computer_score);
            printf("You: %d\n\n", player_score);

            char c[2];
            printf("Do you want to keep playing? (y/n)\n");
            scanf("%1s", c);
            my_flush();

            if (c[0] != 'y') {
                break;
            }
        }
    }

    return 0;
}
