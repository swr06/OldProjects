/// REMAINING : AUSDOLLAR, REN

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int op,op1, op2, op3, op4 ;
char name0 [32] ;
char name1 [32] ;
char name2 [32] ;
char name3 [32] ;
char name4 [32] ;
char name5 [32] ;
char name6 [32] ;
float ans, cur ;

int main()
{
    name0[0] = '\0' ;
    name1[0] = '\0' ;
    name2[0] = '\0' ;
    name3[0] = '\0' ;
    name4[0] = '\0' ;
    name5[0] = '\0' ;
    name6[0] = '\0' ;

    displayheader() ;
}

void displayheader()
{
    char opname[1024] ;

    opname[0] = '\0' ;
    printf("Welcome to currency convertor v01") ;
    strcpy(opname,"USD,EUR,PND,REN") ;
    printf("\nPress 1 to convert from INR to %s",opname) ;
    strcpy(opname,"INR,EUR,PND,REN") ;
    printf("\nPress 2 to convert from USD to %s",opname) ;
    strcpy(opname,"INR,USD,PND,REN") ;
    printf("\nPress 3 to convert from EUR to %s",opname) ;
    strcpy(opname,"INR,USD,EUR,REN") ;
    printf("\nPress 4 to convert from PND to %s",opname) ;
    strcpy(opname,"INR,USD,EUR,PND") ;
    printf("\nPress 5 to convert from REN to %s",opname) ;
    printf("\nOPERATION : ") ;
    scanf("%d",&op) ;
    printsystem() ;
}

int printsystem()
{
    switch(op)
    {
        case 1 :
        {
            strcpy(name0,"INR") ;
            strcpy(name1,"USD") ;
            strcpy(name2,"EUR") ;
            strcpy(name3,"PND") ;
            strcpy(name4,"REN") ;
            childprintsystem() ;
            ilogic() ;

            break ;
        }

        case 2 :
        {
            strcpy(name0,"USD") ;
            strcpy(name1,"INR") ;
            strcpy(name2,"EUR") ;
            strcpy(name3,"PND") ;
            strcpy(name4,"REN") ;
            childprintsystem() ;
            ulogic() ;

            break ;
        }

        case 3 :
        {
            strcpy(name0,"EUR") ;
            strcpy(name1,"USD") ;
            strcpy(name2,"INR") ;
            strcpy(name3,"PND") ;
            strcpy(name4,"REN") ;
            childprintsystem() ;
            elogic() ;

            break ;
        }

        case 4 :
        {
            strcpy(name0,"PND") ;
            strcpy(name1,"USD") ;
            strcpy(name2,"INR") ;
            strcpy(name3,"EUR") ;
            strcpy(name4,"REN") ;
            childprintsystem() ;
            plogic() ;

            break ;
        }

        case 5 :
        {
            strcpy(name0,"REN") ;
            strcpy(name1,"USD") ;
            strcpy(name2,"INR") ;
            strcpy(name3,"EUR") ;
            strcpy(name4,"PND") ;
            childprintsystem() ;
            renlogic() ;

            break ;
        }
    }
}

void childprintsystem()
{
    scrclr() ;
    printf("You have selected %s",name0) ;
    printf("\nType 1 to convert %s to %s",name0,name1) ;
    printf("\nType 2 to convert %s to %s",name0,name2) ;
    printf("\nType 3 to convert %s to %s",name0,name3) ;
    printf("\nType 4 to convert %s to %s",name0,name4) ;
    printf("\nOPERATION : ") ;
    scanf("%d",&op1) ;
}

void scrclr()
{
    system("@cls") ;
}

int ilogic()
{
    strcpy(name5,"INR") ;
    switch (op1)
    {
        case 1 :
        {
            strcpy(name6,"USD") ;
            printlogic() ;
            ans = cur / 65.03 ;

            break ;
        }

        case 2 :
        {
            strcpy(name6,"EUR") ;
            printlogic() ;
            ans = cur / 76.75 ;

            break ;
        }

        case 3 :
        {
            strcpy(name6,"PND") ;
            printlogic() ;
            ans = cur / 85.35 ;

            break ;
        }

        case 4 :
        {
            strcpy(name6,"REN") ;
            printlogic() ;
            ans = cur / 09.83 ;

            break ;
        }
    }
    printanswer() ;
}

int ulogic()
{
    strcpy(name5,"USD") ;
    switch (op1)
    {
        case 1 :
        {
            strcpy(name6,"USD") ;
            printlogic() ;
            ans = cur * 65.03 ;

            break ;
        }

        case 2 :
        {
            strcpy(name6,"EUR") ;
            printlogic() ;
            ans = cur * 0.848857 ;

            break ;
        }

        case 3 :
        {
            strcpy(name6,"PND") ;
            printlogic() ;
            ans = cur / 1.32068120737 ;

            break ;
        }

        case 4 :
        {
            strcpy(name6,"REN") ;
            printlogic() ;
            ans = cur * 06.62 ;

            break ;
        }
    }
    printanswer() ;
}

int elogic()
{
    strcpy(name5,"EUR") ;
    switch (op1)
    {
        case 1 :
        {
            strcpy(name6,"USD") ;
            printlogic() ;
            ans = cur * 1.17964313436 ;

            break ;
        }

        case 2 :
        {
            strcpy(name6,"INR") ;
            printlogic() ;
            ans = cur * 76.71 ;

            break ;
        }

        case 3 :
        {
            strcpy(name6,"PND") ;
            printlogic() ;
            ans = cur * 1.11885258358 ;

            break ;
        }

        case 4 :
        {
            strcpy(name6,"REN") ;
            printlogic() ;
            ans = cur * 07.80157 ;

            break ;
        }
    }
    printanswer() ;
}

int plogic()
{
    strcpy(name5,"PND") ;
    switch (op1)
    {
        case 1 :
        {
            strcpy(name6,"USD") ;
            printlogic() ;
            ans = cur * 1.3189549656 ;

            break ;
        }

        case 2 :
        {
            strcpy(name6,"INR") ;
            printlogic() ;
            ans = cur * 85.59 ;

            break ;
        }

        case 3 :
        {
            strcpy(name6,"EUR") ;
            printlogic() ;
            ans = cur * 1.11895028353 ;

            break ;
        }

        case 4 :
        {
            strcpy(name6,"REN") ;
            printlogic() ;
            ans = cur * 08.75 ;

            break ;
        }
    }
    printanswer() ;
}

int renlogic()
{
    strcpy(name5,"REN") ;
    switch (op1)
    {
        case 1 :
        {
            strcpy(name6,"USD") ;
            printlogic() ;
            ans = cur * 6.64 ;

            break ;
        }

        case 2 :
        {
            strcpy(name6,"INR") ;
            printlogic() ;
            ans = cur * 0.10 ;

            break ;
        }

        case 3 :
        {
            strcpy(name6,"EUR") ;
            printlogic() ;
            ans = cur * 7.79 ;

            break ;
        }

        case 4 :
        {
            strcpy(name6,"PND") ;
            printlogic() ;
            ans = cur * 08.75 ;

            break ;
        }
    }
    printanswer() ;
}

void printlogic()
{
    scrclr() ;
    printf("Enter the amount of %s : ",name5) ;
    scanf("%f",&cur) ;
}

void printanswer()
{
    printf("%f %s = %f %s",cur,name5,ans,name6) ;
    printf("\n\n") ;
    getch() ;
}
