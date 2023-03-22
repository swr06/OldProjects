#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int matrix[ROWS][COLUMNS] =
    {
        {4,5,6},
        {7,8,9},
        {10,11,12},
    } ;

    int ans = 0 ;
    int i, j ;

    for (i = 0 ; i < COLUMNS ; i++)
    {
        for (j = 0 ; j < ROWS ; j++)
        {
            ans = ans + matrix[i][j] ;
        }
    }

    printf("The sum of the matrix is %d",ans) ;

    return 0 ;
}
