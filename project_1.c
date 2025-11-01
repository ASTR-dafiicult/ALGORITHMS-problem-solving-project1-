# include "header.h"

int random_li(int from, int to)
{
    return rand() % (to - from) + from;
}
int rules(int me , int win)
{
    if(me == 1 && win == 2)
    {
        return win;
    }
    else if(me == 2 && win == 1)
    {
        return me;
    }
    else if(me == 3 && win == 1)
    {
        return win;
    }
    else if(me == 1 && win == 3)
    {
        return me;
    }
    else if(me == 2 && win == 3)
    {
        return win;
    }
    else if(me == 3 && win == 2)
    {
        return me;
    }
    else if(me == win)
    {
        return 0;
    }
    return 0;
}
int choise(int me, int win, char player1[], char player2[])
{
    int res = rules(me, win);
    if(me == 1 && win == 2)
    {
        printf("%s choise : stone\n", player1);
        printf("%s choise : paper\n", player2);
        printf("winner round are : %s\n", player2);
        return res;
    }
    else if(me == 2 && win == 1)
    {
        printf("%s choise : paper\n", player1);
        printf("%s choise : stone\n", player2);
        printf("round winner are %s\n", player1);
        return res;
    }
    else if(me == 3 && win == 1)
    {
        printf("%s choise : scissors\n", player1);
        printf("%s choise : stone\n", player2);
        printf("round winner are : %s\n", player2);
        return res;
    }
    else if(me == 1 && win == 3)
    {
        printf("%s choise : stone\n", player1);
        printf("%s choise : scissors\n", player2);
        printf("round winner are : %s\n", player1);
        return res;
    }
    else if(me == 2 && win == 3)
    {
        printf("%s choise : paper \n", player1);
        printf("%s choise : scissors \n", player2);
        printf("round winner are : %s\n", player2);
        return res;
    }
    else if(me == 3 && win == 2)
    {
        printf("%s choise : scissors\n", player1);
        printf("%s choise : paper\n", player2);
        printf("round winner are : %s\n", player1);
        return res;
    }
    else if(me == 1 && win == 1 && res == 0)
    {
        printf("%s choise : stone\n", player1);
        printf("%s choise : stone\n", player2);
        printf("round draw\n");
        return res;
    }
    else if(me == 2 && win == 2 && res == 0)
    {
        printf("%s choise : paper\n", player1);
        printf("%s choise : paper\n", player2);
        printf("round draw\n");
        return res;
    }
    else if(me == 3 && win == 3 && res == 0)
    {
        printf("%s choise : scissors\n", player1);
        printf("%s choise : scissors\n", player2);
        printf("round draw\n");
        return res;
    }
    return res;
}
void gameover()
{
    printf("\t\t\t+++GAME OVER+++\n");
    printf("\t|stone|-------|paper|-----|scissors|-----|\n");
}
void end_game(char player1[], char player2[], int my_winner, int win_win, int draw)
{
    gameover();
    printf("\t------------------GAME RESULT------------------\n");
    printf("\t%s win %d times\n", player1, my_winner);
    printf("\t%s win %d times\n", player2, win_win);
    printf("\tdraw times [%d]\n", draw);
    printf("\t*_*_*_*_*_*_*_*_*_*_*_*_*_*_*__*_*_*_*_*_*_*_*_*_*_*\n");
}
int start_rounds(int nb, char player1[], char player2[])
{
    int i = 0;
    int my_win = 0;
    int win_win = 0;
    int draw = 0;

    int res = 0;
    int me;
    int win;
    while(i < nb)
    {
        printf("\t----------ROUND [%d] START-------------\n", i+1);
        printf("choise /1-stone/2-paper/3-scissors : ");
        scanf("%d", &me);
        win = random_li(1, 3);
        res = choise(me, win, player1, player2);
        
        if(res == me)
        {
            my_win++;
        }
        else if(res == win)
        {
            win_win++;
        }
        else if(res == 0)
        {
            draw++;
        }
        i++;
    }
    end_game(player1, player2, my_win, win_win, draw);
    return 1;
}
void start_game(int nb, char player1[], char player2[])
{
    char yes[2];
    do{
        printf("how many rounds you wan play : ");
        scanf("%d", &nb);
        printf("enter name player1 : ");
        scanf("%s", player1);
        printf("enter name player2 : ");
        scanf("%s", player2);
        start_rounds(nb, player1, player2);
        printf("do you want play agian(Y.y/n.N) : ");
        scanf(" %c", yes);
        system("clear");
    }while(*yes == 'Y' || *yes == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    char player1[10];
    char player2[10];
    int nb = 0;
    start_game(nb, player1, player2);
}
