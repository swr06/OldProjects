///Sum of the elements in the array

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

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        for (int j = 0 ; j < ROWS ; j++)
        {
            ans = ans + matrix[i][j] ;
        }
    }

    printf("The sum of the matrix is %d",ans) ;

}
/// All diagnol numbers become zero

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int matrix[ROWS][COLUMNS] ;
    int ans = 0 ;

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        for (int j = 0 ; j < ROWS ; j++)
        {
            matrix[i][j] = 3 ;
        }
    }

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;
        for (int j = 0 ; j < COLUMNS ; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0 ;
            }
            printf("%d",matrix[i][j]) ;
        }
}

/// every number divisible by 3 = 0

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
    int ans = 0 ;

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

/// Sum of all the odd numbers in the matrix

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 3
#define COLUMNS 3

int main()
{
    int ans = 0 ;

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
            if (matrix[i][j] % 2 == 0)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d",matrix[i][j]) ;
        }
    }

    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLUMNS ; j++)
        {
            ans = ans + matrix[i][j] ;
        }
    }
    printf("\nThe sum of the odd numbers in the matrix is : %d",ans) ;
}

/// Sum of the diagnol numbers
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS        3
#define COLUMNS     3

int ans = 0 ;

int main()
{
    int matrix[ROWS][COLUMNS] ;

    for (int i = 0 ; i < ROWS ; i++)
    {
        printf("\n") ;
        for (int j = 0 ; j < COLUMNS ; j++)
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
}

///Every 3rd CONTENT OF THE element becomes 0 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 10
#define COLUMNS 10

int main()
{
    int matrix[ROWS][COLUMNS] ;

    int ans = 0 ;

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        for (int j = 0 ; j < ROWS ; j++)
        {
            // matrix[i][j] = (i * COLUMNS) + j ;      //this initialises the multi dimensional array as 1,2,3,4,5 ETC
            matrix[i][j] = 3 ;
        }
    }

    for (int i = 0 ; i < COLUMNS ; i++)
    {
        printf("\n") ;

        for (int j = 0 ; j < COLUMNS ; j++)
        {
            if ((i * COLUMNS) + j  % 3 == 0)
            {
                matrix[i][j] = 0 ;
            }

            printf("%d ",matrix[i][j]) ;
        }
    }
}

///Every ODD ELEMENT Becomes 1

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
    int a,b,c ;
    BOOL even ;

    a = 0 ;

    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLUMNS ; j++)
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
}


///Sum and difference Of the first elemnt and second element and so on of two matrix into the 1 element of the third matrix
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




