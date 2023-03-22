#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int matrix[ROWS][COLUMNS] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    } ;

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        for (int j = 0 ; j < ROWS ; j++)
        {
            matrix[i][j] = matrix[i][j] ;
        }
    }

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;

        for (int j = 0 ; j < COLUMNS ; j++)
        {
            if (matrix[i][j] % 3 == 0)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d",matrix[i][j]) ;
        }
    }
}
