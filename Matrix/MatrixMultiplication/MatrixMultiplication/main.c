#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS     3
#define COLUMNS  3

int main()
{
    int matrix[ROWS][COLUMNS] ;
    int matrix2[ROWS][COLUMNS] ;
    int matans[ROWS][COLUMNS] ;

    int k,l ;
    k = 0 ;
    l = 0 ;
    int sum  = 0 ;

    for(int i = 0 ; i < ROWS ; i++)
    {
        for(int j = 0 ; j < COLUMNS ; j++)
        {
            matrix[i][j] = (i * COLUMNS) + j ;
        }
    }

    for(int i = 0 ; i < ROWS ; i++)
    {
        printf("\n") ;

        for(int j = 0 ; j < COLUMNS ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

    printf("\n\n\n") ;

    for(int i = 0 ; i < ROWS ; i++)
    {
        for(int j = 0 ; j < COLUMNS ; j++)
        {
            matrix2[i][j] = (i * COLUMNS) + j ;
        }
    }

    for(int i = 0 ; i < ROWS ; i++)
    {
        printf("\n") ;

        for(int j = 0 ; j < COLUMNS ; j++)
        {
            printf("%d ",matrix2[i][j]) ;
        }
    }

    for(int i = 0 ; i < ROWS ; i++)
    {
        for(int j = 0 ; j < COLUMNS ; j++)
        {
            for(int m = 0 ; m < COLUMNS ; m++)
            {
               matans[i][j] = matrix[i][m] * matrix2[m][j] ;
            }

        }
    }

    printf("\n\n\n") ;

    for(int i = 0 ; i < ROWS ; i++)
    {
        printf("\n") ;

        for(int j = 0 ; j < COLUMNS ; j++)
        {
            printf("%d ",matans[i][j]) ;
        }
    }

    getch() ;
}
