#include <stdio.h>
#include <stdlib.h>

#define BOOL short
#define TRUE   1
#define FALSE  0
#define BUFFER1SIZE 32

int tab, num, table, pass, atab ;

int main()
{
    userverify() ;

    return 0;
}

int logic()
{
    int i = 0 ;

    tab = 0 ;
    pass = 0 ;

    for (i = 0 ; i < atab ; i++)
    {
        pass = pass + 1 ;
        tab = pass ;
        table = num * tab ;

        printf("\n%d x %d = %d",num,tab,table) ;
    }
    printf("\n") ;
    getch() ;
}

int userinput()
{
    scrclr() ;
    printf("Welcome to Tables Generator v01") ;
    printf("\nEnter the number : ") ;
    scanf("%d",&num) ;
    printf("Enter the amount of tables : ") ;
    scanf("%d",&atab) ;
}

int userverify()
{
    BOOL flag = FALSE ;
    char username[BUFFER1SIZE] ;
    char password[BUFFER1SIZE] ;
    char c  ;
    int i = 0 ;

    printf("Type the username : ") ;
    scanf("%s",&username) ;

    if (!strcmp(username,"Samuel"))
    {
        flag = TRUE ;
    }

    else
    {
        flag = FALSE ;
        printf("Wrong Username") ;
    }

    if (flag == TRUE)
    {
        printf("Type the password : ") ;

        while ((c = getch())!= '\r')
        {
            password[i] = c ;
            printf("*") ;
            i++ ;

            if (i > BUFFER1SIZE)
            {
                i = 0 ;
            }
        }

        password[i] = '\0' ;

        if (!strcmp(password,"prawsjsw"))
        {
            userinput() ;
            logic() ;
        }

        else
        {
            printf("\nWrong password") ;
            return 0 ;
        }
    }
}

void scrclr()
{
    system("@cls") ;
}
