#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void print_matrix(){
    // 5 columns and six rows

    for (int i=0;i<6;i++){
        printf(
        // "Enter your number in the box below\n"
        "+----+----+----+----+----+\n"
        "|    |    |    |    |    |\n"
        // "+----+----+----+----+----+\n"
    );
    }
    //  gotoxy(3, 3);
    // int u;
    // scanf("%d",&u);
    printf("+----+----+----+----+----+\n");
}

int main(void)
{
    int number;

    clear();
    print_matrix();
    
    printf("Insert a number of 5 letters:\n");
    scanf("%d", &number);
    return 0;
}