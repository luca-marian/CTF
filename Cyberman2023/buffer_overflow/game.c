#include "wordle.h" // Hidden for simplicity

//
// Game definitions
//

#define WORD_LENGTH 5
#define WORD_GUESSES 6

typedef struct game
{
    short attempts;
    char words[WORD_GUESSES][WORD_LENGTH];
    char solved;
    char game_over;
} game;

//
// ShmooCon 2022 - x64 Pwnable Challenge
//

void main()
{
    init_wargame();

    game state = {};
    char buffer[16] = {};

    while (!(state.game_over || state.solved))
    {
        print_game(&state);
        
        // prompt the user to guess the word & exit if EOF
        printf("Enter word: ");
        if (!fgets(buffer, sizeof(buffer), stdin))
            return;

        // strip newline off entered text
        buffer[strcspn(buffer, "\n")] = 0;
 
        // ensure the guessed word is exactly 5 letters
        if (strlen(buffer) != WORD_LENGTH)
        {
            printf("\n   /!\\ "RED_COLOR"INVALID INPUT"RESET_COLOR" /!\\\n");
            continue;
        }
        
        // the game will end if the entered word matches the encrypted wordle
        if (compare_encrypted(buffer, wordle, WORD_LENGTH))
            state.solved = 1;

        // the game will end if this is the last allowed guess
        else if (state.attempts + 1 == WORD_GUESSES)
            state.game_over = 1;
        
        // copy the word onto the wordle board & encrypt it
        strcpy(state.words[state.attempts], buffer);
        encrypt_word(state.words[state.attempts], WORD_LENGTH);
        state.attempts++;
    }

    // print the final game board / state
    print_game(&state);
}

//
// Encryption 'helpers'
//

void encrypt_word(char * word, int length)
{
    for (int i = 0; i < length; i++)
        word[i] ^= ENCRYPTION_BYTE;
}

int compare_encrypted(char * user_word, char * secret_word, int length)
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

//
// If you can get here in LIVE mode, you win :-)
//

void ret2system()
{
    system("/bin/sh");
}