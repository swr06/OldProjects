#include <bits/stdc++.h>
#include <conio.h>
#define ROW 8
#define COL 8
#define GREEN 7

using namespace std;

typedef struct coordinate
{
    int x ;
    int y ;
} coordinate ;

enum shapes
{
    square, rectangle, circle, triangle
};

enum dir
{
    north, south, east, west
};

int matrix[ROW][COL] ;

void init_matrix() ;
void print_matrix() ;
int rotate_matrix() ;
void scrclr() ;
void fill_colour_flood(int,int,int) ;
void fill_colour_flood_utility(int,int,int,int) ;
int draw_shape(int shape, int colour, coordinate start_c, coordinate end_c, bool fill_) ;
int draw_line(int,coordinate,coordinate) ;

int main()
{
    // driver program

    coordinate a,b ;

    a.x = 0 ;
    a.y = 0 ;
    b.x = 8 ;
    b.y = 8 ;

    cout << "Matrix!" << endl;
    init_matrix() ;
    print_matrix() ;
    getch() ;
    scrclr() ;
    draw_line(8,a,b) ;
    print_matrix() ;

    return 0 ;
}

void init_matrix()
{
    for (int i = 0 ; i < ROW ; i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            matrix[i][j] = 0 ;
        }
    }
}

void print_matrix()
{
    for (int i = 0 ; i < ROW ; i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            cout << matrix[i][j] << " " ;
        }

        cout << endl ;
    }
}

void fill_colour_flood(int x, int y, int new_colour)
{
    int prev_colour ;

    prev_colour = matrix[x][y] ;
    fill_colour_flood_utility(x, y, new_colour, prev_colour) ;
}

void fill_colour_flood_utility(int x, int y, int new_colour, int prev_colour)
{
    if (matrix[x][y] != prev_colour)
    {
        return ;
    }

    matrix[x][y] = new_colour ;
    fill_colour_flood_utility(x + 1,y,new_colour,prev_colour) ;
    fill_colour_flood_utility(x - 1,y,new_colour,prev_colour) ;
    fill_colour_flood_utility(x,y + 1,new_colour,prev_colour) ;
    fill_colour_flood_utility(x,y - 1,new_colour,prev_colour) ;
}

int draw_shape(int shape, int colour, coordinate start_c, coordinate end_c, bool fill_)
{
    if (shape == rectangle && fill_ == 1)
    {
        for (int i = start_c.x ; i <= end_c.x ; i++)
        {
            for (int j = start_c.y ; j <= end_c.y ; j++)
            {
                matrix[i][j] = colour ;
            }
        }
    }

    else if (shape == rectangle && fill_ == 0)
    {
        for (int i = start_c.y ; i < end_c.y ; i++)
        {
            matrix[start_c.x][i] = colour ;
        }

        for (int i = start_c.y ; i < end_c.y ; i++)
        {
            matrix[end_c.x][i] = colour ;
        }

        for (int i = start_c.x ; i < end_c.x ; i++)
        {
            matrix[i][start_c.y] = colour ;
        }

        for (int i = start_c.x ; i < end_c.x ; i++)
        {
            matrix[i][end_c.y] = colour ;
        }

        matrix[start_c.x][start_c.y] = colour ;
        matrix[end_c.x][end_c.y] = colour ;
    }
}

int draw_line (int colour, coordinate start_c, coordinate end_c)
{
    /*
    -> straight lines (same row and same col)
    -> diagonal lines (if the starting and ending x&y are equal)
    -> un uniform lines(still have to work on this method)
    */

    int temp ;
    int diagonal_hemisphere = ;
    coordinate temp_1 ;

    // swap check

    if (start_c.x > end_c.x)
    {
        temp = start_c.x ;
        start_c.x = end_c.x ;
        end_c.x = temp ;
    }

    if (start_c.x == end_c.x) // straight line (horizontal)
    {
        for (int i = start_c.y ; i < end_c.y ; i++)
        {
            matrix[start_c.x][i] = colour ;
        }
    }

    else if (start_c.y == end_c.y) // straight lines (vertical)
    {
        for (int i = start_c.x ; i < end_c.x ; i++)
        {
            matrix[i][start_c.y] = colour ;
        }
    }

    else if (start_c.x == start_c.y && end_c.x == end_c.y) // diagonal
    {
        for (int i = start_c.x ; i < end_c.x ; i++)
        {
            matrix[i][i] = colour ;
        }
    }

    else
    {

    }
}

void scrclr()
{
    system("@cls") ;
}

