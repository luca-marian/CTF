# include "stdio.h"
# include "stdlib.h"
# include "interface.h"

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



// int main(int argc, char *argv[]){
//     get_args(argc,argv);
//     printf("Hello! I'm a simple buffer overflow CTF. You need to crack me in order to obtain a flag.\nGood luck!\n");

//     print_matrix();

//     return 0;
// }

#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int main(void)
{
    int number;

    clear();
    printf(
        "Enter your number in the box below\n"
        "+-----------------+\n"
        "|                 |\n"
        "+-----------------+\n"
    );
    gotoxy(2, 3);
    scanf("%d", &number);
    return 0;
}