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
    FILE *f;
    char flag[50];
    f = fopen("flag", "r");
    if (f == NULL)
    {
        printf("File can't be opened. \n");
    }
    if (fscanf(f, "%s", flag))
        printf("Flag is: %s\n", flag);
    else
    {
        printf("Content can't be read \n");
    }
}

void encrypt_word(char *word, int length)
{
    for (int i = 0; i < length; i++)
        word[i] ^= ENCRYPTION_BYTE;
}

int compare_encrypted(char *user_word, char *secret_word, int length)
{
    char encrypted_char = 0;

    for (int i = 0; i < length; i++)
    {
        encrypted_char = user_word[i] ^ ENCRYPTION_BYTE;

        // if the encrypted characters match as-is, great
        if (encrypted_char == secret_word[i])
            continue;

        // change the character case (upper case <--> lower case)
        if ((user_word[i] > 96 && user_word[i] < 123))
            encrypted_char ^= 0x20;

        // compare again (eg, this is a case-insensitive compare)
        if (encrypted_char != secret_word[i])
            return 0; // fail
    }

    // the two words passed a case-insensitive 'encrypted compare'
    return 1;
}

int main(int argc, char *argv[])
{

    // clear();
    print_flag();
    game state = {};
    char buffer[16] = {};

    init_game(&state);

    while (!(state.game_over || state.solved))
    {

        print_matrix(&state);
        // printf("In while %d %d\n",state.game_over,state.solved);
        // prompt the user to guess the word
        printf("Enter word: \n");
        if (!fgets(buffer, sizeof(buffer), stdin))
            return 1;

        // strip new line of entered text
        buffer[strcspn(buffer, "\n")] = 0;

        // ensure the guessed word is exactly 5 letters
        if (strlen(buffer) != WORD_LENGTH)
        {
            printf(RED "\n 'INVALID INPUT'!\n" RESET);
            continue;
        }

        // the game will end if the entered word matches the encrypted wordle
        if (compare_encrypted(buffer, SOLUTION, WORD_LENGTH))
        {
            state.solved = 1;
            printf(MAG "CONGRATS! You match the word!\n" RESET);
            printf(MAG "Program finished!\n" RESET);
        }

        // the game will end if this is the last allowed guess
        else if (state.attempts + 1 == WORD_GUESSES)
        {
            state.game_over = 1;
            printf("%d", state.attempts);
        }

        // copy the word into wordle board
        strcpy(state.words[state.attempts], buffer);
        encrypt_word(state.words[state.attempts], WORD_LENGTH);
        state.attempts++;
        printf("TO SEE: %d\t%d\n", state.game_over, state.solved);
    }

    return 0;
}