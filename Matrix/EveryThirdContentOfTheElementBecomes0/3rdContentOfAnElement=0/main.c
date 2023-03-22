#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 10
#define COLUMNS 10

int main()
{
    int matrix[ROWS][COLUMNS] ;

    int i, j ;

    for (i = 0 ; i < COLUMNS ; i++)
    {
        for (j = 0 ; j < ROWS ; j++)
        {
            // matrix[i][j] = (i * COLUMNS) + j ;      //this initialises the multi dimensional array as 1,2,3,4,5 ETC
            matrix[i][j] = 3 ;
        }
    }

    for (i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COLUMNS ; j++)
        {
            if ((i * COLUMNS) + j  % 3 == 0)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d ",matrix[i][j]) ;
        }
    }
    return 0 ;
}
