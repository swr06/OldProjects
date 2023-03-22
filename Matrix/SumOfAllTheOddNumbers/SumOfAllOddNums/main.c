#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int ans = 0 ;
    int i, j ;

    int matrix[ROWS][COLUMNS] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    } ;

    for (i = 0 ; i < COLUMNS ; i++)
    {
        for (j = 0 ; j < ROWS ; j++)
        {
            matrix[i][j] = matrix[i][j] ;
        }
    }

    for (i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COLUMNS ; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d",matrix[i][j]) ;
        }
    }

    for (i = 0 ; i < ROWS ; i++)
    {
        for (j = 0 ; j < COLUMNS ; j++)
        {
            ans = ans + matrix[i][j] ;
        }
    }
    printf("\nThe sum of the odd numbers in the matrix is : %d",ans) ;

    return 0 ;
}
