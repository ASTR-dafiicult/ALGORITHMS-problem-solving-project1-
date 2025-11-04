# include "header.h"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BROWN   "\033[0;33m"
#define RESET    "\033[0m"
#define BLUE    "\033[0;34m"
#define CYAN    "\033[0;36m"
#define BMAGENTA "\033[1;35m"

void cat_header()
{
    printf("\n\033[1;35m\n"); // purple
    printf("      |\\__/,|   (`\\\n");
    printf("    _.|o_o  |    )_)\n");
    printf("---(((---(((--------\n");
    printf("\033[0;31m");
}
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
        printf(BROWN"%s choise : stone\n", player1);
        printf(BROWN"%s choise : paper\n", player2);
        printf(RED"winner round are : %s\n", player2);
        return res;
    }
    else if(me == 2 && win == 1)
    {
        printf(BROWN"%s choise : paper\n"RESET, player1);
        printf(BROWN"%s choise : stone\n"RESET, player2);
        printf(GREEN"round winner are %s\n"RESET, player1);
        return res;
    }
    else if(me == 3 && win == 1)
    {
        printf(BROWN"%s choise : scissors\n"RESET, player1);
        printf(BROWN"%s choise : stone\n"RESET, player2);
        printf(RED"round winner are : %s\n"RESET, player2);
        return res;
    }
    else if(me == 1 && win == 3)
    {
        printf(BROWN"%s choise : stone\n"RESET, player1);
        printf(BROWN"%s choise : scissors\n"RESET, player2);
        printf(GREEN"round winner are : %s\n"RESET, player1);
        return res;
    }
    else if(me == 2 && win == 3)
    {
        printf(BROWN"%s choise : paper \n"RESET, player1);
        printf(BROWN"%s choise : scissors \n"RESET, player2);
        printf(RED"round winner are : %s\n"RESET, player2);
        return res;
    }
    else if(me == 3 && win == 2)
    {
        printf(BROWN"%s choise : scissors\n"RESET, player1);
        printf(BROWN"%s choise : paper\n"RESET, player2);
        printf(GREEN"round winner are : %s\n"RESET, player1);
        return res;
    }
    else if(me == 1 && win == 1 && res == 0)
    {
        printf(YELLOW"%s choise : stone\n"RESET, player1);
        printf(YELLOW"%s choise : stone\n"RESET, player2);
        printf(YELLOW"round draw\n"RESET);
        return res;
    }
    else if(me == 2 && win == 2 && res == 0)
    {
        printf(YELLOW"%s choise : paper\n"RESET, player1);
        printf(YELLOW"%s choise : paper\n"RESET, player2);
        printf(YELLOW"round draw\n"RESET);
        return res;
    }
    else if(me == 3 && win == 3 && res == 0)
    {
        printf(YELLOW"%s choise : scissors\n"RESET, player1);
        printf(YELLOW"%s choise : scissors\n"RESET, player2);
        printf(YELLOW"round draw\n"RESET);
        return res;
    }
    return res;
}
void gameover()
{
    printf(BLUE"\t\t\t+++GAME OVER+++\n"RESET);
    printf(BLUE"\t|stone|-------|paper|-----|scissors|-----|\n"RESET);
}
void end_game(char player1[], char player2[], int my_winner, int win_win, int draw)
{
    gameover();
    printf(CYAN"\t------------------GAME RESULT------------------\n"RESET);
    printf(GREEN"\t    %s win %d times\n"RESET, player1, my_winner);
    printf(RED"\t    %s win %d times\n"RESET, player2, win_win);
    printf(YELLOW"\t    draw times [%d]\n"RESET, draw);
    printf(BMAGENTA"\t*_*_*_*_*_*_*_*_*_*_*_*_*_*_*__*_*_*_*_*_*_*_*_*_*_*\n"RESET);
}
void bar_loading()
{
    int colors[] = {31, 35, 32, 36, 33, 34};
    int length = 6;
    int stop = 35;
    printf("\033[0;33mLOADING...\033[0m\n");
    for(int i = 0; i <= stop; i++)
    {
        int color = colors[i % length];
        printf("\r\033[1;%dm[", color);
        for(int j = 0; j <= i; j++)
        {
            printf("=");
        }
        for(int k = i; k < stop; k++)
        {
            printf("/");
        }
        printf("]\033[1;%dm%3d%%", color, (i*100) / stop);
        fflush(stdout);
        usleep(22000);
    }
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
        printf(CYAN"\t----------ROUND [%d] START-------------\n"RESET, i+1);
        printf(BMAGENTA"choise /1-stone/2-paper/3-scissors : "RESET);
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
        cat_header();
        printf(BMAGENTA"\nhow many rounds you wan play : "RESET);
        scanf("%d", &nb);
        printf(YELLOW"enter name player1 : "RESET);
        scanf("%s", player1);
        printf(CYAN"enter name player2 : "RESET);
        scanf("%s", player2);
        start_rounds(nb, player1, player2);
        printf(YELLOW"do you want play agian(Y.y/n.N) : "RESET);
        scanf(" %c", yes);
        system("clear");
        bar_loading();
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
