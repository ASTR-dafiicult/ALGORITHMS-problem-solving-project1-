# include "header.h"

void board_bar(char casse[9])
{
    printf("\t   TIC-TAC-TOE\n");
    printf("\t*********************\n");
    printf("\t      |      |      \n");
    printf("\t %c    |   %c  |   %c  \n", casse[0], casse[1], casse[2]);
    printf("\t      |      |      \n");
    printf("\t======|======|======\n");
    printf("\t      |      |      \n");
    printf("\t %c    |   %c  |   %c  \n", casse[3], casse[4], casse[5]);
    printf("\t      |      |      \n");
    printf("\t======|======|======\n");
    printf("\t      |      |      \n");
    printf("\t %c    |   %c  |   %c  \n", casse[6], casse[7], casse[8]);
    printf("\t      |      |      \n");
    printf("\t*********************\n");

}
void rules(int choise, char mark, char cas[], int player)
{
    if(choise == 1 && cas[0] == '1')
    {
        cas[0] = mark;
    }
    else if(choise == 2 && cas[1] == '2')
    {
        cas[1] = mark;
    }
    else if(choise == 3 && cas[2] == '3')
    {
        cas[2] = mark;
    }
    else if(choise == 4 && cas[3] == '4')
    {
        cas[3] = mark;
    }
    else if(choise == 5 && cas[4] == '5')
    {
        cas[4] = mark;
    }
    else if(choise == 6 && cas[5] == '6')
    {
        cas[5] = mark;
    }
    else if(choise == 7 && cas[6] == '7')
    {
        cas[6] = mark;
    }
    else if(choise == 8 && cas[7] == '8')
    {
        cas[7] = mark;
    }
    else if(choise == 9 && cas[8] == '9')
    {
        cas[8] = mark;
    }
    else{
        printf("input not valid!chane it(1-9)\n");
        player--;
        getchar();
    }
}
int check_win(char cas[9])
{
    if(cas[0] == cas[1] && cas[1] == cas[2])
    {
        return 1;
    }
    else if(cas[3] == cas[4] && cas[4] == cas[5])
    {
        return 1;
    }
    else if(cas[6] == cas[7] && cas[7] == cas[8])
    {
        return 1;
    }
    else if(cas[0] == cas[3] && cas[3] == cas[6])
    {
        return 1;
    }
    else if(cas[1] == cas[4] && cas[4] == cas[7])
    {
        return 1;
    }
    else if(cas[2] == cas[5] && cas[5] == cas[8])
    {
        return 1;
    }
    else if(cas[0] == cas[4] && cas[4] == cas[8])
    {
        return 1;
    }
    else if(cas[2] == cas[4] && cas[4] == cas[6])
    {
        return 1;
    }
    else if(cas[0] != '1' && cas[1] != '2' && cas[2] != '3' && cas[3] != '4' && cas[4] != '5' && cas[5] != '6' && cas[6] != '7' && cas[7] != '8' && cas[8] != '9')
    {
        return 0;
    }
    else
        return -1;
}
void play(char player1[], char player2[])
{
    
    char cas[9] = {'1', '2', '3', '4','5', '6', '7', '8', '9'};
    int player = 1;
    int choise;
    char mark; // X || O
    int i = 0;

    do{
        system("clear");
        board_bar(cas);
        if(player % 2 == 1)
        {
            player = 1;
        }
        else{
            player = 2;
        }
        printf("choise between(1-9) : ");
        scanf("%d", &choise);
        if(player == 1)
        {
            mark = 'X';
        }
        else{
            mark = 'O';
        }
        rules(choise, mark, cas, player);
        i = check_win(cas); //-1 0 1
        player++;
    }while(i == -1);

    if(i == 1)
    {
        if(player % 2 == 0)
        {
            printf("player %s won\n", player1);
        }
        else{
            printf("player %s won game\n", player2);
        }
    }
    else if(i == 0)
    {
        printf("game draw\n");
    }
    getchar();
}

int main()
{
    char name1[10];
    char name2[10];
    printf("enter name : ");
    scanf("%s", name1);
    printf("enter name : ");
    scanf("%s", name2);
    play(name1, name2);
}