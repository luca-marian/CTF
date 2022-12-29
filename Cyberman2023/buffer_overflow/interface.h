#include <ctype.h>

#define WORD_LENGTH 5
#define WORD_GUESSES 6

const char SOLUTION[6] = "CYBER";


typedef struct game
{
    short attempts;
    char words[WORD_GUESSES][WORD_LENGTH];
    char solved;
    char game_over;
} game;

void init_game(game *state){

    state->solved = 0;
    state->game_over = 0;
}

char* to_upper(char *str){

    int j = 0;
    while (str[j]) {
        str[j] = toupper(str[j]);
        j++;
    }
    return (char*)str;
}

void print_matrix(game *state){
    // 5 columns and six rows

    for (int i=0;i<6;i++){
        printf(
        // "Enter your number in the box below\n"
        "+------+------+------+------+------+\n"
        "|  %c  |  %c  |  %c  |  %c  |  %c  |\n" ,
        state->words[i][0],state->words[i][1],state->words[i][2],state->words[i][3],state->words[i][4]
        // "+----+----+----+----+----+\n"
    );
    }
    //  gotoxy(3, 3);
    // int u;
    // scanf("%d",&u);
    printf("+------+------+------+------+------+\n");
}

void print_game(game *state){
// 5 columns and six rows
    // print_matrix();

    
   
}

void print_for_test(game *state){
    
    for(int i=0;i<state->attempts;i++){
        printf("%s\n",state->words[i]);
    }
}

