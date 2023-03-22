#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS        5
#define COLUMNS     5
#define TRUE        1
#define FALSE       2
#define BOOL        short

int main()
{
    int matrix[ROWS][COLUMNS] ;
    int a ;
    int i, j ;
    a = 0 ;

    for (i = 0 ; i < ROWS ; i++)
    {
        for (j = 0 ; j < COLUMNS ; j++)
        {
            if((i + j) % 2 == 0 )
            {
                matrix[i][j] = 0 ;
            }

            else
            {
                matrix[i][j] = 1 ;
                a = a + 1 ;
            }

            printf("%d ",matrix[i][j]) ;
        }
    }

    printf("\n\nThe sum of the odd matrix is : %d",a) ;

    return 0 ;
}
