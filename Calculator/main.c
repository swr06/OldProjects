/*Samuel Rasquinha*/

/*This is calculator V06 Beta*/
/*Features to add*/
/*
 * Date calculation
 * Basic equation solver
 * decimal arithmetic
 * upgrade addition, subtraction, multiplication and division to decimal based
 * basic license check
*/


/*WAY OF WORKING
 * ENTER THE LICENSE
 * ASK IF WANT TO CREATE USER
 * IF SO THEN DO IF NOT DONT
 * CREATE A LICENSE FILE
 * VERIFY
 * REMEMBER
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <float.h>
#include <math.h>

#define BAD_INPUT 1
#define GOOD_INPUT 0

#define BOOL short

#define TRUE  1
#define FALSE 0
#define NULL  0
#define true  1
#define false 0
#define null  0

#define BUFFER1SIZE 32

#define ADD         1
#define SUBTRACT    2
#define MULTIPLY    3
#define DIVIDE      4
#define POWER       5
#define HCF         6
#define CTF         7
#define FTC         8
#define DIVCHK      9
#define LEAPYEAR    10
#define MASS        11
#define PERIMETER   12
#define AREA        13
#define TABGEN      14
#define CURR        15
#define APPROX      16
#define MATRIX      17
#define NUMGEN      18
#define NEXT1       19
#define QUIT        0

/// MENU 1 :

#define MENU        1
#define ROUND       2
#define NEGTOPOS    3
#define SQRT        4
#define RANDOM		5
#define PRIMECHK	6
#define ASCEND      7
#define FRACTODEC   8
#define DECTOFRAC   9
#define REDUCE      10
#define PERCENTAGE  11
#define FRACARITH	12
#define PROP_PROG   13
#define DIST_CALC   14
#define INV_ARRAY   15
#define SECOND      50

#define array_max_elements 10

void UserInput() ;
void DisplayHeader() ;
void GetTheOperands() ;
void scrclr() ;
int Hcf(int num1, int num2) ;
float Divide(int FirstNum, int SecondNum) ;
//double Power(double FirstNum, double SecondNum) ;
int ctf(int celsius) ;
int ftc(int Fahrenheit) ;
BOOL check() ;

int calc, num1, num2, ans, sidea, sideb, sidec, opr ;
extern int intense_random = 5 ;
int num, tab, pass, table, atab ;
float fAns, fNum1, fNum2 ;
double dAns, dNum1, dNum2 ;
char userwish[32] ;
char prosname[32] ;
char string[16] ;
int numbers[1024] ;

BOOL flag = FALSE ;
int op,op1, op2, op3, op4 ;
char name0 [32] ;
char name1 [32] ;
char name2 [32] ;
char name3 [32] ;
char name4 [32] ;
char name5 [32] ;
char name6 [32] ;
float cans, cur ;
/*ren*/float reu, rep, rei, rus ;
/*inr*/float ius, ieu, ipn, ire ;
/*usd*/float uin, ueu, upn, ure ;
/*pnd*/float pus, peu, pin, pre ;
/*eur*/float eus, ein, epn, ere ;
/*update curr*/int uop, uop1, uop2, uop3 ;
float *up ;

/*approximate*/ int aop, aop1, aop2 ;
double floatnum, fp, fq, ip, iq ;
int aint ;

/*matrix*/ int rows, columns, mop, mop1, mop2, matrixans, matopr ;
int elementval = 0 ;
int elenum = 0 ;
int singlenum ;

/// MENU 1 :

int globalusrchk = FALSE ;
int m1op ;
int checkch ;

/// FRACTIONS :

int flcm ;
int f_nume_1 ;
int f_denom_1 ;
int f_nume_2 ;
int f_denom_2 ;
int f_ans_nume ;
int f_ans_denom ;
int f_converted_whole ;
int f_converted_nume ;
int f_converted_denom ;
int f_greater ;
int f_lesser ;

/// MATRIX ADVANCED
/*****************/

///Array Properties

///Integer group properties
int int_group_ascend[array_max_elements] ;
int int_group_decend[array_max_elements] ;

//Fraction group properties
int frac_group_ascend_nume[array_max_elements] ; // DONE
int frac_group_ascend_denom[array_max_elements] ; // DONE
int frac_group_decend_nume[array_max_elements] ;
int frac_group_decend_denom[array_max_elements] ;

int main()
{
    invert_array_UI() ;

    exit(0) ;
}

BOOL check()
{
    BOOL bRetVal = FALSE ;

    scrclr() ;
    printf("You have selected %s (y/n) : ",prosname) ;
    scanf("%s",&userwish) ;

    if (!strcmp(userwish,"y"))
    {
        bRetVal = TRUE ;
    }

    else if (!strcmp(userwish,"Y"))
    {
        bRetVal = TRUE ;
    }

    return bRetVal ;
}

//START
/*
int licenseverify()
{
	char filename[32] ;
	FILE *license ;
	char contents[256] ;
	char key[8] ;

	strcpy(key,"7") ;
	strcpy(filename,"license.txt") ;

	if (file_exists(filename) == 0)
	{
		license = fopen(filename,"w+") ;
	}

	if (file_exists(filename) == 1)
	{
		fgets(contents,sizeof (contents), license) ;
	}

	if(stringsearch(key,contents) == 0)
	{
		printf("KEY INVALID") ;

		return 0 ;
	}

	else
	{
		printf("KEY VALID") ;

		return 1 ;
	}
}

int licenseverifychild()
{

}

int stringsearch(char tosearch[20], char stringtosearch[512])
{
	char *sresult ;
	short returnvalue ;

	sresult = strstr(stringtosearch, tosearch);
	returnvalue = strcmp(tosearch,sresult) ;

	return returnvalue ;
}

int file_exists(char efilename[32])
{
	FILE *lfptr ;
	lfptr = fopen(efilename,"r") ;

	if (lfptr == NULL)
	{
		//fileexists
		fclose(efilename) ;

		return 1 ;
	}

	else
	{
		///file does not exist
		return 0 ;
	}
}
*/
// END

int userverify()
{
    uop3 = 0 ;
    char username[BUFFER1SIZE] ;
    char password[BUFFER1SIZE] ;
    char c  ;
    int i = 0 ;
    int ij = 0 ;

    resetcur() ;

    printf("Type the username : ") ;
    scanf("%s",&username) ;

    if(!strcmp(username,"test"))
    {
        scrclr() ;
        UserInput() ;
        ProcessInputs() ;
    }

    if(!strcmp(username,"Samuel"))
    {
        flag = TRUE ;
    }

    else
    {
        flag = FALSE ;
        //printf("Wrong Username") ;
    }

    if (flag == TRUE)
    {
        printf("Type the password : ") ;

        while ((c = getch())!= '\r')
        {
            password[i] = c ;
            printf("") ;

            if (i > BUFFER1SIZE)
            {
                i = 0 ;
            }

            if (c == '\b')
            {
                i -- ;
            }

            else
            {
                i ++ ;
            }
        }

        password[i] = '\0' ;

        if (!strcmp(password,"password"))
        {
            scrclr() ;
            UserInput() ;
            ProcessInputs() ;
        }

        else
        {
            printf("\nWrong password") ;
            return 0 ;
        }
    }
}

BOOL quitcheck()
{
    BOOL boolretvalue = TRUE ;
    printf("Do you really want to quit? y/n : ") ;
    scanf("%s",&userwish) ;

    if (!strcmp(userwish,"n"))
    {
        boolretvalue = FALSE ;
    }

    else if (!strcmp(userwish,"N"))
    {
        boolretvalue = FALSE ;
    }

    return boolretvalue ;
}

