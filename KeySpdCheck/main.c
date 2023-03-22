#include <stdio.h>
#include "RandChar.h"
#include <math.h>

int main()
{
	key_press_individual_char() ; 
	
	return 0 ; 
}

void scrclr() 
{
	system("@cls") ; 
}

int key_press_individual_char() 
{
	char char_to_press ; 
	int loop_times ; 
	int rand_int ;
	char char_pressed ;
	int fails = 0 ;
	int wins = 0 ;
	
	printf("Loop times : ") ;
	scanf("%d",&loop_times) ; 
	scrclr() ; 
	
	for(int i = 0 ; i < loop_times ; ++i)
	{
		printf("Wins = %d            Fails = %d",wins,fails) ; 
		rand_int = rand() % 5 ; 
		char_to_press = rand_char(rand_int) ;
		printf("\nPress the %c key : ",char_to_press) ; 
		char_pressed = getch() ; 
		
		if(char_pressed == char_to_press)
		{
			wins++ ;
			scrclr() ;
		}
		
		else
		{
			fails++ ;
			scrclr() ; 
		}
	}
}


int rand_char(int rand_int_char, int return_type) 
{
	char return_char ; 
	
	switch(rand_int_char) 
	{
		case 0 : 
		{
			return_char = 'a' ;
			
			break ; 
		}
		
		case 1 : 
		{
			return_char = 'a' ;
			
			break ; 
		}
		
		case 2 : 
		{
			return_char = 'b' ;
			
			break ; 
		}
		
		case 3 : 
		{
			return_char = 'c' ;

			break ; 
		}
		
		case 4 : 
		{
			return_char = 'd' ;

			break ; 
		}
		
		case 5 : 
		{
			return_char = 'e' ;

			break ; 
		}
		
		case 6 : 
		{
			return_char = 'f' ;
			
			break ; 
		}
		
		case 7 : 
		{
			return_char = 'g' ;
			
			break ; 
		}
		
		case 8 : 
		{
			return_char = 'h' ;
			
			break ; 
		}
		
		case 9 : 
		{
			return_char = 'i' ;
			
			break ; 
		}
		
		case 10 : 
		{
			return_char = 'j' ;
			
			break ; 
		}
		
		case 11 : 
		{
			return_char = 'k' ;
			
			break ; 
		}
		
		case 12 : 
		{
			return_char = 'l' ;
			
			break ; 
		}
		
		case 13 : 
		{
			return_char = 'm' ;
			
			break ; 
		}
		
		case 14 : 
		{
			return_char = 'n' ;
			
			break ; 
		}
		
		case 15 : 
		{
			return_char = 'o' ;
			
			break ; 
		}
		
		case 16 : 
		{
			return_char = 'p' ;
			
			break ; 
		}
		
		case 17 : 
		{
			return_char = 'q' ;
			
			break ; 
		}
		
		case 18 : 
		{
			return_char = 'r' ;
			
			break ; 
		}
		
		case 19 : 
		{
			return_char = 's' ;
			
			break ; 
		}
		
		case 20 : 
		{
			return_char = 't' ;
			
			break ; 
		}
		
		case 21 : 
		{
			return_char = 'u' ;
			
			break ; 
		}
		
		case 22 : 
		{
			return_char = 'v' ;
			
			break ; 
		}
		
		case 23 : 
		{
			return_char = 'w' ;
			
			break ; 
		}
		
		case 24 : 
		{
			return_char = 'x' ;
			
			break ; 
		}
		
		case 25 : 
		{
			return_char = 'y' ;
			
			break ; 
		}
		
		case 26 : 
		{
			return_char = 'z' ;
			
			break ; 
		}
		
		default : 
		{
			return 0 ; 
			
			break ; 
		}
	}
	
	if(return_type == 1)
	{
		return_char = toupper(return_char) ; 
	}
		
	return return_char ;
	return return_char ;
}
