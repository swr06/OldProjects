/*
Author : Samuel Wesley Rasquinha
Email : samuelrasquinha@gmail.com
Title : Basic Path Finding AI program Alpha 0.1
Age : 12
Description : This is a simple AI that manages to find its way to a destination but it is not perfect
Version : 1.0 Alpha
Updates : 2018 - 9 - 16
Comments : Not Yet
Reference : 8 bit guy
*/

#include <bits/stdc++.h>
#include <conio.h>
#define ROW 10
#define COL 10
#define right right_

using namespace std;

void error() ;
int random_move(int choice_1, int choice_2) ;
int AI_() ;
void play() ;
int direction_avalible_chk(int direction) ;
int go_in_direction(int go_direction) ;
int win_chk() ;
int find_destination_direction() ;
int in_range(int range_row, int range_col, int row_count, int col_count, int value_to_find) ;
void draw_feild() ;
void initialize_feild() ;
void scrclr() ;

int feild[ROW][COL] ;
int player_x = 0 ;
int player_y = 1 ;
int prev_player_x = 0 ;
int prev_player_y = 0 ;
int dest_x ;
int dest_y ;
int direction_destination ;
int best_move_array[3] ;

void play() ;

enum feild_space
{
    vacant, block, player, destination
};

enum direction
{
    up_left, up_right, down_left, down_right, middle_vertical, middle_horizontal
};

enum go_direction
{
    up = 0, down = 1, left_ = 2, right_ = 3
};

int main()
{
    initialize_feild() ;
    draw_feild() ;


    return 0;
}

void initialize_feild()
{
    for (int i = 0 ; i < ROW ; i++)
    {
        for (int j = 0 ; j < COL ; j++)
        {
            feild[i][j] = vacant ;
        }
    }

    feild[0][1] = player ;
    feild[4][1] = block ;
    feild[4][2] = block ;
    feild[4][3] = player ;
    feild[7][8] = destination ;
}

void draw_feild()
{
    scrclr() ;

    for (int i = 0 ; i < ROW ; i++)
    {
        cout << "|" ;

        for (int j = 0 ; j < COL ; j++)
        {
            if (feild[i][j] == block)
            {
                cout << " " << (char) 219 ;
                cout << " |" ;
            }

            else if (feild[i][j] == player)
            {
                cout << " " << (char) 12 ;
                cout << " |" ;
            }

            else
            {
                cout << "  " ;
                cout << " |" ;
            }
        }

        cout << endl ;
        cout << "-----------------------------------------" ;
        cout << endl ;
    }
}

int in_range(int range_row, int range_col, int row_count, int col_count, int value_to_find)
{
    /* Return Values ::
    1 = The value is in the range
    0 = The value is not in the range
    */

    int row_current = range_row ;
    int col_current = range_col ;
    int return_value = 0 ;

    for (int i = 0 ; i < row_count ; i++)
    {
        for (int j = 0 ; j < col_count ; j++)
        {
            col_current = col_current + 1 ;

            if (feild[row_current][col_current] == value_to_find)
            {
                return_value = 1 ;

                break ;
            }
        }

        if (return_value == 1)
        {
            break ;
        }

        row_current = row_current + 1 ;
        col_current = range_col ;
    }

    return return_value ;
}

int find_destination_direction()
{
    if (in_range(0,0,4,4,destination) == 1)
    {
        direction_destination = up_left ;
    }

    else if (in_range(0,6,4,4,destination) == 1)
    {
        direction_destination = up_right ;
    }

    else if (in_range(6,0,4,4,destination) == 1)
    {
        direction_destination = down_left ;
    }

    else if (in_range(6,6,4,4,destination) == 1)
    {
        direction_destination = down_right ;
    }

    else if (in_range(0,4,10,2,destination) == 1)
    {
        direction_destination = middle_vertical ;
    }

    else if (in_range(4,0,2,10,destination) == 1)
    {
        direction_destination = middle_horizontal ;
    }

    else
    {
        return -1 ;
    }

    return 1 ;
}

