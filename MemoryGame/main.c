/*
ask how many(either nums or characters)
generate or take inputs
ask whether to save to a file
ask the user to enter
compare
output() ;
*/
#include <stdio.h>
#include <stdlib.h>

#define WORD_LENGTH 10000
#define TRUE 1
#define FALSE 2

///GLOBAL VARIABLES
int amint ;

int main()
{
    input() ;
	//randcharprint() ; 
	
    return 0 ;
}

int memintegers()
{
    int localop ;
    int temp = 0 ;
    char localcop[8] ;
    int usrchk = 0 ;

    scrclr() ;
    printf("Enter the amount of numbers : ") ;
    scanf("%d",&amint) ;

    int memin[amint] ;

    for (int i = 0 ; i < amint ; i++)
    {
        temp++ ;
        printf("Enter the value of number %d : ",temp) ;
        scanf("%d",&memin[i]) ;
    }

    usrchk = 0 ;

    while (usrchk == 0)
    {
        usrchk = 1 ;
        scrclr() ;
        printf("You have entered the following values") ;
        temp = 0 ;

        for (int j = 0 ; j < amint ; j++)
        {
            temp++ ;
            printf("\nNumber %d : %d",temp,memin[j]) ;
        }

        printf("\n\nPress any key IF YOU FINISHED MEMORIZING") ;
        getch() ;
        scrclr() ;
        printf("Have you finished memorizing ? (y/n) : ") ;
        scanf("%s",&localcop) ;

        if (!strcmp(localcop,"y"))
        {
            usmemintegers(memin) ;
        }

        if (!strcmp(localcop,"Y"))
        {
            usmemintegers(memin) ;
        }

        if (!strcmp(localcop,"n"))
        {
            usrchk = 0 ;
        }

        if (!strcmp(localcop,"N"))
        {
            usrchk = 0 ;
        }
    }
}

int usmemintegers(int memina[amint])
{
    scrclr() ;
    int usmemin[amint] ;
    int lctemp = 0 ;

    for (int i = 0 ; i < amint ; i++)
    {
        usmemin[i] = 0 ;
    }

    printf("According to what you memorized what is : \n") ;

    for (int j = 0 ; j < amint ; j++)
    {
        lctemp++ ;
        printf("Number %d : ",lctemp) ;
        scanf("%d",&usmemin[j]) ;
    }

    scrclr() ;
    printf("\nCheck your answers") ;
    printf("\n         ORIGINAL   |   WHAT YOU WROTE ") ;
    lctemp = 0 ;

    for (int k = 0 ; k < amint ; k++)
    {
        lctemp++ ;
        printf("\nNumber %d :     %d       %d",lctemp,memina[k],usmemin[k]) ;
    }

    getch() ;
}

void scrclr()
{
    system("@cls") ;
}

int memchar()
{
    int localop ;
    int temp = 0 ;
    char localcop[8] ;
    int usrchk = 0 ;
    int check ;
    int check1 ;

    while(usrchk == 0)
    {
        usrchk = 1 ;
        scrclr() ;
        printf("Type 1 to ask random words (after memorizing)") ;
        printf("\nType 2 to ask the words in (1,2,3,4) order") ;
        printf("\nOPERATION : ") ;
        scanf("%d",&localop) ;

        switch(localop)
        {
            case 1 :
            {
                check1 = 1 ;

                break ;
            }

            case 2 :
            {
                check1 = 2 ;

                break ;
            }

            default :
            {
                usrchk = 0 ;

                break ;
            }
        }
    }

    scrclr() ;
    printf("Enter the number of words : ") ;
    scanf("%d",&amint) ;

    char word[amint][WORD_LENGTH] ;

    for (int i = 0 ; i < amint ; i++)
    {
        temp++ ;
        printf("Enter word %d : ",temp) ;
        scanf("%s",word[i]) ;
    }

    temp = 0 ;

    for(int i = 0 ; i < amint ; i++)
    {
        for(int j = 0 ; j < WORD_LENGTH ; j++)
        {
            if (word[i][j] == '\0')
            {
                break ;
            }

            printf("%c",word[i][j]) ;
        }

        printf("\n") ;
    }

    usrchk = 0 ;

    while (usrchk == 0)
    {
        usrchk = 1 ;
        scrclr() ;
        printf("You have entered the following values\n") ;
        temp = 0 ;

        for(int i = 0 ; i < amint ; i++)
        {
            temp++ ;
            printf("\nWord %d : ",temp) ;

            for(int j = 0 ; j < WORD_LENGTH ; j++)
            {
                if (word[i][j] == '\0')
                {
                    break ;
                }

                printf("%c",word[i][j]) ;
            }
        }

        printf("\n\nPress any key IF YOU FINISHED MEMORIZING") ;
        getch() ;
        scrclr() ;
        printf("Have you finished memorizing ? (y/n) : ") ;
        scanf("%s",&localcop) ;

        if (!strcmp(localcop,"y"))
        {
            check = 1 ;
        }

        if (!strcmp(localcop,"Y"))
        {
            check = 1 ;
        }

        if (!strcmp(localcop,"n"))
        {
            usrchk = 0 ;
        }

        if (!strcmp(localcop,"N"))
        {
            usrchk = 0 ;
        }
    }

    if (check = 1 )
    {
        char usword[amint][WORD_LENGTH] ;
        int temp1[amint] ;

        scrclr() ;
        temp = 0 ;
        printf("According to what you memorized what is : ") ;

        if (check1 == 1)
        {
            for (int i = 0 ; i < amint ; i++)
            {
                temp1[i] = rand() % amint ;
            }

            for (int i = 0 ; i < amint ; i++)
            {
                printf("\nWord %d : ",temp1[i]) ;
                scanf("%s",usword[i]) ;
            }
        }

        else if(check1 == 2)
        {
            for (int i = 0 ; i < amint ; i++)
            {
                printf("\nWord %d : ",(i+1)) ;
                scanf("%s",usword[i]) ;
            }
        }

        scrclr() ;
        temp = 0 ;

        printf("Check your answers\n") ;

        printf("            ORIGINAL | WHAT YOU WROTE") ;

        for(int i = 0 ; i < amint ; i++)
        {
            printf("\nWord %d :  %s             %s ",(i+1),word[i],usword[i]) ;
        }
    }
}

