#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int matrix[ROWS][COLUMNS] ;
    int i = 0 ;
    int j = 0 ;

    for (i = 0 ; i < COLUMNS ; i++)
    {
        for (j = 0 ; j < ROWS ; j++)
        {
            matrix[i][j] = 3 ;
        }
    }

    for (i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COLUMNS ; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d",matrix[i][j]) ;
        }
    }

    return 0 ;
}
