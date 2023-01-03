#include <ctype.h>

#define WORD_LENGTH 5
#define WORD_GUESSES 6

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"
char ENCRYPTION_BYTE = '\x29';

char SOLUTION_CLEAR[6] = "CYBER";
char SOLUTION[6] = "\x6a\x70\x6b\x6c";

typedef struct game
{
    short attempts;
    char words[WORD_GUESSES][WORD_LENGTH];
    char solved;
    char game_over;
} game;

void init_game(game *state)
{
    //     state->solved = 0;
    //     state->game_over = 0;
}

char *to_upper(char *str)
{
    // int j = 0;
    // while (str[j])
    // {
    //     str[j] = toupper(str[j]);
    //     j++;
    // }
    return (char *)str;
}

void print_color(const char *word)
{

    if (word[0] == SOLUTION[0])
        printf(
            // "Enter your number in the box below\n"
            "+-----+-----+-----+-----+-----+\n"
            "|  \x1B[32m%c\x1B[0m  |  %c  |  %c  |  %c  |  %c  |\n",
            word[0], word[1], word[2], word[3], word[4]);

    if (word[1] == SOLUTION[1])
        printf(
            // "Enter your number in the box below\n"
            "+-----+-----+-----+-----+-----+\n"
            "|  %c |   \x1B[32m%c\x1B[0m  |  %c  |  %c  |  %c  |\n",
            word[0], word[1], word[2], word[3], word[4]);

    if (word[2] == SOLUTION[2])
        printf(
            // "Enter your number in the box below\n"
            "+-----+-----+-----+-----+-----+\n"
            "|  %c  |  %c  |   \x1B[32m%c\x1B[0m   |  %c  |  %c  |\n",
            word[0], word[1], word[2], word[3], word[4]);

    if (word[3] == SOLUTION[3])
        printf(
            // "Enter your number in the box below\n"
            "+-----+-----+-----+-----+-----+\n"
            "|  %c |  %c  |  %c  |   \x1B[32m%c\x1B[0m   |  %c  |\n",
            word[0], word[1], word[2], word[3], word[4]);

    if (word[4] == SOLUTION[4])
        printf(
            // "Enter your number in the box below\n"
            "+-----+-----+-----+-----+-----+\n"
            "|  %c |  %c  |  %c  |  %c  |   \x1B[32m%c\x1B[0m   |\n",
            word[0], word[1], word[2], word[3], word[4]);
}

void print_matrix(game *state)
{
    // 5 columns and 6 rows

    for (int i = 0; i < 6; i++)
    {
        if (state->words[i][0] == 0)
        {
            printf(
                "+-----+-----+-----+-----+-----+\n"
                "|     |     |     |     |     |\n");
        }
        else
        {
            printf(
                // "Enter your number in the box below\n"
                "+-----+-----+-----+-----+-----+\n"
                "|  %c  |  %c  |  %c  |  %c  |  %c  |\n",
                state->words[i][0] ^ ENCRYPTION_BYTE, state->words[i][1] ^ ENCRYPTION_BYTE, state->words[i][2] ^ ENCRYPTION_BYTE,
                state->words[i][3] ^ ENCRYPTION_BYTE, state->words[i][4] ^ ENCRYPTION_BYTE);
            // print_color(state->words[i]);
        }
    }

    printf("+-----+-----+-----+-----+-----+\n");
    printf("Attemps %d/6\n", state->attempts + 1);
}

void print_matrixx(game *state)
{
    // 5 columns and 6 rows

    for (int i = 0; i < 6; i++)
    {
        if (state->words[i][0] == 0)
        {
            printf(
                "+-----+-----+-----+-----+-----+\n"
                "|     |     |     |     |     |\n");
        }
        else
        {
            printf(
                // "Enter your number in the box below\n"
                "+-----+-----+-----+-----+-----+\n"
                "|  %c  |  %c  |  %c  |  %c  |  %c  |\n",
                state->words[i][0], state->words[i][1], state->words[i][2],
                state->words[i][3], state->words[i][4]);
            // print_color(state->words[i]);
        }
    }

    printf("+-----+-----+-----+-----+-----+\n");
    printf("Attemps %d/6\n", state->attempts + 1);
}

void print_for_test(game *state)
{

    for (int i = 0; i < state->attempts; i++)
    {
        printf("%s\n", state->words[i]);
    }
}
