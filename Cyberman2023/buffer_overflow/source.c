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

void get_args(int argc,char *argv[]){

    if (argc>2){
        printf("Just 1 element is requred\n");
        exit(1);
    }
}


void print_flag(){
    printf("Congrats!");
    printf("The flag is: {Very good job!}");
}

void get_hint(){
    printf("You are almost there!");
}


int main(int argc, char *argv[])
{

    // clear();
    game state = {};
    char buffer[16] = {};

    init_game(&state);

    while (!(state.game_over || state.solved)){
        
        print_matrix(&state);
        // printf("In while %d %d\n",state.game_over,state.solved);
        //prompt the user to guess the word 
        printf("Enter word: ");
        if (!fgets(buffer,sizeof(buffer),stdin));

        //strip new line of entered text
        buffer[strcspn(buffer,"\n")] = 0;

        //ensure the guessed word is exactly 5 letters
        if(strlen(buffer) != WORD_LENGTH){
            printf("\n   /!\\ 'RED_COLOR'INVALID INPUT'RESET_COLOR' /!\\\n");
            continue;
        }

        // the game will end if you entered word matches
        if (!strcmp(to_upper(buffer),SOLUTION)){
            state.solved = 1;
            printf("CONGRATS! You match the word!");
        }
 
        // the game will end if this is the last allowed guess
        else if (state.attempts + 1 == WORD_GUESSES){
            state.game_over = 1;
            printf("%d",state.attempts);
        }

        // state.attempts +=1;
            
        // copy the word into wordle board
        strcpy(state.words[state.attempts++],buffer);

        // printf("In while %d %d",state.game_over,state.solved);

    }

    print_for_test(&state);
    // print_game(&state);
    return 0;
}