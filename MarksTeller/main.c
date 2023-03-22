#include <stdio.h>
#include <stdlib.h>

void main()
{
    int marks ;

    // input of marks and Statements
    printf ("Marks Teller By Samuel Wesley Version 0.1\n") ;
    printf ("Enter the marks you got! : " ) ;
    scanf("%d",&marks) ;

    if (marks > 100)
        {
            printf ("You marks should come in a scale of 1 - 100") ;
            return 0 ;
        }

    if (marks == 0)
    {
        printf ("You are the ULTIMATE failure!") ;
    }

    if (marks >= 95)
        {
            printf ("You have scored : %s","Outstanding!") ;
            return 1 ;
        }

    if (marks >= 90)
        {
            printf ("You have scored : %s","Excellent!") ;
            return 2 ;
        }

    if (marks >= 80)
        {
            printf ("You have scored : %s","GREAT!") ;
            return 3 ;
        }

    if (marks >= 70 )
        {
            printf ("You have scored : %s","Good") ;
            return 4 ;
        }

    if (marks >= 60 )
        {
            printf ("You have scored : %s","Appreciatable") ;
            return 5 ;
        }

    if (marks >= 50)
        {
            printf ("You have scored : %s","Improvable") ;
            return 6 ;
        }

    if (marks >= 40)
        {
            printf ("You have scored : %s","Close to bad, but OK\n") ;
            return 7 ;
        }

    if (marks >= 30)
        {
            printf ("You have scored : %s","Bad") ;
            return 8 ;
        }

    if (marks >= 10)
        {
            printf ("You have scored : %s","Extremely BAD!") ;
            return 9 ;
        }

    if (marks >= 1)
        {
            printf ("You have scored : %s","You have shat well!") ;
            return 10 ;
        }

        return 11 ;
}