int win_chk()
{
    if (player_x == dest_x && player_y == dest_y - 1 | player_x == dest_x && player_y == dest_y + 1)
    {
        return 1 ;
    }

    else if (player_y == dest_y && player_x == dest_x - 1 | player_y == dest_y && player_x == dest_x + 1)
    {
        return 1 ;
    }

    else
    {
        return 0 ;
    }
}

int go_in_direction(int go_direction)
{
    int return_val = 0 ;

    prev_player_x = player_x ;
    prev_player_y = player_y ;

    if (direction_avalible_chk(go_direction) == 1)
    {
        if (go_direction == up)
        {
            player_x = player_x - 1 ;
        }

        else if (go_direction == down)
        {
            player_x = player_x + 1 ;
        }

        else if (go_direction == right_)
        {
            player_y = player_y + 1 ;
        }

        else if (go_direction == left_)
        {
            player_y = player_y - 1 ;
        }

        play() ;
        return_val = 1 ;
    }

    return return_val ;
}

int direction_avalible_chk(int direction)
{
    if (direction == up)
    {
        if (feild[player_x - 1][player_y] == vacant)
        {
            return 1 ;
        }
    }

    else if (direction == down)
    {
        if (feild[player_x + 1][player_y] == vacant)
        {
            return 1 ;
        }
    }

    else if (direction == left_)
    {
        if (feild[player_x][player_y + 1] == vacant)
        {
            return 1 ;
        }
    }

    else if (direction == right_)
    {
        if (feild[player_x][player_y - 1] == vacant)
        {
            return 1 ;
        }
    }

    return 0 ;
}

void play()
{
    feild[prev_player_x][prev_player_y] = vacant ;
    feild[player_x][player_y] = player ;
}

int AI_() // i left of here
{
    int direction_horizontal ;
    int direction_vertical ;
    int step_x = ROW ;
    int step_y = COL ;

    for (int i = 0 ; i <= step_x ; i++)
    {
        draw_feild() ;

        for (int j = 0 ; j <= step_y ; j++)
        {
            if (direction_horizontal == right && direction_avalible_chk(right) == 1)
            {
                go_in_direction(right) ;
                step_y-- ;
            }

            else
            {
                // best system
            }

            if (direction_horizontal == left && direction_avalible_chk(left) == 1)
            {
                go_in_direction(left) ;
                step_y-- ;
            }

            else
            {
                // best system
            }
        }

        if (direction_vertical == up)
        {
            if (direction_avalible_chk(up) == 1)
            {
                go_in_direction(up) ;
                step_x-- ;
            }

            if (direction_horizontal == right)
            {
                direction_horizontal = left ;
            }

            else if (direction_horizontal == left)
            {
                direction_horizontal = right ;
            }
        }

        else
        {
            // best_system
        }

        if (direction_vertical == down)
        {
            if (direction_avalible_chk(down) == 1)
            {
                go_in_direction(down) ;
                step_x-- ;
            }

            if (direction_horizontal == right)
            {
                direction_horizontal = left ;
            }

            else if (direction_horizontal == left)
            {
                direction_horizontal = right ;
            }
        }

        else
        {
            // best_system
        }
    }
}

