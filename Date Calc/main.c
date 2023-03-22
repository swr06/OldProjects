/*
	Features to be added 
	 * Can Adjust date format and THE PROGRAM WILL STORE THIS IN A SOMEWHAT ENCRYPTED FILE
	 * Can Adjust how it will calculate the dates (i.e. in days or month or years) 
	 * show century
*/

#include <stdio.h> 

struct date
{
	int day ; 
	int month ; 
	int year ;
} ;

///GLOBALS
 

int main()
{
	int total ;
	struct date date1 ; 
	struct date date2 ;
	char c[4] ;
	int maxdays ; 

	printf("Welcome to date calculator v01") ; 
	printf("\nFormat : DD/MM/YYYY") ;
	printf("\nEnter the first date separated with space and with the above format : \n") ; 
	scanf("%d",&date1.day) ; 
	scanf("%d",&date1.month) ; 
	scanf("%d",&date1.year) ; 
	
	///DATE 1 checks
	if (date1.month > 12)
	{
		printf("\nERROR") ; 
		getch() ; 
		
		return 0 ;
	}
	
	if (date1.year > 10000)
	{
		printf("\nERROR") ; 
		getch() ; 
		
		return 0 ;
	}
	
	if (date1.month == 1)
	{
		if(date1.day > 31)
		{
			printf("\nERROR") ;
			getch() ;
			
			return 0 ; 
		}
	}
	
	if (date1.month == 2)
	{
		if (date1.year % 4 == 0)
		{
			if (date1.day > 29)
			{
				printf("\nERROR") ;
				getch() ; 
				
				return 0 ;
			}
		}
		
		else
		{
			if (date1.day > 28)
			{
				printf("\nERROR") ; 
				getch() ;
				
				return 0 ; 
			}
		}
	}
	
	if (date1.month == 3)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
			getch() ; 
			
			return 0 ;
		}
	}
	
	if (date1.month == 4)
	{
		if (date1.day > 30)
		{
			printf("\nERROR") ;
			getch() ; 
			
			return 0 ; 
		}
	}
	
	if (date1.month == 5)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
			getch() ;
			
			return 0 ;
		}
	}
	
	if (date1.month == 6)
	{
		if (date1.day > 30)
		{
			printf("\nERROR") ;
			getch() ; 
			
			return 0 ;
		}
	}
	
	if (date1.month == 7)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date1.month == 8)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date1.month == 9)
	{
		if (date1.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date1.month == 10)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date1.month == 11)
	{
		if (date1.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date1.month == 12)
	{
		if (date1.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	printf("\nEnter the second date separated with space and with the above format : \n") ; 
	scanf("%d",&date2.day) ; 
	scanf("%d",&date2.month) ; 
	scanf("%d",&date2.year) ; 
	
	///Date 2 checks
	if (date2.month > 12)
	{
		printf("\nERROR") ; 
	}
	
	if (date2.year > 10000)
	{
		printf("\nERROR") ; 
	}
	
	if (date2.month == 1)
	{
		if(date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 2)
	{
		if (date2.year % 4 == 0)
		{
			if (date2.day > 29)
			{
				printf("\nERROR") ;
			}
		}
		
		else
		{
			if (date2.day > 28)
			{
				printf("\nERROR") ; 
			}
		}
	}
	
	if (date2.month == 3)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 4)
	{
		if (date2.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 5)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 6)
	{
		if (date2.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 7)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 8)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 9)
	{
		if (date2.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 10)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 11)
	{
		if (date2.day > 30)
		{
			printf("\nERROR") ;
		}
	}
	
	if (date2.month == 12)
	{
		if (date2.day > 31)
		{
			printf("\nERROR") ;
		}
	}
	
	/// MATH
	
	total = 0 ; 
	
	for (int i = 0 ; i < date2.year - date1.year ; i++)
	{
		if (date2.year % 4 == 0)
		{
			total = total + 366 ; 
		}
		
		else 
		{
			total = total + 365 ; 
		}
	}
	
	//Month and day math
	
	//#checks XD
	
	if (date1.month == 1)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 2)
	{
		if (date1.year % 4 == 0)
		{
			maxdays = 29 ; 
		}
		
		else
		{
			maxdays = 28 ; 
		}
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 3)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 4)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 5)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}

	else if (date1.month == 6)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 7)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 8)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 9)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 10)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 11)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}
	
	else if (date1.month == 12)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date1.day ;
		total = total + maxdays ;
	}

	//Date 2 
	
	if (date2.month == 1)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 2)
	{
		if (date2.year % 4 == 0)
		{
			maxdays = 29 ; 
		}
		
		else
		{
			maxdays = 28 ; 
		}
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 3)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 4)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 5)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}

	else if (date2.month == 6)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 7)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 8)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 9)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 10)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 11)
	{
		maxdays = 30 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	else if (date2.month == 12)
	{
		maxdays = 31 ; 
		maxdays = maxdays - date2.day ;
		total = total + maxdays ;
	}
	
	printf("\nTOTAL : %d",total - maxdays) ;
}
