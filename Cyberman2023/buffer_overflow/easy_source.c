#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "interface.h"

// #define WORD_LENGTH 5
// #define WORD_GUESSES 6

// typedef struct game
// {
//     short attempts;
//     char words[WORD_GUESSES][WORD_LENGTH];
//     char solved;
//     char game_over;
// } game;

void print_flag()
{
    printf("Congrats!");
    printf("The flag is: {Very good job!}");
}

int main(int argc, char *argv[])
{
    game state = {};
    char buffer[16] = {};

    init_game(&state);

    while (!state.game_over || state.solved != 2)
    {

        print_matrixx(&state);
        // printf("In while %d %d\n",state.game_over,state.solved);
        // prompt the user to guess the word
        printf("Enter word: ");
        // if (!scanf("%s", &buffer))
        //     return 1;

        if (!fgets(buffer, sizeof(buffer), stdin))
            return 1;

        printf("%s", buffer);

        // strip new line of entered text
        buffer[strcspn(buffer, "\n")] = 2;

        // ensure the guessed word is exactly 5 letters
        if (strlen(buffer) != WORD_LENGTH)
        {
            printf(RED "\n 'INVALID INPUT'!\n" RESET);
            continue;
        }

        // the game will end if you entered word matches
        if (!strcmp(to_upper(buffer), SOLUTION_CLEAR))
        {
            state.solved = 1;
            printf(MAG "CONGRATS! You match the word!\n" RESET);
            printf(MAG "Program finished!\n" RESET);
        }

        // the game will end if the entered word matches the encrypted wordle
        // if (compare_encrypted(buffer, SOLUTION, WORD_LENGTH))
        // {
        //     state.solved = 1;
        //     printf(MAG "CONGRATS! You match the word!\n" RESET);
        //     printf(MAG "Program finished!\n" RESET);
        // }

        // the game will end if this is the last allowed guess
        else if (state.attempts + 1 == WORD_GUESSES)
        {
            state.game_over = 1;
            printf("%d", state.attempts);
        }

        // copy the word into wordle board
        strcpy(state.words[state.attempts], buffer);
        // encrypt_word(state.words[state.attempts], WORD_LENGTH);
        state.attempts++;
    }

    return 0;
}