int AI_Best_System(int dir_moving) // todo : child function for best system which moves accordingly and tells whether it played or needs to change direction
{
    /* Return Values ::
    -1 = failed
    1 = played
    2 = go in the opposite direction
    */

    // up left

    if (player_x == dest_x && direction_destination == up_left)
    {
        init_best_array(left_,up,down,right_) ;
    }

    else if (player_y == dest_y && direction_destination == up_left)
    {
        init_best_array(up,left_,right_,down) ;
    }

    else if (direction_destination == up_left)
    {
        init_best_array(up,left_,right_,down) ;
    }

    // up right

    else if (player_x == dest_x && direction_destination == up_right)
    {
        init_best_array(right_,up,down,left) ;
    }

    else if (player_y == dest_y && direction_destination == up_right)
    {
        init_best_array(up,right_,left_,down) ;
    }

    else if (direction_destination == up_right)
    {
        init_best_array(up,left_,right_,down) ;
    }

    // middle horizontal

    else if (player_x == dest_x && direction_destination == middle_horizontal)
    {
         if (in_range(4,0,2,5,destination) == 1)  // if the destination is on the left
         {
             init_best_array(left_,up,down,right_) ;
         }

         else if (in_range(4,5,2,5,destination) == 1)  // if the destination is on the right
         {
            init_best_array(right_,up,down,left_) ;
         }
    }

    else if (player_y == dest_y && direction_destination == middle_horizontal)
    {
        if (dest_x < user_x) // if the destination is down
        {
            init_best_array(down,right_,left_,up) ;
        }

        else if (dest_x > user_x) // if the destination is up
        {
            init_best_array(up,right_,left_,down) ;
        }
    }

    else if (direction_destination == middle_horizontal)
    {
        if (dest_x < user_x) // if the destination is down
        {
            if (in_range(4,0,2,5,destination) == 1)  // if the destination is on the left
            {
                init_best_array(down,left_,up,right_) ;
            }

            else if (in_range(4,5,2,5,destination) == 1)  // if the destination is on the right
            {
                init_best_array(down,right_,up,left) ;
            }
        }

        else if (dest_x > user_x) // if the destination is up
        {
            if (in_range(4,0,2,5,destination) == 1)  // if the destination is on the left
            {
                init_best_array(up,left_,down,right_) ;
            }

            else if (in_range(4,5,2,5,destination) == 1)  // if the destination is on the right
            {
                init_best_array(up,right_,down,left_) ;
            }
        }
    }

    // down left

    if (player_x == dest_x && direction_destination == down_left)
    {
        init_best_array(left_,down,up,right_) ;
    }

    else if (player_y == dest_y && direction_destination == down_left)
    {
        init_best_array(down,left_,right_,up) ;
    }

    else if (direction_destination == down_left)
    {
        init_best_array(down,left_,right_,up) ;
    }

    // down right

    else if (player_x == dest_x && direction_destination == down_right)
    {
        init_best_array(right_,down,up,left) ;
    }

    else if (player_y == dest_y && direction_destination == down_right)
    {
        init_best_array(down,right_,left_,up) ;
    }

    else if (direction_destination == down_right)
    {
        init_best_array(down,left_,right_,up) ;
    }

    // middle vertical

    else if (player_x == dest_x && direction_destination == middle_vertical)
    {
        if (player_y > dest_y) // if the destination is on the left
        {
            init_best_array(left_,down,up,right_) ;
        }

        else (player_y < dest_y) // if the destination is on the right
        {
            init_best_array(right_,down,up,left_) ;
        }
    }

    else if (player_y == dest_y && direction_destination == middle_vertical)
    {
        if (dest_x < user_x) // if the destination is down
        {
            init_best_array(down,right_,left_,up) ;
        }

        else if (dest_x > user_x) // if the destination is up
        {
            init_best_array(up,right_,left_,down) ;
        }
    }

    else if (direction_destination == middle_vertical)
    {
        if (dest_x < user_x) // if the destination is down
        {
            if (player_y > dest_y)  // if the destination is on the left
            {
                init_best_array(left_,down,up,right_) ;
            }

            else if (player_y < dest_y)  // if the destination is on the right
            {
                init_best_array(right_,down,up,left_) ;
            }
        }

        else if (dest_x > user_x) // if the destination is up
        {
            if (player_y > dest_y)  // if the destination is on the left
            {
                init_best_array(left_,up,down,right_) ;
            }

            else if (player_y < dest_y)  // if the destination is on the right
            {
                init_best_array(right_,up,down,left_) ;
            }
        }
    }

    return best_move_array ;
}

int init_best_array(int a, int b, int c, int d)
{
    best_move_array[0] = a ;
    best_move_array[1] = b ;
    best_move_array[2] = c ;
    best_move_array[3] = d ;
}

int random_move(int choice_1, int choice_2)
{
    int random_move = rand % 1 ;

    if (random_move == 0)
    {
        return choice_1 ;
    }

    else
    {
        return choice_2 ;
    }
}

void error()
{
    getch() ;
    cout << "ERROR!" ;
}

void scrclr()
{
    system("@cls") ;
}