void UserInput()
{
    int UserInput = BAD_INPUT ;

    while (UserInput == BAD_INPUT)
    {
        UserInput = GOOD_INPUT ;
        DisplayHeader() ;
        scanf("%d",&calc) ;
        scrclr() ;

        switch (calc)
        {
        case QUIT :
        {
            if (quitcheck() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            else
            {
                exit(0) ;
            }

            break ;
        }

        case ADD :
        {
            strcpy(prosname,"addition") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            GetTheOperands() ;

            break ;
        }

        case SUBTRACT :
        {
            strcpy(prosname,"subtraction") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            GetTheOperands() ;

            break ;
        }

        case MULTIPLY :
        {
            strcpy(prosname,"multiplication") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            GetTheOperands() ;

            break ;
        }

        case DIVIDE :
        {
            strcpy(prosname,"division") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            GetTheOperands() ;

            break ;
        }

        case POWER :
        {
            strcpy(prosname,"power") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case HCF :
        {
            strcpy(prosname,"HCF") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            GetTheOperands() ;

            break ;
        }

        case CTF :
        {
            strcpy(prosname,"celsius to fahrenheit calculation") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case FTC :
        {
            strcpy(prosname,"celsius to fahrenheit calculation") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case DIVCHK :
        {
            strcpy(prosname,"Divisibility check") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case LEAPYEAR :
        {
            strcpy(prosname,"leap year check") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case MASS :
        {
            strcpy(prosname,"mass calculation") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case PERIMETER :
        {
            strcpy(prosname,"perimeter calculation") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case AREA :
        {
            strcpy(prosname,"area calculation") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case TABGEN :
        {
            strcpy(prosname,"tables generator") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case CURR :
        {
            strcpy(prosname,"currency convertor") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }


        case APPROX :
        {
            strcpy(prosname,"approx") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case MATRIX :
        {
            strcpy(prosname,"matrix operations") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case NUMGEN :
        {
            strcpy(prosname,"number generator") ;

            if (check() == FALSE)
            {
                UserInput = BAD_INPUT ;
                scrclr() ;
            }

            break ;
        }

        case NEXT1 :
        {
            menu1displayheader() ;

            break ;
        }

        default :
        {
            UserInput = BAD_INPUT ;

            break ;
        }
        }
    }

}

void DisplayHeader()
{
    printf("*WELCOME TO BASIC CALCULATOR VERSION 06*");
    printf("\nType %d for Addition",ADD) ;
    printf("\nType %d for Subtraction",SUBTRACT) ;
    printf("\nType %d for Multiplication",MULTIPLY) ;
    printf("\nType %d for Division",DIVIDE) ;
    printf("\nType %d for Power",POWER) ;
    printf("\nType %d for HCF",HCF) ;
    printf("\nType %d for Celsius to Fahrenheit",CTF) ;
    printf("\nType %d for Fahrenheit to Celsius",FTC) ;
    printf("\nType %d for Divisibility check",DIVCHK) ;
    printf("\nType %d to check whether a year IS a leap year or NOT",LEAPYEAR) ;
    printf("\nType %d for mass calculation (ex: addition of 2 or more numbers)",MASS) ;
    printf("\nType %d to find the perimeter of 3 shapes",PERIMETER) ;
    printf("\nType %d to find the area of 4 shapes",AREA) ;
    printf("\nType %d to launch the tables generator",TABGEN) ;
    printf("\nType %d to launch the currency convertor",CURR) ;
    printf("\nType %d to launch the approx program",APPROX) ;
    printf("\nType %d to launch matrix operations",MATRIX) ;
    printf("\nType %d to generate a kind of number",NUMGEN) ;
    printf("\nType %d to Goto the NEXT menu",NEXT1) ;
    printf("\nType 0 to EXIT") ;
    printf("\nOPERATION : ") ;
}

void GetTheOperands()
{
    printf("\nType the first number : ") ;
    scanf("%d",&num1) ;
    printf("\nType the second number : ") ;
    scanf("%d",&num2) ;
}

void scrclr()
{
    system("@cls") ;
}

void ProcessInputs()
{
    int ans ;
    int rem ;

    switch (calc)
    {
    case ADD :
    {
        ans = Add(num1,num2) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case SUBTRACT :
    {
        ans = Sub(num1,num2) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case MULTIPLY :
    {
        ans = Multiply(num1,num2) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case DIVIDE :
    {
        fAns = Divide(num1,num2) ;
        printf("The Quotient is : %f", fAns) ;

        break ;
    }

    case CTF :
    {
        printf("\nCelsius : ") ;
        scanf("%d",&num1) ;
        ans = ctf(num1) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case FTC :
    {
        printf("\nFahrenheit : ") ;
        scanf("%d",&num1) ;
        ans = ftc(num1) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case POWER:
    {
        Power() ;

        break ;
    }

    case HCF :
    {
        ans = Hcf(num1,num2) ;
        printf("\nThe answer is : %d",ans) ;

        break ;
    }

    case DIVCHK :
    {
        divichk() ;

        break ;
    }

    case LEAPYEAR :
    {
        leapyear() ;

        break ;
    }

    case MASS :
    {
        masscheck() ;

        break ;
    }

    case PERIMETER :
    {
        perimeter() ;

        break ;
    }

    case AREA :
    {
        area() ;

        break ;
    }

    case TABGEN :
    {
        tabexe() ;

        break ;
    }

    case CURR :
    {
        currencyexe() ;

        break ;
    }

    case APPROX :
    {
        printdoublegen() ;

        break ;
    }

    case MATRIX :
    {
        matrixprint() ;

        break ;
    }

    case NUMGEN :
    {
        numgenprint() ;

        break ;
    }
    }


    getch() ;
    continuechk() ;
    flag = 5 ;
    getch() ;

    return 0 ;
}

int area()
{
    scrclr() ;
    printf("Type 1 to find the area of a square") ;
    printf("\nType 2 to find the area of a rectangle") ;
    printf("\nType 3 to find the area of a triangle") ;
    printf("\nType 4 to find the area of a circle") ;
    printf("\nOperation : ") ;
    scanf("%d",&opr) ;

    switch (opr)
    {
    case 1 :
    {
        printf("\nYou have selected area of a square") ;
        areasq() ;

        break ;
    }

    case 2 :
    {
        printf("\nYou have selected area of a rectangle") ;
        arearec() ;

        break ;
    }

    case 3 :
    {
        printf("\nYou have selected area of a triangle") ;
        areatri() ;

        break ;
    }

    case 4 :
    {
        printf("\nYou have selected area of a circle") ;
        areacir() ;

        break ;
    }

    default :
    {
        printf("\nBAD OPERATION") ;

        return 0 ;
        break ;
    }
    }
}

int areasq()
{
    scrclr() ;
    printf("Enter the length of the square : ") ;
    scanf("%d",&sidea) ;
    ans = sidea * sidea ;
    printf("The area of the square = %d",ans) ;
}

int arearec()
{
    scrclr() ;
    printf("Enter the length of the rectangle : ") ;
    scanf("%d",&sidea) ;
    printf("\nEnter the breadth of the rectangle : ") ;
    scanf("%d",&sideb) ;
    ans = sidea * sideb ;
    printf("The area of the rectangle = %d",ans) ;
}

void areatri()
{
    float height,base,faans ;

    scrclr() ;
    printf("Enter the height of the triangle : ") ;
    scanf("%f",&height) ;
    printf("\nEnter the base of the triangle : ") ;
    scanf("%f",&base) ;
    faans = 0.50 * height * base ;
    printf("\nArea of a triangle is : %f",faans) ;
}

void areacir()
{
    float radius, faans ;
    const float pi = 3.14159265354 ;

    scrclr() ;
    printf("Enter the radius of the circle : ") ;
    scanf("%f",&radius) ;
    faans = pi * radius * radius ;
    printf("\nArea of a circle is : %f",faans) ;
}

int perimeter()
{
    scrclr() ;
    printf("Type 1 to find the perimeter of a square") ;
    printf("\nType 2 to find the perimeter of a rectangle") ;
    printf("\nType 3 to find the perimeter of a triangle") ;
    printf("\nOperation : ") ;
    scanf("%d",&opr) ;

    switch (opr)

    {
    case 1 :
    {
        printf("\nYou have selected perimeter of a square") ;
        perimetersq() ;

        break ;
    }

    case 2 :
    {
        printf("\nYou have selected perimeter of a rectangle") ;
        perimeterrec() ;

        break ;
    }

    case 3 :
    {
        printf("\nYou have selected perimeter of a triangle") ;
        perimetertri() ;

        break ;
    }

    default :
    {
        printf("BAD INPUT") ;

        return 0 ;
        break ;
    }
    }
}

int perimetersq()
{
    printf("\nEnter the length of the square : ") ;
    scanf("%d",&sidea) ;
    ans = sidea * 4 ;
    printf("\nThe perimeter of the square is : %d ",ans) ;
}

int perimeterrec()
{
    printf("\nEnter the length of the rectangle : ") ;
    scanf("%d",&sidea) ;
    printf("\nEnter the breadth of the rectangle : ") ;
    scanf("%d",&sideb) ;
    ans = sidea + sideb + sidea + sideb ;
    printf("\nThe perimeter of the rectangle is : %d ",ans) ;
}

int perimetertri()
{
    printf("\nEnter the length of one side of the triangle : ") ;
    scanf("%d",&sidea) ;
    printf("\nEnter the length of the second side of the triangle : ") ;
    scanf("%d",&sideb) ;
    printf("\nEnter the length of the third side of the triangle : ") ;
    scanf("%d",&sidec) ;
    ans = sidea + sideb + sidec ;
    printf("\nThe perimeter of the triangle is %d ",ans) ;
}

int divichk(int num1, int div)
{
    int ans ;

    printf("Enter the number : ") ;
    scanf("%d",&num1) ;
    printf("Enter the divisor : ") ;
    scanf("%d",&div) ;
    ans = num1 % div ;

    if (ans == 0)
    {
        printf("The number IS divisible by %d",div) ;
    }

    else if (ans != 0)
    {
        printf("The number is NOT divisible by %d",div) ;
    }
}

int leapyear(int year)
{
    printf("Type the year : ") ;
    scanf("%d",&year) ;

    if (year % 4 == 0)
    {
        printf("it IS a leap year") ;
    }
    else
    {
        printf("it IS NOT a leap year") ;
    }

}

void masscheck()
{
    int masop = 0 ;
    scrclr() ;
    printf("Type 1 for mass addition") ;
    printf("\nType 2 for mass subtraction") ;
    printf("\nOperation : ") ;
    scanf("%d",&masop) ;

    if (masop == 1)
    {
        masscalcadd() ;
    }

    else if (masop == 2)
    {
        masscalcsub() ;
    }

    if (masop <=! 2)
    {
        printf("\nBAD OPERATION !") ;
        return 0 ;
    }
}

int masscalcadd()
{
    strcpy(string,"add") ;
    massprint() ;
    ans = 0 ;

    for (int j = 0 ; j < num1 ; j++)
    {
        ans = ans + numbers[j] ;
    }

    printf("The answer is : %d",ans) ;
    getch() ;
    return 0 ;
}

int masscalcsub()
{
    strcpy(string,"subtraction") ;
    massprint() ;
    ans = 0 ;

    for (int j = 0 ; j < num1 ; j++)
    {
        ans = ans - numbers[j] ;
    }

    printf("The answer is : %d",ans) ;
    getch() ;
    return 0 ;
}

void massprint()
{
    printf("Type the numbers you want to %s : ",string) ;
    scanf("%d",&num1) ;

    for (int i = 0 ; i < num1 ; i++)
    {
        printf("Type number %d : ", i) ;
        scanf("%d",&numbers[i]) ;
    }
}

int Hcf(int num1, int num2)
{
    int nRemainder, nAnswer ;

    if (num1 < num2)
    {
        int temp ;

        temp = num1 ;
        num1 = num2 ;
        num2 = temp ;
    }

    nRemainder = 1 ;

    while (nRemainder != 0)
    {
        nRemainder = num1 % num2 ;
        num1 = num2 ;
        num2 = nRemainder ;
    }

    return num1 ;
}

int Add(int FirstNum, int SecondNum)
{
    int ans ;

    ans = FirstNum + SecondNum ;

    return ans ;
}

int Sub(int FirstNum, int SecondNum)
{
    int ans ;

    ans = FirstNum - SecondNum ;

    return ans ;
}

int Multiply(int FirstNum, int SecondNum)
{
    int ans ;

    ans = FirstNum * SecondNum ;

    return ans ;
}

int ctf(int celsius)
{
    int ans ;

    celsius = celsius * 9 ;
    celsius = celsius / 5 ;
    celsius = celsius + 32 ;

    ans = celsius ;

    return ans ;
}

int ftc(int Fahrenheit)
{
    int ans ;

    Fahrenheit = Fahrenheit - 32 ;
    Fahrenheit = Fahrenheit * 5  ;
    Fahrenheit = Fahrenheit / 9  ;

    ans = Fahrenheit ;

    return ans ;
}


float Divide(int FirstNum, int SecondNum)
{
    float ans = 0 ;

    ans = (float) FirstNum / (float) SecondNum ;

    if (FirstNum == 0)
    {
        printf("\nILLEGAL OPERATION") ;

        getch() ;

        return 0 ;
    }

    if (SecondNum == 1)
    {
        printf("\nILLEGAL OPERATION") ;

        getch() ;

        return 0 ;
    }

    return ans ;
}

int Power()
{
    float pownum,localans ;
    int exp ;

    scrclr() ;
    printf("Enter the base : ") ;
    scanf("%f",&pownum) ;
    printf("Enter the exponent : ") ;
    scanf("%d",&exp) ;
    localans = 1;

    for(int i = 0 ; i < exp ; i++)
    {
        localans = localans * pownum ;
    }

    printf("The Power of %f to the power of %d is : %f",pownum,exp,localans) ;
}

int tablogic()
{
    int i = 0 ;

    tab = 0 ;
    pass = 0 ;

    for (i = 0 ; i < atab ; i++)
    {
        pass = pass + 1 ;
        tab = pass ;
        table = num * tab ;

        printf("\n%d x %d = %d",num,tab,table) ;
    }
    printf("\n") ;
    getch() ;
}

int tabuserinput()
{
    scrclr() ;
    printf("Enter the number : ") ;
    scanf("%d",&num) ;
    printf("Enter the amount of tables : ") ;
    scanf("%d",&atab) ;
}

void tabexe()
{
    tabuserinput() ;
    tablogic() ;
}
/// Currency Converter
void curdisplayheader()
{
    char opname[1024] ;

    name0[0] = '\0' ;
    name1[0] = '\0' ;
    name2[0] = '\0' ;
    name3[0] = '\0' ;
    name4[0] = '\0' ;
    name5[0] = '\0' ;
    name6[0] = '\0' ;
    opname[0] = '\0' ;
    strcpy(opname,"USD,EUR,PND,REN") ;
    printf("\nPress 1 to convert from INR to %s",opname) ;
    strcpy(opname,"INR,EUR,PND,REN") ;
    printf("\nPress 2 to convert from USD to %s",opname) ;
    strcpy(opname,"INR,USD,PND,REN") ;
    printf("\nPress 3 to convert from EUR to %s",opname) ;
    strcpy(opname,"INR,USD,EUR,REN") ;
    printf("\nPress 4 to convert from PND to %s",opname) ;
    strcpy(opname,"INR,USD,EUR,PND") ;
    printf("\nPress 5 to convert from REN to %s",opname) ;
    printf("\nPress 10 to update the currency values") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&op) ;
    printsystem() ;
}

int printsystem()
{
    switch(op)
    {
    case 1 :
    {
        strcpy(name0,"INR") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"EUR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        childprintsystem() ;
        ilogic() ;

        break ;
    }

    case 2 :
    {
        strcpy(name0,"USD") ;
        strcpy(name1,"INR") ;
        strcpy(name2,"EUR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        childprintsystem() ;
        ulogic() ;

        break ;
    }

    case 3 :
    {
        strcpy(name0,"EUR") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"INR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        childprintsystem() ;
        elogic() ;

        break ;
    }

    case 4 :
    {
        strcpy(name0,"PND") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"INR") ;
        strcpy(name3,"EUR") ;
        strcpy(name4,"REN") ;
        childprintsystem() ;
        plogic() ;

        break ;
    }

    case 5 :
    {
        strcpy(name0,"REN") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"INR") ;
        strcpy(name3,"EUR") ;
        strcpy(name4,"PND") ;
        childprintsystem() ;
        renlogic() ;

        break ;
    }

    case 10 :
    {
        updatecur() ;

        break ;
    }

    default :
    {
        printf("BAD OPERATION") ;
    }
    }
}

void childprintsystem()
{
    scrclr() ;
    printf("You have selected %s",name0) ;
    printf("\nType 1 to convert %s to %s",name0,name1) ;
    printf("\nType 2 to convert %s to %s",name0,name2) ;
    printf("\nType 3 to convert %s to %s",name0,name3) ;
    printf("\nType 4 to convert %s to %s",name0,name4) ;
    printf("\nOPERATION : ") ;
    scanf("%d",&op1) ;
}

int ilogic()
{
    strcpy(name5,"INR") ;
    switch (op1)
    {
    case 1 :
    {
        strcpy(name6,"USD") ;
        printlogic() ;
        cans = cur / ius ;

        break ;
    }

    case 2 :
    {
        strcpy(name6,"EUR") ;
        printlogic() ;
        cans = cur / ieu ;

        break ;
    }

    case 3 :
    {
        strcpy(name6,"PND") ;
        printlogic() ;
        cans = cur / ipn ;

        break ;
    }

    case 4 :
    {
        strcpy(name6,"REN") ;
        printlogic() ;
        cans = cur / ire ;

        break ;
    }
    }
    printanswer() ;
}

int ulogic()
{
    strcpy(name5,"USD") ;
    switch (op1)
    {
    case 1 :
    {
        strcpy(name6,"INR") ;
        printlogic() ;
        cans = cur * uin ;

        break ;
    }

    case 2 :
    {
        strcpy(name6,"EUR") ;
        printlogic() ;
        cans = cur * ueu ;

        break ;
    }

    case 3 :
    {
        strcpy(name6,"PND") ;
        printlogic() ;
        cans = cur / upn ;

        break ;
    }

    case 4 :
    {
        strcpy(name6,"REN") ;
        printlogic() ;
        cans = cur * ure ;

        break ;
    }
    }
    printanswer() ;
}

int elogic()
{
    strcpy(name5,"EUR") ;
    switch (op1)
    {
    case 1 :
    {
        strcpy(name6,"USD") ;
        printlogic() ;
        cans = cur * eus ;

        break ;
    }

    case 2 :
    {
        strcpy(name6,"INR") ;
        printlogic() ;
        cans = cur * ein ;

        break ;
    }

    case 3 :
    {
        strcpy(name6,"PND") ;
        printlogic() ;
        cans = cur * epn ;

        break ;
    }

    case 4 :
    {
        strcpy(name6,"REN") ;
        printlogic() ;
        cans = cur * ere ;

        break ;
    }
    }
    printanswer() ;
}

int plogic()
{
    strcpy(name5,"PND") ;
    switch (op1)
    {
    case 1 :
    {
        strcpy(name6,"USD") ;
        printlogic() ;
        cans = cur * pus ;

        break ;
    }

    case 2 :
    {
        strcpy(name6,"INR") ;
        printlogic() ;
        cans = cur * pin ;

        break ;
    }

    case 3 :
    {
        strcpy(name6,"EUR") ;
        printlogic() ;
        cans = cur * peu ;

        break ;
    }

    case 4 :
    {
        strcpy(name6,"REN") ;
        printlogic() ;
        cans = cur * pre ;

        break ;
    }
    }
    printanswer() ;
}

int renlogic()
{
    strcpy(name5,"REN") ;
    switch (op1)
    {
    case 1 :
    {
        strcpy(name6,"USD") ;
        printlogic() ;
        cans = cur * rus ;

        break ;
    }

    case 2 :
    {
        strcpy(name6,"INR") ;
        printlogic() ;
        cans = cur * 0.10 ;

        break ;
    }

    case 3 :
    {
        strcpy(name6,"EUR") ;
        printlogic() ;
        cans = cur * reu ;

        break ;
    }

    case 4 :
    {
        strcpy(name6,"PND") ;
        printlogic() ;
        cans = cur * rep ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }
    printanswer() ;
}

void printlogic()
{
    scrclr() ;
    printf("Enter the amount of %s : ",name5) ;
    scanf("%f",&cur) ;
}

void printanswer()
{
    printf("%f %s = %f %s",cur,name5,cans,name6) ;
    printf("\n\n") ;
    getch() ;
}

void currencyexe()
{
    curdisplayheader() ;
}

int resetcur()
{
    ius = 65.03 ;
    ieu = 76.75 ;
    ipn = 85.35 ;
    ire = 09.83 ;
    uin = 65.03 ;
    ueu = 0.848857 ;
    upn = 1.32068120737 ;
    ure = 06.62 ;
    eus = 1.17964313436 ;
    ein = 76.71 ;
    epn = 1.11885258358 ;
    ere = 07.80157 ;
    pus = 1.3189549656 ;
    pin = 85.59 ;
    peu = 1.11895028353 ;
    pre = 08.75 ;
    rus = 0.15 ;
    rei = 0.10 ;
    reu = 7.79 ;
    rep = 08.75 ;
}

int updatecur()
{
    printup() ;
    int curop2 ;

    switch (uop)
    {
    case 1 :
    {
        strcpy(name0,"INR") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"EUR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        uop3 = 1 ;

        break ;
    }

    case 2 :
    {
        strcpy(name0,"USD") ;
        strcpy(name1,"INR") ;
        strcpy(name2,"EUR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        uop3 = 2 ;

        break ;
    }

    case 3 :
    {
        strcpy(name0,"PND") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"EUR") ;
        strcpy(name3,"INR") ;
        strcpy(name4,"REN") ;
        uop3 = 3 ;

        break ;
    }

    case 4 :
    {
        strcpy(name0,"EUR") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"INR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"REN") ;
        uop3 = 4 ;

        break ;
    }

    case 5 :
    {
        strcpy(name0,"REN") ;
        strcpy(name1,"USD") ;
        strcpy(name2,"INR") ;
        strcpy(name3,"PND") ;
        strcpy(name4,"EUR") ;
        uop3 = 5 ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }
    childprintup() ;
    curlogicchildin() ;
    printf("\nType 1 to launch the converter") ;
    printf("\nType 2 to reset the values") ;
    printf("\nOperation : ") ;
    scanf("%d",&uop) ;
    scrclr() ;

    switch (uop)
    {
    case 1 :
    {
        currencyexe() ;

        break ;
    }

    case 2 :
    {
        resetcur() ;
        printf("RESET SUCCESSFUL") ;
        printf("\nType 1 to launch the convertor") ;
        printf("\nType 2 to EXIT") ;
        printf("\nOPERATION : ") ;
        scanf("%d",&curop2) ;

        if (curop2 == 1)
        {
            scrclr() ;
            currencyexe() ;
        }

        else if (curop2 == 2)
        {
            return 0 ;
        }

        else
        {
            printf("\nBAD INPUT\n") ;
            getch() ;

            return 0 ;
        }

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

}

void printup()
{
    scrclr() ;
    printf("Type 1 to change the values of operation INR") ;
    printf("\nType 2 to change the values of operation USD") ;
    printf("\nType 3 to change the values of operation EUR") ;
    printf("\nType 4 to change the values of operation PND") ;
    printf("\nType 5 to change the values of operation REN") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&uop) ;
}

void childprintup()
{
    scrclr() ;
    printf("You have selected %s",name0) ;
    printf("\nType 1 to change the value of %s",name1) ;
    printf("\nType 2 to change the value of %s",name2) ;
    printf("\nType 3 to change the value of %s",name3) ;
    printf("\nType 4 to change the value of %s",name4) ;
    printf("\nOPERATION : ") ;
    scanf("%d",&op1) ;
    uop2 = uop2 + op1 ;
}

int iuplogic()
{
    switch(uop2)
    {
    case 1 :
    {
        up = &ius ;

        break ;
    }

    case 2 :
    {
        up = &ieu ;

        break ;
    }

    case 3 :
    {
        up = &ipn ;

        break ;
    }

    case 4 :
    {
        up = &ire ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

    scanf("%f",up) ;
}

int usuplogic()
{
    switch(uop2)
    {
    case 1 :
    {
        up = &uin ;

        break ;
    }

    case 2 :
    {
        up = &ueu ;

        break ;
    }

    case 3 :
    {
        up = &upn ;

        break ;
    }

    case 4 :
    {
        up = &ure ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

    scanf("%f",up) ;
}

int euuplogic()
{
    switch(uop2)
    {
    case 1 :
    {
        up = &eus ;

        break ;
    }

    case 2 :
    {
        up = &ein ;

        break ;
    }

    case 3 :
    {
        up = &epn ;

        break ;
    }

    case 4 :
    {
        up = &ere ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

    scanf("%f",up) ;
}

int pnduplogic()
{
    switch(uop2)
    {
    case 1 :
    {
        up = &pus ;

        break ;
    }

    case 2 :
    {
        up = &peu ;

        break ;
    }

    case 3 :
    {
        up = &pin ;

        break ;
    }

    case 4 :
    {
        up = &pre ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

    scanf("%f",up) ;
}

int renuplogic()
{
    switch(uop2)
    {
    case 1 :
    {
        up = &reu ;

        break ;
    }

    case 2 :
    {
        up = &rei ;

        break ;
    }

    case 3 :
    {
        up = &rep ;

        break ;
    }

    case 4 :
    {
        up = &reu ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }

    scanf("%f",up) ;
}

int curlogicchildin()
{
    scrclr() ;
    printf("Enter the value : ") ;

    switch (uop3)
    {
    case 1 :
    {
        iuplogic() ;

        break ;
    }

    case 2 :
    {
        usuplogic() ;

        break ;
    }

    case 3 :
    {
        euuplogic() ;

        break ;
    }

    case 4 :
    {
        pnduplogic() ;

        break ;
    }

    case 5 :
    {
        renuplogic() ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT!") ;

        return 0 ;
        break ;
    }
    }
}
/// PI GEN
int printdoublegen()
{
    scrclr() ;
    printf("This program will generate an approximate of a number") ;
    printf("\nType 1 to find an approximate of an integer") ;
    printf("\nType 2 to find an approximate of a decimal number") ;
    printf("\nType 10 to find approximates of existing values (ex.pi)") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&aop) ;

    switch (aop)
    {
    case 1 :
    {
        scrclr() ;
        printf("Enter the integer : ") ;
        scanf("%d",&aint) ;
        printf("\nEnter an approx numerator : ") ;
        scanf("%f",&ip) ;
        printf("\nEnter an approx denominator : ") ;
        scanf("%f",&iq) ;
        integergen() ;

        break ;
    }

    case 2 :
    {
        scrclr() ;
        printf("Enter the decimal point number (FLOAT) : ") ;
        scanf("%f",&floatnum) ;
        printf("\nEnter an approx numerator : ") ;
        scanf("%f",&fp) ;
        printf("\nEnter an approx denominator : ") ;
        scanf("%f",&fq) ;
        floatdoublegen() ;

        break ;
    }

    case 10 :
    {
        scrclr() ;
        printf("Type 1 for PI by Archimedes") ;
        printf("\nOPERATION : ") ;
        scanf("%d",&aop1) ;

        if (aop1 == 1)
        {
            floatnum = 3.14159265354 ;
            fp = 22 ;
            fq = 7 ;
            floatdoublegen() ;
        }

        else
        {
            printf("\nBAD OPERATION") ;
            return 0 ;
        }

        break ;
    }

    default :
    {
        printf("\nBAD OPERATION") ;
        getch() ;
        scrclr() ;

        return 0 ;
        break ;
    }
    }
}

int floatdoublegen()
{
    float error, diff, p,q,ans,pi ;
    int nume, denom, fracs ;
    long cycles = 0 ;

    pi = 3.14159265354 ;
    error = pi ;
    p = 22 ;
    q = 7 ;
    fracs = 0 ;

    while (fracs < 5)
    {
        cycles ++ ;
        ans = p / q ;

        diff = (ans - pi) ;

        if (diff < 0)
        {
            diff = diff * (-1) ;
        }

        if (diff < error)
        {
            error = diff ;
            nume = (int) p ;
            denom = (int) q ;
            printf("\nThe better fraction of %f is %d / %d and error is %f",pi,nume,denom,error,cycles) ;
            fracs ++ ;
        }

        if (ans >= pi)
        {
            q++ ;
        }

        else
        {
            p++ ;
        }
    }
}


int integergen()
{
    int error, diff, p,q,ans ;
    int nume, denom, fracs ;

    error = aint ;
    p = ip ;
    q = iq ;
    fracs = 0 ;

    while (fracs < 5)
    {
        ans = p / q ;

        diff = (ans - aint) ;

        if (diff < 0)
        {
            diff = diff * (-1) ;
        }

        if (diff < error)
        {
            error = diff ;
            nume = (int) p ;
            denom = (int) q ;
            printf("\nThe better fraction of %d is %d / %d ",aint,nume,denom) ;
            fracs ++ ;
        }

        if (ans >= aint)
        {
            q++ ;
        }

        else
        {
            p++ ;
        }
    }
}
/// END
int matrix()
{
    scrclr() ;
    matrixprint() ;
}

int matrixprint()
{
    matrixans = 0 ;
    printf("Enter the amount of ROWS : ") ;
    scanf("%d",&rows) ;
    printf("\nEnter the amount of COLUMNS : ") ;
    scanf("%d",&columns) ;
    scrclr() ;
    printf("Type 1 to assign the values to the matrix(1,2,3 etc.)") ;
    printf("\nType 2 to assign one value to the whole matrix") ;
    printf("\nType 3 to assign a particular to each element of a matrix") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&mop) ;
    mop1 = 0 ;
    mop1 = mop1 + mop ;
    scrclr() ;
    printf("Type 1 to find the sum of all the diagonal numbers in a matrix") ;
    printf("\nType 2 to find the sum of the whole matrix") ;
    printf("\nType 3 to set every number divisible by *NUMBER* to *NUMBER") ;
    printf("\nType 4 to find the sum of all the ODD numbers") ;
    printf("\nType 5 to find the sum of all the EVEN numbers") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&matopr) ;
    matuser() ;
}

void matuser()
{
    scrclr() ;

    switch (matopr)
    {
    case 1 :
    {
        matsumdiag() ;

        break ;
    }

    case 2 :
    {
        SumMatrix() ;

        break ;
    }

    case 3 :
    {
        matrixdivto() ;

        break ;
    }

    case 4 :
    {
        SumOddNums() ;

        break ;
    }

    case 5 :
    {
        SumEvenNums() ;

        break ;
    }

    default :
    {
        printf("\nBAD OPERATION") ;
        getch() ;

        return 0 ;
        break ;
    }
    }
}

int matsumdiag()
{
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < columns ; j++)
        {
            if (i == j)
            {
                ans = ans + matrix[i][j] ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

    printf("\nThe sum of the diagonal numbers is : %d",ans) ;
}

int matrixdivto()
{
    int div,num ;

    scrclr() ;
    printf("Every number divisible by : ") ;
    scanf("%d",&div) ;
    printf("\nBecomes : ") ;
    scanf("%d",&num) ;
    // logic
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < columns ; j++)
        {
            if (matrix[i][j] % div == 0)
            {
                matrix[i][j] = num ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }
}

int MatrixTemplate()
{
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }
}

int SumOddNums()
{
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < columns ; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                matrix[i][j] = 0 ;
            }
            ans = ans + matrix[i][j] ;
        }
    }

    printf("\nThe sum of all the odd numbers is : %d",ans) ;
}

int SumEvenNums()
{
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < columns ; j++)
        {
            if (matrix[i][j] % 2 == 1)
            {
                matrix[i][j] = 0 ;
            }
            ans = ans + matrix[i][j] ;
        }
    }

    printf("\nThe sum of all the even numbers is : %d",ans) ;
}

int SumMatrix()
{
    int matrix[rows][columns] ;

    if (mop1 == 1)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = (i * columns) + j ;
            }
        }
    }

    if (mop1 == 2)
    {
        printf("\nEnter the number : ") ;
        scanf("%d",&singlenum) ;

        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                matrix[i][j] = singlenum ;
            }
        }
    }

    if (mop1 == 3)
    {
        for (int i = 0 ; i < rows ; i++)
        {
            for (int j = 0 ; j < columns ; j++)
            {
                elenum++ ;
                printf("Enter the value of element %d : ",elenum) ;
                scanf("%d",&elementval) ;
                matrix[i][j] = elementval ;
            }
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        printf("\n ") ;

        for (int j = 0 ; j < columns ; j++)
        {
            printf("%d ",matrix[i][j]) ;
        }
    }

    for (int i = 0 ; i < rows ; i++)
    {
        for (int j = 0 ; j < columns ; j++)
        {
            ans = ans + matrix[i][j] ;
        }
    }

    printf("\nThe Sum of the matrix is : %d",ans) ;
}

int oddnumgen()
{
    int oddnum ;
    int oddanum = 0 ;
    int oans = 0 ;
    int temp = 0 ;
    int temp1 = 0 ;

    scrclr() ;
    printf("Enter the amount of odd numbers you wanna generate : ") ;
    scanf("%d",&oddanum) ;

    for (int i = 0 ; i < oddanum ; i++)
    {
        temp++ ;
        oddnum = temp ;
        temp1 = oddnum - 1 ;
        oans = oddnum + temp1 ;
        printf("\nOdd Number %d : %d",temp,oans) ;
    }
}

int evennumgen()
{
    int evnum ;
    int evamnum = 0 ;
    int eans = 0 ;
    int temp = 0 ;
    int temp1 = 0 ;

    scrclr() ;
    printf("Enter the amount of even numbers you wanna generate : ") ;
    scanf("%d",&evamnum) ;

    for (int i = 0 ; i < evamnum ; i++)
    {
        temp++ ;
        evnum = temp ;
        eans = evnum + evnum ;
        printf("\nEven Number %d : %d",temp,eans) ;
    }
}

int fibonacci()
{
    int f0, f1, fians, fnuma, temp = 0 ;
    f0 = 0 ;
    f1 = 1 ;

    scrclr() ;
    printf("Type the amount of fibonacci numbers you wanna generate : ") ;
    scanf("%d",&fnuma) ;

    for (int i = 0 ; i < fnuma ; i++)
    {
        temp++ ;
        fians = f0 + f1 ;
        f0 = f1 ;
        f1 = fians ;

        printf("\nfibonacci %d : %d",temp,fians) ;
    }

}

void numgenprint()
{
    int genop ;

    scrclr() ;
    printf("Type 1 to generate fibonacci numbers") ;
    printf("\nType 2 to generate ODD numbers") ;
    printf("\nType 3 to generate EVEN numbers") ;
    printf("\nType 4 to generate Triangular numbers") ;
    printf("\nType 5 to generate Square numbers") ;
    printf("\nType 6 to generate prime numbers") ;
    printf("\nOperation : ") ;
    scanf("%d",&genop) ;

    switch (genop)
    {
    case 1 :
    {
        fibonacci() ;

        break ;
    }

    case 2 :
    {
        oddnumgen() ;

        break ;
    }

    case 3 :
    {
        evennumgen() ;

        break ;
    }

    case 4 :
    {
        trinumbergen() ;

        break ;
    }

    case 5 :
    {
        sqrnumgen() ;

        break ;
    }

    case 6 :
    {
        primegenerator() ;

        break ;
    }

    default :
    {
        printf("\nBAD INPUT") ;

        return 0 ;
        break ;
    }
    }
}

int trinumbergen()
{
    int trinum, trians, tritemp ;

    scrclr() ;
    printf("Enter the amount of triangle numbers you want to generate : ") ;
    scanf("%d",&trinum) ;

    trians = 0 ;
    tritemp = 0 ;

    for (int i = 0 ; i < trinum ; i++)
    {
        tritemp++ ;
        trians = trians + tritemp ;
        printf("Triangular number %d is : %d\n",(i+1),trians) ;
    }
}

int sqrnumgen()
{
    int sqnum, numgen, sqtemp ;

    scrclr() ;
    printf("Enter the amount of square numbers you want to generate : ") ;
    scanf("%d",&sqnum) ;
    sqtemp = 0 ;

    for (int i = 0; i < sqnum; i++)
    {
        sqtemp++ ;
        numgen = sqtemp * sqtemp ;
        printf("Square number %d : %d\n",sqtemp,numgen) ;
    }
}

int menu1displayheader()
{
    int lop, usrchk ;
    lop = 0 ;
    usrchk = FALSE ;
    globalusrchk = FALSE ;
    scrclr() ;

    while (globalusrchk == FALSE)
    {
        globalusrchk = TRUE ;
        printf("Type %d to go back to MENU 1",MENU) ;
        printf("\nType %d to round a decimal number to the nearest integer",ROUND) ;
        printf("\nType %d to convert a negative number to a natural number",NEGTOPOS) ;
        printf("\nType %d to find the square root of a number",SQRT) ;
        printf("\nType %d to generate random numbers",RANDOM) ;
        printf("\nType %d to check if a number is prime or not",PRIMECHK) ;
        printf("\nType %d to arrange numbers in ascending order",ASCEND) ;
        printf("\nType %d to convert fraction to decimal",FRACTODEC) ;
        printf("\nType %d to convert decimal to fraction",DECTOFRAC) ;
        printf("\nType %d to convert fraction to lowest terms",REDUCE) ;
        printf("\nType %d to find the percentage of a number to it's total",PERCENTAGE) ;
        printf("\nType %d to do fraction arithmetic",FRACARITH) ;
        printf("\nType %d to launch properties program",PROP_PROG) ;
        printf("\nType %d to launch distance calculator program",DIST_CALC) ;
        printf("\nOPERATION : ") ;
        menu1userinput() ;

        if(globalusrchk == TRUE)
        {
            switch (mop1)
            {
            case MENU :
            {
                scrclr() ;
                UserInput() ;
                ProcessInputs() ;

                break ;
            }

            case ROUND :
            {
                roundnum() ;

                break ;
            }

            case NEGTOPOS :
            {
                negtopos() ;

                break ;
            }

            case SQRT :
            {
                squareroot() ;

                break ;
            }

            case RANDOM :
            {
                randomgen() ;

                break ;
            }

            case PRIMECHK :
            {
                primechk() ;

                break ;
            }

            case ASCEND :
            {
                ascend() ;

                break ;
            }

            case FRACTODEC :
            {
                fractodec() ;

                break ;
            }

            case DECTOFRAC :
            {
                dectofrac() ;

                break ;
            }

            case REDUCE :
            {
                reducefrac() ;

                break ;
            }

            case PERCENTAGE :
            {
                percentage() ;

                break ;
            }

            case FRACARITH :
            {
                fraction_arithmetic() ;

                break ;
            }

            case PROP_PROG :
            {
                properties_program() ;

                break ;
            }

            case DIST_CALC :
            {
                distance_calc() ;

                break ;
            }



            default :
            {
                globalusrchk = FALSE ;

                break ;
            }
            }
            getch() ;
        }
    }

    continuechk() ;
}


int roundnum()
{
    float lcnumber, lcnumber2, remainder  ;
    BOOL userchk = FALSE ;

    while (userchk == FALSE)
    {
        userchk = TRUE ;
        scrclr() ;
        printf("Enter the decimal number to be rounded to the nearest integer : ") ;
        scanf("%f",&lcnumber) ;

        lcnumber2 = (int) lcnumber ;
        remainder = lcnumber2 - lcnumber ;
        remainder = remainder * 10 ;

        if (remainder == 0)
        {
            userchk = FALSE ;
        }

        else
        {
            printf("The round of the decimal number %f is : %f",lcnumber,round(lcnumber)) ;
        }
    }
    getch() ;
}

int negtopos()
{
    long lcnum, lcans, usrchk ;
    usrchk = FALSE ;

    while (usrchk == FALSE)
    {
        usrchk = TRUE ;
        scrclr() ;
        printf("Enter a negative number : ") ;
        scanf("%d",&lcnum) ;

        if (lcnum > 0)
        {
            usrchk = FALSE ;
        }
        else
        {
            lcans = abs(lcnum) ;

            printf("The positive number of %d is : %d\n",lcnum,lcans) ;
        }
    }
    getch() ;
}

int squareroot()
{
    float m,n ;
    float sqrnum ;

    scrclr() ;
    n = 0.0001;
    printf("Enter the number you wanna find the square root of : ") ;
    scanf("%f",&sqrnum) ;

    for(m = 0 ; m < sqrnum ; m = m + n)
    {
        if((m * m) > sqrnum)
        {
            m = m-n ;

            break ;
        }
    }

    printf("%f",m) ;
    getch() ;
}

int randomgen()
{
    int randnum, range, randnumop, localchk ;
    localchk = FALSE ;
    int randtemp ;

    randtemp = 0 ;
    localchk = TRUE ;
    scrclr() ;
    printf("How many random numbers do you want to generate : ") ;
    scanf("%d",&randnumop) ;
    printf("Range (0 to ) : ") ;
    scanf("%d",&range) ;

    for (int i = 0 ; i < randnumop ; i++)
    {
        randtemp++ ;
        randnum = rand() % range ;
        printf("\nRandom Number %d is : %d",randtemp,randnum) ;
    }
}

int menu1userinput()
{
    int localchk = FALSE ;
    scanf("%d",&mop1) ;

    //printf("You have selected %s (y/n) : ",prosname) ;

    while(localchk == FALSE)
    {
        localchk = TRUE ;

        switch (mop1)
        {
        case MENU :
        {
            scrclr() ;
            UserInput() ;
            ProcessInputs() ;

            break ;
        }

        case ROUND :
        {
            strcpy(prosname,"rounding numbers operation") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case NEGTOPOS :
        {
            strcpy(prosname,"negative to positive operation") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;

                break ;
            }

            break ;
        }

        case SQRT :
        {
            strcpy(prosname,"Square root calculation") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case RANDOM :
        {
            strcpy(prosname,"random number generator") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case PRIMECHK :
        {
            strcpy(prosname,"prime number checker") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case ASCEND :
        {
            strcpy(prosname,"ascending order") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case FRACTODEC :
        {
            strcpy(prosname,"fraction to decimal conversion") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case DECTOFRAC :
        {
            strcpy(prosname,"decimal to fraction conversion") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case REDUCE :
        {
            strcpy(prosname,"fraction in its lowest terms operation") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case PERCENTAGE :
        {
            strcpy(prosname,"percentage calculation") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case FRACARITH :
        {
            strcpy(prosname,"fraction arithmetic") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case PROP_PROG :
        {
            strcpy(prosname,"properties program") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        case DIST_CALC :
        {
            strcpy(prosname,"distance calculator") ;

            if (check() == FALSE)
            {
                globalusrchk = FALSE ;
                scrclr() ;
            }

            break ;
        }

        default :
        {
            localchk = FALSE ;

            break ;
        }
        }
    }
}

int primechk()
{
    int number ;
    short isprime = TRUE ;
    float limit ;
    int orinumber ;

    scrclr() ;
    printf("Enter a number to check whether it is prime or not : ") ;
    scanf("%d",&number) ;
    orinumber = number ;

    if (number < 0)
    {
        orinumber = number ;
        number = abs(number) ;
    }

    if (number == 2)
    {
        orinumber = number ;
        printf("\n%d is prime",number) ;
        getch() ;

        return 0 ;
    }

    if (number == 1)
    {
        orinumber = number ;
        printf("\n%d is unique",number) ;
        getch() ;

        return 0 ;
    }

    limit = sqrt(number) ;

    for (int i = 2 ; i <= (limit + 1) ; ++i)
    {
        if (number % i == 0)
        {
            isprime = FALSE ;

            break ;
        }
    }

    if (isprime == FALSE)
    {
        printf("\n%d is NOT prime",orinumber) ;
    }

    else if (isprime == TRUE)
    {
        printf("\n%d is prime",orinumber) ;
    }
}

int primegenerator()
{
    int amount ;
    int prime = 3 ;
    int j = 0 ;
    int buffer ;

    scrclr() ;
    printf("Enter the amount of prime numbers you wanna generate : ") ;
    scanf("%d",&amount) ;

    if (amount >= 1)
    {
        printf("First %d prime numbers are :\n", amount) ;
        printf("2\n") ;
    }

    for (int i = 2 ; i <= amount ; buffer++)
    {
        for (j = 2 ; j <= prime - 1 ; j++)
        {
            if(prime % j == 0)
            {
                break ;
            }
        }

        if ( j == prime )
        {
            printf("%d\n",prime) ;
            i++ ;
        }

        prime++ ;
    }
}

int ascend()
{
    int sortnum ;
    int temp ;

    scrclr() ;
    printf("Type the amount of numbers you wanna sort in ascending order : ") ;
    scanf("%d",&sortnum) ;

    int sortarray[sortnum] ;

    for (int i = 0 ; i < sortnum ; i++)
    {
        printf("\nEnter the value of element of %d : ",i) ;
        scanf("%d",&sortarray[i]) ;
    }

    for (int i = 0 ; i < sortnum ; i++)
    {
        for (int j = 0 ; j < (sortnum - i + 1) ; j++)
        {
            if (sortarray[j] < sortarray[j + 1])
            {
                temp = sortarray[j] ;
                sortarray[j] = sortarray[j + 1] ;
                sortarray[j + 1] = temp ;
            }
        }
    }

    for (int i = 0 ; i < sortnum ; i++)
    {
        printf("%d\n",sortarray[i]) ;
    }
}

int decend()
{
    int sortnum ;
    int temp ;

    scrclr() ;
    printf("Type the amount of numbers you wanna sort in ascending order : ") ;
    scanf("%d",&sortnum) ;

    int sortarray[sortnum] ;

    for (int i = 0 ; i < sortnum ; i++)
    {
        printf("\nEnter the value of element of %d : ",i) ;
        scanf("%d",&sortarray[i]) ;
    }

    for (int i = 0 ; i < sortnum ; i++)
    {
        for (int j = i + 1 ; j < sortnum ; j++)
        {
            if (sortarray[j] < sortarray[j + 1])
            {
                temp = sortarray[i] ;
                sortarray[i] = sortarray[j] ;
                sortarray[j] = temp ;
            }
        }
    }

    for (int i = 0 ; i < sortnum ; i++)
    {
        printf("%d\n",sortarray[i]) ;
    }
}

int fractodec()
{
    float nume, deno ;
    float convert ;

    scrclr() ;
    printf("Enter the numerator : ") ;
    scanf("%f",&nume) ;
    printf("\nEnter the denominator : ") ;
    scanf("%f",&deno) ;
    convert = nume / deno ;
    printf("\n%d / %d in decimal form is %.2f",(int)nume,(int)deno,convert) ;
}

int frac_to_dec_return(float nume, float deno)
{
    float convert ;

    scrclr() ;
    convert = nume / deno ;

    return convert ;
}

int dectofrac()
{
    return 0 ;
}

int reducefrac()
{
    int nume, denom, temp, temp1 ;

    scrclr() ;
    printf("Enter the numerator : ") ;
    scanf("%d",&nume) ;
    printf("Enter the denominator : ") ;
    scanf("%d",&denom) ;
    temp = nume ;
    temp1 = denom ;

    for (int i = denom / 2 ; i > 1 ; i--)
    {
        if ((nume % i == 0 ) && (denom % i == 0))
        {
            nume = nume / i ;
            denom = denom / i ;
            i = nume / 2 ;
        }
    }

    printf("The reduced form of %d / %d : %d / %d",temp,temp1,nume,denom) ;
}

int continuechk()
{
    char localop[4] ;
    int temp = 3 ;

    scrclr() ;
    printf("do you want to continue (y/n) : ") ;
    scanf("%s",&localop) ;

    if(!strcmp(localop,"y"))
    {
        temp = 1 ;
    }

    else if(!strcmp(localop,"Y"))
    {
        temp = 1 ;
    }

    else if(!strcmp(localop,"n"))
    {
        temp = 0 ;
    }

    else if(!strcmp(localop,"N"))
    {
        temp = 0 ;
    }

    switch(temp)
    {
    case 1 :
    {
        scrclr() ;
        UserInput() ;
        ProcessInputs() ;

        break ;
    }

    case 0 :
    {
        scrclr() ;
        quitcheck() ;

        break ;
    }

    default :
    {
        printf("BAD INPUT") ;

        break ;
    }
    }
}

int percentage()
{
    float localcalc ;
    float total ;
    float localnum ;

    scrclr() ;
    printf("Enter the total : ") ;
    scanf("%f",&total) ;
    printf("\nEnter the number of percentage you wanna find : ") ;
    scanf("%f",&localnum) ;
    localcalc = (float)localnum / total * 100.0 ;
    printf("\nPercentage : %.2f",localcalc) ;
}

int percentage_return(float total, float per_to_find)
{
    float local_calc ;
    float true_ans ;

    scrclr() ;
    local_calc = (float)per_to_find / total * 100.0 ;

    return local_calc ;
}


int lcm(int lcm_num1, int lcm_num2)
{
    int lcm_ans ;
    int lcm_gcd ;

    lcm_gcd = gcd(lcm_num1,lcm_num2) ;
    lcm_ans = ( lcm_num1 * lcm_num2 ) / lcm_gcd ;

    return lcm_ans ;
}

int gcd(int gnum1, int gnum2)
{
    int g_gcd = 0 ;
    int i ;

    for(i = 1 ; i <= gnum1 && i <= gnum2 ; i++)
    {
        if(gnum1 % i == 0 && gnum2 % i == 0)
        {
            g_gcd = i ;
        }
    }

    return g_gcd ;
}

int fraction_comparator(int nume1, int denom1, int nume2, int denom2)
{
    int ans_nume ;
    int i ;
    float practise1, practise2 ;

    flcm = lcm(denom1,denom2) ;
    practise1 = (flcm/denom1) ;
    practise2 = (flcm/denom2) ;
    nume1 = nume1 * practise1 ;
    nume2 = nume2 * practise2 ;

    if(nume1 > nume2)
    {
        return 1 ;
    }

    else if (nume2 > nume1)
    {
        return 0 ;
    }

    return -1 ;
}

int frac_add(int nume1, int denom1, int nume2, int denom2)
{
    int ans_nume ;
    int i ;
    float practise1, practise2 ;

    flcm = lcm(denom1,denom2) ;
    practise1 = (flcm/denom1) ;
    practise2 = (flcm/denom2) ;
    nume1 = nume1 * practise1 ;
    nume2 = nume2 * practise2 ;
    ans_nume = nume1 + nume2 ;

    return ans_nume ;
}

int reduce_frac_return(int nume, int denom, int return_val)
{
    int temp, temp1 ;

    temp = nume ;
    temp1 = denom ;

    for (int i = denom / 2 ; i > 1 ; i--)
    {
        if ((nume % i == 0 ) && (denom % i == 0))
        {
            nume = nume / i ;
            denom = denom / i ;
            i = nume / 2 ;
        }
    }

    if (return_val == 1)
    {
        return nume ;
    }

    else if (return_val == 0)
    {
        return denom ;
    }
}

int frac_sub(int nume1, int denom1, int nume2, int denom2)
{
    int ans_nume ;
    int i ;
    float practise1, practise2 ;

    flcm = lcm(denom1,denom2) ;
    practise1 = (flcm/denom1) ;
    practise2 = (flcm/denom2) ;
    nume1 = nume1 * practise1 ;
    nume2 = nume2 * practise2 ;
    ans_nume = nume1 - nume2 ;

    return ans_nume ;
}

int ascend_return(int ascend_array[array_max_elements])
{
    int temp ;

    scrclr() ;

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        for (int j = 0 ; j < (array_max_elements - i + 1) ; j++)
        {
            if (ascend_array[j] > ascend_array[j + 1])
            {
                temp = ascend_array[j] ;
                ascend_array[j] = ascend_array[j + 1] ;
                ascend_array[j + 1] = temp ;
            }
        }
    }

    return ascend_array ;
}

int frac_mul(int nume1, int denom1, int nume2, int denom2)
{
    int ans_nume ;
    int i ;
    float practise1, practise2 ;

    flcm = lcm(denom1,denom2) ;
    practise1 = (flcm/denom1) ;
    practise2 = (flcm/denom2) ;
    nume1 = nume1 * practise1 ;
    nume2 = nume2 * practise2 ;
    ans_nume = nume1 * nume2 ;

    return ans_nume ;
}

int frac_div(int nume1, int denom1, int nume2, int denom2)
{
    int ans_nume ;
    int i ;
    float practise1, practise2 ;

    flcm = lcm(denom1,denom2) ;
    practise1 = (flcm/denom1) ;
    practise2 = (flcm/denom2) ;
    nume1 = nume1 * practise1 ;
    nume2 = nume2 * practise2 ;
    ans_nume = nume1 / nume2 ;

    return ans_nume ;
}

int convert_to_mixed(int convert_nume, int convert_denom, int return_value)
{
    float convert_temp ;
    int convert_quo ;
    int convert_rem ;
    int convert_dividend ;
    int convert_divisor ;

    if(convert_denom < convert_nume)
    {
        convert_dividend = convert_nume ;
    }

    else if (convert_denom > convert_nume)
    {
        convert_dividend = convert_denom ;
    }

    else
    {
        return 0 ;
    }

    convert_temp = convert_dividend / convert_divisor ;
    convert_quo = (int)convert_temp ;
    convert_rem = convert_dividend % convert_divisor ;

    if(return_value == 0)
    {
        return convert_quo ;
    }

    if(return_value == 1)
    {
        return convert_rem ;
    }

    if(return_value == 2)
    {
        return convert_denom ;
    }
}

int equivlent_check(int eq_nume_1, int eq_deno_1,int eq_nume_2, int eq_deno_2)
{
    int eq_1 ;
    int eq_2 ;

    eq_1 = eq_nume_1 * eq_deno_2 ;
    eq_2 = eq_nume_2 * eq_deno_1 ;

    if (eq_1 == eq_2)
    {
        return 1 ;
    }

    else
    {
        return 0 ;
    }
}

int properties_program()
{
    int local_op ;
    int local_integer ;
    int integer_array[array_max_elements] ;
    int local_nume,local_denom ;
    char c[8] ;
    int temp_a ;

    printf("Type 1 to see the properties of an integer") ;
    printf("\nType 2 to see the properties of a group of integers") ;
    printf("\nType 3 to see the properties of a fraction") ;
    printf("\nBETA : Type 4 to see the properties of a group of fractions") ;
    printf("\nOPERATION : ") ;
    scanf("%d",&local_op) ;
    scrclr() ;

    switch(local_op)
    {
    case 1 :
    {
        printf("Enter an integer : ") ;
        scanf("%d",&local_integer) ;
        integer_properties(local_integer) ;

        break ;
    }

    case 2 :
    {
        printf("How many numbers do you wanna find the properties of ? : ") ;
        scanf("%d",&temp_a) ;
        printf("\nEnter the elements of the integer array separated by ',' : ") ;

        for(int i = 0 ; i < temp_a ; i++)
        {
            scanf("%d",&integer_array[i]) ;
            scanf("%c",&c[0]) ;
        }

        properties_integer_group(integer_array) ;

        break ;
    }

    case 3 :
    {
        printf("Enter the numerator : ") ;
        scanf("%d",&local_nume) ;
        printf("Enter the denominator : ") ;
        scanf("%d",&local_denom) ;
        properties_fraction(local_nume,local_denom) ;

        break ;
    }

    case 4 :
    {
        printf("\nIN SEVERE ALPHA CONDITION") ;

        return 0 ;
        break ;
    }

    default :
    {
        printf("\nERROR\n") ;
        return 0 ;
    }
    }
}


int fraction_arithmetic()
{
    int localop ;
    int local_result ;

    scrclr() ;
    printf("Type 1 to select fraction addition") ;
    printf("\nType 2 to select fraction subtraction") ;
    printf("\nType 3 to select fraction multiplication") ;
    printf("\nType 4 to select fraction division") ;
    printf("\nType 5 to compare 2 fractions") ;
    printf("\nType 6 to check if 2 fractions are equivlent") ;
    printf("\nOperation : ") ;
    scanf("%d",&localop) ;

    switch(localop)
    {
    case 1 :
    {
        fraction_scanf() ;
        f_ans_nume = frac_add(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        f_ans_denom = flcm ;
        printf("\nThe answer is : %d/%d or %d(%d/%d)",f_ans_nume,f_ans_denom,(int) f_ans_denom / f_ans_nume,(int)f_ans_denom % f_ans_nume,f_ans_nume) ;

        break ;
    }

    case 2 :
    {
        fraction_scanf() ;
        f_ans_nume = frac_sub(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        f_ans_denom = flcm ;
        printf("\nThe answer is : %d/%d or %d(%d/%d)",f_ans_nume,f_ans_denom,(int) f_ans_denom / f_ans_nume,(int)f_ans_denom % f_ans_nume,f_ans_nume) ;

        break ;
    }

    case 3 :
    {
        fraction_scanf() ;
        f_ans_nume = frac_mul(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        f_ans_denom = flcm ;
        printf("\nThe answer is : %d/%d or %d(%d/%d)",f_ans_nume,f_ans_denom,(int) f_ans_denom / f_ans_nume,(int)f_ans_denom % f_ans_nume,f_ans_nume) ;

        break ;
    }

    case 4 :
    {
        fraction_scanf() ;
        f_ans_nume = frac_div(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        f_ans_denom = flcm ;
        printf("\nThe answer is : %d/%d or %d(%d/%d)",f_ans_nume,f_ans_denom,(int) f_ans_denom / f_ans_nume,(int)f_ans_denom % f_ans_nume,f_ans_nume) ;

        break ;
    }

    case 5 :
    {
        fraction_scanf() ;
        local_result = fraction_comparator(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;

        if (local_result == 1)
        {
            printf("%d/%d > %d/%d",f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        }

        else if (local_result == 0)
        {
            printf("%d/%d < %d/%d",f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        }

        break ;
    }

    case 6 :
    {
        fraction_scanf() ;
        local_result = equivlent_check(f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;

        if(local_result == 1)
        {
            printf("\n%d/%d and %d/%d are equivlent",f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        }

        else if(local_result == 0)
        {
            printf("\n%d/%d and %d/%d are NOT equivlent",f_nume_1,f_denom_1,f_nume_2,f_denom_2) ;
        }

        break ;
    }

    default :
    {
        printf("\nERROR!\n") ;

        return 0 ;
        break ;
    }
    }
}

int fraction_scanf()
{
    char local_c[4] ;

    scrclr() ;
    printf("Enter fraction one : ") ;
    scanf("%d",&f_nume_1) ;
    scanf("%c",&local_c) ;
    scanf("%d",&f_denom_1) ;
    printf("\nEnter fraction two : ") ;
    scanf("%d",&f_nume_2) ;
    scanf("%c",&local_c) ;
    scanf("%d",&f_denom_2) ;
}

int array_properties_range(int range_array[array_max_elements])
{
    int range_num_1 ;
    int range_num_2 ;
    int range_final ;

    range_array = ascend_return(range_array) ;
    range_num_1 = range_array[array_max_elements] ;
    range_num_2 = range_array[0] ;
    range_final = range_num_1 - range_num_2 ;

    return range_final ;
}

int array_properties_frequency(int frequency_array[array_max_elements])
{
    int frequency_occur_array[array_max_elements] ;
    int count = 1 ;

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        frequency_occur_array[i] = -1 ;
    }

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        count = 1 ;

        for (int j = i + 1 ; j < array_max_elements ; j++)
        {
            if(frequency_array[i] == frequency_array[j])
            {
                count++ ;
                frequency_occur_array[j] = 0 ;
            }
        }

        if(frequency_occur_array[i] != 0)
        {
            frequency_occur_array[i] = count ;
        }
    }

    for(int i = 0 ; i < array_max_elements ; i++)
    {
        if(frequency_occur_array[i] != 0)
        {
            printf("\n%d occurs %d times\n", frequency_array[i], frequency_occur_array[i]);
        }
    }
}


int integer_properties(int integer)
{
    short properties_even, properties_odd, properties_positive, properties_negative, properties_neither ;

    if (integer == 0)
    {
        properties_neither = true ;
    }

    if (integer == 1)
    {
        properties_odd = true ;
    }

    if (integer % 2 == 0)
    {
        properties_even = true ;
    }

    if (integer < 0)
    {
        properties_negative = true ;
    }

    if (integer > 0)
    {
        properties_positive = true ;
    }

    // Print the result

    if(properties_neither == true)
    {
        printf("\n%d is a zero number") ;
    }

    if(properties_positive == true)
    {
        printf("\n%d is a positive number",integer) ;
    }

    if(properties_negative == true)
    {
        printf("\n%d is a negative number",integer) ;
    }

    if(properties_even == true)
    {
        printf("\n%d is an even number",integer) ;
    }

    if(properties_odd == true)
    {
        printf("\n%d is an odd number",integer) ;
    }
}

int properties_integer_group(int int_group_array[array_max_elements])
{
    int int_group_range ; //DONE P
    int int_group_frequency ; //DONE P
    int int_group_positive[array_max_elements] ; //DONE P
    int int_group_negative[array_max_elements] ; //DONE P
    int int_group_odd[array_max_elements] ; //DONE P
    int int_group_even[array_max_elements] ; //DONE P
    int int_group_ascend[array_max_elements] ;  //DONE P
    int int_group_decend[array_max_elements] ; //DONE P
    int intgrp_temp ;
    int local_temp3 ;

    int_group_range = array_properties_range(int_group_array) ;
    int_group_negative[0] = 1 ;
    int_group_positive[0] = -1 ;
    int_group_odd[0] = 2 ;
    int_group_even[0] = 1 ;

    //INITIALISE THE ASCEND AND DECEND ARRAYS
    for(int i = 0 ; i < array_max_elements ; i++)
    {
        int_group_ascend[i] = int_group_array[i] ;
        int_group_decend[i] = int_group_array[i] ;
    }

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        for (int j = 0 ; j < (array_max_elements - i + 1) ; j++)
        {
            if (int_group_ascend[j] > int_group_ascend[j + 1])
            {
                intgrp_temp = int_group_ascend[j] ;
                int_group_ascend[j] = int_group_ascend[j + 1] ;
                int_group_ascend[j + 1] = intgrp_temp ;
            }
        }
    }

    for (int i = 0 ; i < array_max_elements; i++)
    {
        if(int_group_array[i] > 0)
        {
            int_group_positive[i] = int_group_array[i] ;
        }

        else if(int_group_array[i] < 0)
        {
            int_group_negative[i] = int_group_array[i] ;
        }
    }

    for (int i = 0 ; i < array_max_elements; i++)
    {
        if(int_group_array[i] % 2 == 0)
        {
            int_group_even[i] = int_group_array[i] ;
        }

        else if(int_group_array[i] % 2 == 1)
        {
            int_group_odd[i] = int_group_array[i] ;
        }
    }

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        for (int j = i + 1 ; j < array_max_elements ; j++)
        {
            if (int_group_decend[j] < int_group_decend[j + 1])
            {
                local_temp3 = int_group_decend[i] ;
                int_group_decend[i] = int_group_decend[j] ;
                int_group_decend[j] = local_temp3 ;
            }
        }
    }

    printf("The range of the array is : %d",int_group_range) ;
    printf("\nThe frequency is as follows : ") ;
    array_properties_frequency(int_group_array) ;

    if(int_group_positive[0] != -1)
    {
        printf("\nPositive Numbers : %d",int_group_positive[0]) ;

        for(int i = 1 ; i < array_max_elements ; i++)
        {
            printf(",%d",int_group_positive[i]) ;
        }
    }

    if(int_group_negative[0] != 1)
    {
        printf("\nNegative Numbers : %d",int_group_negative[0]) ;

        for(int i = 1 ; i < array_max_elements ; i++)
        {
            printf(",%d",int_group_negative[i]) ;
        }
    }

    if(int_group_odd[0] != 2)
    {
        printf("\nOdd Numbers : %d",int_group_odd[0]) ;

        for(int i = 1 ; i < array_max_elements ; i++)
        {
            printf(",%d",int_group_odd[i]) ;
        }
    }

    if(int_group_even[0] != 1)
    {
        printf("\nEven Numbers : %d",int_group_even[0]) ;

        for(int i = 1 ; i < array_max_elements ; i++)
        {
            printf(",%d",int_group_even[i]) ;
        }
    }

    printf("\nNumbers in ascending order : %d",int_group_ascend[0]) ;

    for(int i = 1 ; i < array_max_elements ; i++)
    {
        printf(",%d",int_group_ascend[i]) ;
    }

    printf("\nNumbers in decending order : %d",int_group_decend[0]) ;

    for(int i = 1 ; i < array_max_elements ; i++)
    {
        printf(",%d",int_group_decend[i]) ;
    }
}

int properties_fraction(int frac_nume, int frac_denom)
{
    float frac_decimal ; //DONE
    int proper_improper_chk ; //DONE
    int reduce_nume ; //DONE
    int reduce_denom ; //DONE
    short reduce_able ; //DONE
    char frac_string[16] ;
    char frac_string_2[16] ;
    float dec_frac_nume ;
    float dec_frac_denom ;
    short local_a, local_b ;

    dec_frac_nume = (float) frac_nume ;
    dec_frac_denom = (float) frac_denom ;
    frac_decimal = dec_frac_nume / dec_frac_denom ;

    if (frac_nume < frac_denom)
    {
        proper_improper_chk = true ;
    }

    else if ((frac_nume > frac_denom))
    {
        proper_improper_chk = false ;
    }

    if(proper_improper_chk == true)
    {
        local_a = true ;
    }

    else if(proper_improper_chk == false)
    {
        local_a = false ;
    }

    if(local_a == true)
    {
        strcpy(frac_string_2,"proper") ;
    }

    else if(local_a == false)
    {
        strcpy(frac_string_2,"improper") ;
    }

    reduce_nume = reduce_frac_return(frac_nume, frac_denom, 0) ;
    reduce_denom = reduce_frac_return(frac_nume, frac_denom, 1) ;

    if (reduce_denom != frac_denom)
    {
        strcpy(frac_string,"is reduceable") ;
    }

    else
    {
        strcpy(frac_string,"is not reduceable") ;
    }

    printf("%d/%d in decimal form = %.2f",frac_nume, frac_denom,frac_decimal) ;
    printf("\n%d/%d %s",frac_nume, frac_denom, frac_string) ;
    printf("\n%d/%d in reduced form = %d/%d",frac_nume, frac_denom, reduce_denom, reduce_nume) ;
    printf("\n%d/%d is %s",frac_nume, frac_denom,frac_string_2) ;
}

int properties_group_fraction(int frac_group_nume[array_max_elements], int frac_group_denom[array_max_elements]) //BETA
{
    int frac_group_LCM ; //DONE
    int local_count ;
    int lcm_frac_group = 1 ;
    int	frac_temp_1 [array_max_elements] ;
    int frac_temp_2 [array_max_elements] ;
    int local_temp ;
    int local_temp_2 ;

    ///INITIALISE THE ARRAYS
    for(int i = 0 ; i < array_max_elements ; i++)
    {
        frac_group_ascend_nume[i] = i ;
        frac_group_ascend_denom[i] = i + i;
        frac_group_decend_nume[i] = i + 1 ;
        frac_group_decend_denom[i] = i + i ;
    }

    ///ASCENDING
    for(int i = 0 ; i < array_max_elements ; i++)
    {
        local_temp_2 = frac_group_ascend_nume[i] ;
        lcm_frac_group = lcm(lcm_frac_group,local_temp_2) ;
    }

    frac_group_LCM = lcm_frac_group ;

    for(int i = 0 ; i < array_max_elements ; i++)
    {
        frac_temp_1[i] = (lcm_frac_group/frac_group_denom[i]) ;
    }

    for(int i = 0 ; i < array_max_elements ; i++)
    {
        frac_group_ascend_nume[i] = frac_group_ascend_nume[i] * frac_temp_1[i] ;
    }

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        for (int j = 0 ; j < (array_max_elements - i + 1) ; j++)
        {
            if (frac_group_ascend_nume[j] > frac_group_ascend_nume[j + 1])
            {
                local_temp = frac_group_ascend_nume[j] ;
                frac_group_ascend_nume[j] = frac_group_ascend_nume[j + 1] ;
                frac_group_ascend_nume[j + 1] = local_temp ;
            }
        }
    }

    frac_group_ascend_denom[0] = lcm_frac_group ;

    ///DECENDING
    for(int i = 0 ; i < array_max_elements ; ++i)
    {
        lcm_frac_group = lcm(lcm_frac_group,frac_group_decend_nume[i]) ;
    }

    for(int i = 0 ; i < array_max_elements ; i++)
    {
        frac_temp_1[i] = (lcm_frac_group/frac_group_denom[i]) ;
    }

    for(int i = 0 ; i < array_max_elements ; i++)
    {
        frac_group_decend_nume[i] = frac_group_decend_nume[i] * frac_temp_1[i] ;
    }

    for (int i = 0 ; i < array_max_elements ; i++)
    {
        for (int j = i + 1 ; j < array_max_elements ; j++)
        {
            if (frac_group_decend_nume[j] < frac_group_decend_nume[j + 1])
            {
                local_temp = frac_group_decend_nume[i] ;
                frac_group_decend_nume[i] = frac_group_decend_nume[j] ;
                frac_group_decend_nume[j] = local_temp ;
            }
        }
    }

}

int complete_program_power(int complete_num, int complete_exp)
{
    int complete_sqrt ;
    int complete_temp_ans ;
    int complete_ans = -1 ;

    complete_sqrt = (int) sqrt(complete_num) ;

    for(int i = 0 ; i <= complete_sqrt ; i++)
    {
        complete_temp_ans = pow(complete_num,i) ;

        if(complete_temp_ans == complete_num)
        {
            complete_ans = i ;
        }
    }

    if(complete_ans == -1)
    {
        return -1 ;
    }

    else
    {
        return complete_ans ;
    }
}

int complete_program_addition(int complete_augend, int complete_sum)
{
    int complete_addend ;

    complete_addend = complete_augend - complete_sum ;
    return complete_addend ;
}

int complete_program_subtraction(int complete_minuend, int difference)
{
    int complete_subtrahend ;

    complete_subtrahend = difference - complete_minuend ;
    return complete_subtrahend ;
}

int complete_program_multiply(int complete_factor_1, int complete_product)
{
    int complete_factor_2 ;

    complete_factor_2 = complete_product / complete_factor_1 ;
    return complete_factor_2 ;
}

int complete_program_dividend(int complete_divisor, int complete_quotient)
{
    int complete_dividend ;

    complete_dividend = complete_quotient * complete_divisor ;
    return complete_divisor ;
}

int complete_program_divisor(int complete_dividend, int complete_quotient)
{
    int complete_divisor ;

    complete_divisor = complete_divisor / complete_quotient ;
    return complete_divisor ;
}

int distance_calc()//BETA
{
    long distance_seconds = -1 ;
    long distance_minutes = -1 ;
    long distance_hours = -1 ;
    long distance_days = -1 ;
    long distance_weeks = -1 ;
    long distance_months = -1 ;
    long distance_years = -1 ;
    long distance_decades = -1 ;
    long distance = 176 ;
    long speed_rate = 20 ;
    short print_year_ = false ;

    if(distance > speed_rate)
    {
        distance_seconds = distance / speed_rate * 3600 ;
    }

    else
    {
        distance_seconds = speed_rate / distance ;
    }

    if(distance_seconds > 60)
    {
        distance_minutes = distance_seconds / 60 ;
        distance_seconds = distance_minutes * 60 - distance_seconds ;
    }

    if(distance_minutes > 60)
    {
        distance_hours = distance_minutes / 60 ;
        distance_minutes = distance_minutes / 60 ;
    }

    if(distance_hours > 24)
    {
        distance_days = distance_hours / 24 ;
        distance_hours = distance_hours / 24 ;
    }

    if(distance_days > 31)
    {
        distance_months = distance_days / 31 ;
        distance_days = distance_days ;
    }

    if(distance_months > 12)
    {
        distance_years = distance_months / 12 ;
        print_year_ = true ;
        distance_months = distance_months / 12 ;
    }

    else if(distance_minutes == -1)
    {
        printf("%ld kilometers take %ld seconds, to go at the speed of %ld KPH",distance,distance_seconds,speed_rate) ;
    }

    else if(distance_hours == -1)
    {
        printf("%ld kilometers take %ld minutes and %ld seconds, to go at the speed of %ld KPH",distance,distance_minutes,distance_seconds,speed_rate) ;
    }

    else if(distance_days == -1)
    {
        printf("%ld kilometers take %ld hours, %ld minutes, %ld seconds, to go at the speed of %ld KPH",distance,distance_hours,distance_minutes,distance_seconds,speed_rate) ;
    }

    else if(distance_months == -1)
    {
        printf("%ld kilometers take %ld days, %ld hours, %ld minutes, %ld seconds, to go at the speed of %ld KPH",distance,distance_days,distance_hours,distance_minutes,distance_seconds,speed_rate) ;
    }

    else if(distance_years == -1)
    {
        printf("%lf kilometers take %lf months, %lf days, %lf hours, %lf minutes, %lf seconds, to go at the speed of %lf KPH",distance,distance_months,distance_days,distance_hours,distance_minutes,distance_seconds,speed_rate) ;
    }

    else if(print_year_ == true)
    {
        printf("%lf kilometers take %lf years, %lf months, %lf days, %lf hours, %lf minutes, %lf seconds, to go at the speed of %lf KPH",distance,distance_years,distance_months,distance_days,distance_hours,distance_minutes,distance_seconds,speed_rate) ;
    }
}

int KMS_TO_KMH(double KMS)
{
    double KMH ;
    KMH = KMS * 3600 ;

    return KMH ;
}

int KMH_TO_KMS(double KMH)
{
    double KMS ;
    KMS = KMH / 3600 ;

    return KMS ;
}

int invert_array_return(int array_to_invert[array_max_elements],int n)
{
    int in_temp ;

    for(int i = 0 ; i < (n/2) ; i++)
    {
        in_temp = array_to_invert[i] ;
        array_to_invert[i] = array_to_invert[n-i-1] ;
        array_to_invert[n-i-1] = in_temp ;
    }

}

int invert_array_UI() //Done
{
    int in_temp ;
    int array_to_invert[array_max_elements] ;
    int n ;

    printf("Enter the amount of elements to inverse : ") ;
    scanf("%d",&n) ;

    for(int i = 0 ; i < n ; i++)
    {
        printf("\nEnter the value of element %d : ",i) ;
        scanf("%d",&array_to_invert[i]) ;
    }

    for(int i = 0 ; i < (n/2) ; i++)
    {
        in_temp = array_to_invert[i] ;
        array_to_invert[i] = array_to_invert[n-i-1] ;
        array_to_invert[n-i-1] = in_temp ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\n",array_to_invert[i]) ;
    }
}

int array_median(int array_median_[array_max_elements],int n)
{
    if(n % 2 == 0)
    {
        return 0 ;
    }

    else
    {
        n = n - 1 / 2 + 1 ;
        return array_median_[n] ;
    }
}

int array_mean(int array_mean_[array_max_elements],int n)
{
    int sum = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + array_mean_[i] ;
    }

    sum = sum / n ;

    return sum ;
}

int array_insert(int* array, int pos, int value, int size)
{
    int inserted_array[size + 1] ;

    if (pos > (size + 1))
    {
        return 0 ;
    }

    for (int i = 0 ; i < size ; i++)
    {
        inserted_array[i] = array[i] ;
    }

    for (int i = (size - 1) ; i >= (size - pos) ; i--)
    {
        inserted_array[i] = inserted_array[i+1] ;
    }

    inserted_array[pos] = value ;

    for (int i = 0 ; i < (size + 1) ; i++)
    {
        printf(" %d \n",inserted_array[i]) ;

    }

    getch() ;
    getch() ;
}

int insert_array_ui()
{
    int n ;
    int insert_array[array_max_elements] ;
    int new_element_val ;
    int pos ;

    printf("enter the amount of elements : ") ;
    scanf("%d",&n) ;

    for(int i = 0 ; i < n ; i++)
    {
        printf("\nEnter the value of element %d : ",i) ;
        scanf("%d",&insert_array[i]) ;
    }

    printf("\nEnter the position of the new element : ") ;
    scanf("%d",&pos) ;
    printf("\nEnter the value of the new element : ") ;
    scanf("%d",&new_element_val) ;

    array_insert(insert_array,pos,new_element_val,n) ;
}



