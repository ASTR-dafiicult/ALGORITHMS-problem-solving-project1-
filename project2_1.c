# include "header.h"

int random_numbers(int from , int to)
{
    return rand() % (to - from) + from;
}
char random_op()
{
    char op = (char) random_numbers(42, 47);
    while(op == 44 || op == 46)
    {
        op = (char)random_numbers(42, 47);
    }
    return op; //return random operation type
}
int numbers_lvl(int lvl)
{
    int number;
    if(lvl == 1)
    {
        number = random_numbers(1, 10);
    }
    else if(lvl == 2)
    {
        number = random_numbers(10, 50);
    }
    else if(lvl == 3)
    {
        number = random_numbers(50, 100);
    }
    else if(lvl == 4)
    {
        number = random_numbers(1, 200);
    }
    return number; //return random numbers
}
int op_type(int number1, int number2, char op)
{
    int total;
    if(op == '+')
    {
        total = number1 + number2;
    }
    else if(op == '-')
    {
        total = number1 - number2;
    }
    else if(op == '*')
    {
        total = number1 * number2;
    }
    else if(op == '/')
    {
        total = number1 / number2;
    }
    return total; //return total after operation
}
void game_res1()
{
    printf("\t\t\033[0;32mFINAL RESULT PASS :-)\033[0m\n");
    printf("\t\t\033[0;32m||------------------||\033[0m\n");
    printf("\t  \033[0;32m(((((YOU ARE GOOD YOU DO IT)))))\033[0m\n");
}
void game_res2()
{
    printf("\t\t\033[0;31mFINAL RESULT FAIL :-(\033[0m\n");
    printf("\t\t\033[0;31m||------------------||\033[0m\n");
    printf("\t  \033[0;31m)))))DON'T GIVE UP MAYBE NEXT TIME((((\033[0m\n");
}
void choise_res(int optype)
{
    if(optype == 1)
    {
        printf("OPTYPE : [add]\n");
    }
    else if(optype == 2)
    {
        printf("OPTYPE : [sub]\n");
    }
    else if(optype == 3)
    {
        printf("OPTYPE : [mul]\n");
    }
    else if(optype == 4)
    {
        printf("OPTYPE : [div]\n");
    }
}
void game_result(int nb, int lvl, char optype, int right, int wrong)
{
    if(right > wrong)
    {
        game_res1();
    }
    else{
        game_res2();
    }
    if(lvl == 1)
    {
        printf("questions level are : [easy]\n");
    }
    else if(lvl == 2)
    {
        printf("question level are  : [medium]\n");
    }
    else if(lvl == 3)
    {
        printf("question level are  : [hard]\n");
    }
    else
    {
        printf("question level are  : [mix]\n");
    }
    choise_res(optype);
    printf("\t\t***********************************\n");
    printf("------------NUMBER OF QUESTION ARE      :   ---%d\n", nb);
    printf("------------NUMBER OF RIGHT ANSWERS ARE :   ---%d\n", right);
    printf("------------NUMBER OF WRONG ANSWERS ARE :   ---%d\n", wrong);
    printf("\t\t************************************\n");
}
void start_operations(int nb, int lvl, int type)
{
    int right = 0;
    int wrong = 0;
    char op = 0;
    int res;
    int number1;
    int number2;
    int total = 0;
    int i = 0;
    if(type == 1) // +
    {
        while(i < nb)
        {
            printf("GESTION [%d/%d]\n", i+1, nb);
            number1 = numbers_lvl(lvl);
            number2 = numbers_lvl(lvl);
            op = 1;
            total = number1 + number2;
            printf("%d + %d\n", number1, number2);
            printf("------------------\n ");
            scanf("%d", &res);
            if(total == res)
            {
                printf("\033[0;32mRIGHT ANSWER!\033[0m\n");
                printf("it's : %d\n",  total);
                right++;
            }
            else{
                printf("\033[0;31mWRONG ANSWER! :-(\033[0m\n");
                printf("the right answer are : %d\n", total);
                wrong++;
            }
            i++;
        }
        game_result(nb, lvl, op, right, wrong);
    }
    if(type == 2) // -
    {
        int i = 0;
        while(i < nb)
        {
            printf("GESTION [%d/%d]\n", i+1, nb);
            number1 = numbers_lvl(lvl);
            number2 = numbers_lvl(lvl);
            op = 2;
            total = number1 - number2;
            printf("%d - %d\n", number1, number2);
            printf("----------\n");
            scanf("%d", &res);
            if(res == total)
            {
                printf("\033[0;32mRIGHT ANSWER!\033[0m\n");
                printf("it's :  %d\n", res);
                right++;
            }
            else{
                printf("\033[0;31mWRONG ANSWER! :-(\033[0m\n");
                printf("the right answer are : %d\n", total);
                wrong++;
            }
            i++;
        }
        game_result(nb, lvl, op, right, wrong);
    }
    if(type == 3) // x
    {
        int i = 0;
        while(i < nb)
        {
            printf("GESTION [%d/%d]\n", i+1, nb);
            number1 = numbers_lvl(lvl);
            number2 = numbers_lvl(lvl);
            op = 3;
            total = number1 * number2;
            printf("%d x %d\n", number1, number2);
            printf("---------\n");
            scanf("%d", &res);
            if(total == res)
            {
                printf("\033[0;32mRIGHT ANSWER!\033[0m\n");
                printf("it's : %d\n", res);
                right++;
            }
            else{
                printf("\033[0;31mWRONG ANSWER! :-(\033[0m\n");
                printf("the right answer are : %d\n", total);
                wrong++;
            }
            i++;
        }
        game_result(nb, lvl, op, right, wrong);
    }
    if(type == 4) // /
    {
        int i = 0;
        while(i < nb)
        {
            printf("GESTION[%d/%d]\n", i+1, nb);
            number1 = numbers_lvl(lvl);
            number2 = numbers_lvl(lvl);
            op = 4;
            total = number1 / number2;
            printf("%d / %d\n", number1, number2);
            printf("----------\n");
            scanf("%d", &res);
            if(total == res)
            {
                printf("\033[0;32mRIGHT ANSWER!\033[0m\n");
                printf("it's : %d\n", res);
                right++;
            }
            else{
                printf("\033[0;31mWRONG ANSWER! :-(\033[0m\n");
                printf("the right answer are : %d\n", total);
                wrong++;
            }
            i++;
        }
        game_result(nb, lvl, op, right, wrong);
    }
    if(type == 5) // mix
    {
        int i = 0;
        while(i < nb)
        {
            printf("GESTION [%d/%d]\n", i+1, nb);
            number1 = numbers_lvl(lvl);
            number2 = numbers_lvl(lvl);
            op = random_op();
            total = op_type(number1, number2, op);
            printf("%d %c %d\n", number1, op, number2);
            printf("----------\n");
            scanf("%d", &res);
            if(total == res)
            {
                printf("\033[0;32mRIGHT ANSWER!\033[0m\n");
                printf("it's : %d\n",  total);
                right++;
            }
            else{
                printf("\033[0;31mWRONG ANSWER! :-(\033[0m\n");;
                printf("the right answer are : %d\n", total);
                wrong++;
            }
            i++;
        }
        game_result(nb, lvl, op, right, wrong);
    }
}
void ascii_cat()
{
    printf("\n\033[1;35m\n"); // purple
    printf("      |\\__/,|   (`\\\n");
    printf("    _.|o_o  |    )_)\n");
    printf("---(((---(((--------\n");
    //printf("\033[0;31m");
    // reset
}
void bar_loading()
{
    int colors[] = {31, 35, 32, 36, 33, 34}; 
    int length = 6;
    int stop = 35;
     printf("\033[0;33mLOADING...\033[0m\n\n");
    for(int i = 0; i <= stop; i++)
    {
        int color = colors[i % length];
        printf("\r\033[1;%dm[", color);
        for(int j = 0; j < i;j++)
        {
            printf("=");
        }
        for(int j = i; j < stop; j++)
        {
            printf("/");
        }
        printf("]\033[1;%dm%3d%% \033[0m", color, (i * 100) / stop);
        fflush(stdout);
        usleep(120000);
    }
}
void start_game()
{
    int nb;
    int lvl;
    int choise;
    char yes[2];
    do{
        printf("\nHow Many Question You Want Answer : ");
        scanf("%d", &nb);
        printf("Question's LVL <--> [1]easy|[2]med|[3]hard|[4]mix : ");
        scanf("%d", &lvl);
        printf("Operation Type <--> [1]add|[2]sub|[3]mul|[4]div|[5]mix : ");
        scanf("%d", &choise);
        start_operations(nb, lvl, choise);
        printf("\033[0;33mDo You Want Play Again (y/n)(Y/N): \033[0m");
        scanf(" %c", yes);
        system("clear");
        bar_loading();
        ascii_cat();
        printf("\n\033[1;35m--------LET'S STAR NEW GAME-------\n\033[0m");
    }while(*yes == 'Y' || *yes == 'y');
}
int main()
{
    srand((unsigned)time(NULL));
    start_game();
}