int integerask()
{
    int localop, localchk ;
    localchk = 0 ;

    while (localchk == 0)
    {
        localchk = 1 ;
        scrclr() ;
        printf("Type 1 to generate random numbers") ;
        printf("\nType 2 to enter each number manually") ;
        printf("\nOPERATION : ") ;
        scanf("%d",&localop) ;

        switch (localop)
        {
            case 1 :
            {
                randintegers() ;

                break ;
            }

            case 2 :
            {
                memintegers() ;

                break ;
            }

            default :
            {
                localchk = 0 ;

                break ;
            }
        }
    }
}

int randintegers()
{
    int localop ;
    int temp = 0 ;
    char localcop[8] ;
    int usrchk = 0 ;
    int randmax ;

    scrclr() ;
    printf("Enter the amount of numbers : ") ;
    scanf("%d",&amint) ;
    printf("range is from 0 to : ") ;
    scanf("%d",&randmax) ;

    int memin[amint] ;

    for (int i = 0 ; i < amint ; i++)
    {
        memin[i] = rand() % randmax ;
    }

    usrchk = 0 ;

    while (usrchk == 0)
    {
        usrchk = 1 ;
        scrclr() ;
        printf("The values generated were : ") ;

        for (int j = 0 ; j < amint ; j++)
        {
            printf("\nNumber %d : %d",(j + 1),memin[j]) ;
        }

        printf("\n\nPress any key IF YOU FINISHED MEMORIZING") ;
        getch() ;
        scrclr() ;
        printf("Have you finished memorizing ? (y/n) : ") ;
        scanf("%s",&localcop) ;

        if (!strcmp(localcop,"y"))
        {
            usmemintegers(memin) ;
        }

        if (!strcmp(localcop,"Y"))
        {
            usmemintegers(memin) ;
        }

        if (!strcmp(localcop,"n"))
        {
            usrchk = 0 ;
        }

        if (!strcmp(localcop,"N"))
        {
            usrchk = 0 ;
        }
    }
}

int input()
{
    int op ;
    int usrchk = 0 ;

    while(usrchk == 0)
    {
        usrchk = 1 ;
        printf("Welcome to the Memory game V01\n") ;
        printf("\nType 1 to memorize integers") ;
        printf("\nType 2 to memorize characters") ;
        printf("\nOPERATION : ") ;
        scanf("%d",&op) ;

        switch (op)
        {
            case 1 :
            {
                integerask() ;

                break ;
            }

            case 2 :
            {
                memchar() ;

                break ;
            }

            default :
            {
                usrchk = 0 ;

                break ;
            }
        }
    }
    getch() ;
}

int randcharprint() 
{
	int localop ; 
	int localchk = FALSE ; 
	
	while(localchk == FALSE)
	{
		localchk = TRUE ; 
		scrclr() ; 
		printf("Type 1 to go EASY") ;
		printf("\nType 2 to go NORMAL") ;
		printf("\nType 3 to go HARD") ;
		printf("\nType 4 to go EXTREMELY HARD") ;
		printf("\nOPERATION : ") ;
		scanf("%d",&localop) ;
		scrclr() ; 
		
		switch(localop)
		{
			case 1 : 
			{
				randchareasy() ; 
				
				break ;
			}
			
			case 2 : 
			{
				
				
				break ;
			}
			
			case 3 : 
			{
				
				
				break ;
			}
			
			case 4 : 
			{
				
				
				break ;
			}
			
			default : 
			{
				localchk = FALSE ; 
				
				break ; 
			}
		}
	}
}

int randchareasy()
{
	char randword[1024] ; 
	int randc ; 
	int localamount ; 
	int localchk = FALSE ; 
	int temp ; 
	
	while(localchk == FALSE)
	{
		localchk = TRUE ; 
		scrclr() ; 
		printf("Enter the amount of random words do you wanna generate (MAX : 100) : ") ;
		scanf("%d",&localamount) ;
		
		for (int i = 0 ; i < localamount ; i++)
		{
			if (localamount > 100)
			{
				localchk = FALSE ; 
				
				break ; 
			}

			temp = randc ;
 			randc = rand() % localamount ;
			
			if (randc == temp)
			{
				randc = rand() % localamount ; 
			}
			
			printf("randc = %d\n",randc) ;
		}
		
	}
}