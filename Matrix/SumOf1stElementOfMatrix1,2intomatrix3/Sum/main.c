#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLUMNS 4

#define ROW (ROWS - 1)
#define COL (COLUMNS - 1)

int main()
{
    matadd() ;
    matsub() ;

    return 0 ;
}

int matadd()
{
    int matrix[ROWS][COLUMNS] ;
    int matrix2[ROWS][COLUMNS] ;
    int matrix3[ROWS][COLUMNS] ;
    int j ;
    int i ;

    printf("Addition") ;
    printf("\n\nMatrix 1 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix[i][j] = (i * COLUMNS) + j ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

/// Matrix 2
    printf("\n\nMatrix 2 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix2[i][j] = (i * COLUMNS) + j ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix2[i][j]) ;
        }
    }

///Matrix 3
    printf("\n\nMatrix 3 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix3[i][j] = matrix[i][j] + matrix2[i][j] ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix3[i][j]) ;
        }
    }

    printf("\n") ;
}


int matsub()
{
    int matrix[ROWS][COLUMNS] ;
    int matrix2[ROWS][COLUMNS] ;
    int matrix3[ROWS][COLUMNS] ;
    int j ;
    int i ;

    printf("\n\nSubtraction : ") ;
    printf("\n\nMatrix 1 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix[i][j] = (i * COLUMNS) + j ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

/// Matrix 2
    printf("\n\nMatrix 2 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix2[i][j] = (i * COLUMNS) + j ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix2[i][j]) ;
        }
    }

///Matrix 3
    printf("\n\nMatrix 3 : ") ;

    for (i = 0 ; i < ROW ; i++)
    {
        for (j = 0 ; j < COL ; j++)
        {
            matrix3[i][j] = matrix[i][j] - matrix2[i][j] ;
        }
    }

    for (i = 0 ; i < ROW ; i++)
    {
        printf("\n") ;

        for (j = 0 ; j < COL ; j++)
        {
            printf("%d ",matrix3[i][j]) ;
        }
    }

    printf("\n") ;

}
