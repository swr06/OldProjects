#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS        3
#define COLUMNS     3

int ans = 0 ;

int main()
{
    int matrix[ROWS][COLUMNS] ;
    int i, j ;

    for (i = 0 ; i < ROWS ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COLUMNS ; j++)
        {
            matrix[i][j] = (i * COLUMNS ) + j ;

            if (i == j)
            {
                ans = ans + matrix[i][j] ;
            }

            printf("%d",matrix[i][j]) ;
        }
    }

    printf("\nThe sum of the diagnol numbers is : %d",ans) ;

    return 0 ;
}
