#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void print_matrix(){
    // 5 columns and six rows

    for (int i=0;i<6;i++){
        for (int j=0;j<5;j++){
            printf("_____\n|   |\n|   |\n_____\t");
        }
    }   
}

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
    // gotoxy(2, 3);
    scanf("%d", &number);
    return 0;
}