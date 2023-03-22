#include <stdio.h>
#include <dos.h>
#include <stdlib.h>

#define BOOL short
#define FALSE     0
#define TRUE      1
#define DATETIME  1
#define HOTSPOT   2
#define NETWORK   3
#define HACK      4
#define BUFFER1SIZE   32
#define IPCON     5
#define ENCRYPT   6
#define DECRYPT   7

int op,input ;

int getoperation() ;
int userverify() ;
void DisplayHeader() ;
void ipconfig() ;
int datetime() ;
void date() ;
void time() ;
void wifihotspot() ;
void netveiw() ;
int userhack() ;
int encrypt() ;
void decryptfile() ;
void scrclr() ;

int main()
{
    userverify() ;
}

int getoperation()
{
    input = FALSE ;

    while (input == FALSE)
    {
        DisplayHeader() ;

        switch (op)
        {
            input = TRUE ;

            case DATETIME :
            {
                datetime() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case HOTSPOT :
            {
                wifihotspot() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case NETWORK :
            {
                netveiw() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case HACK :
            {
                userhack() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case IPCON :
            {
                ipconfig() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case ENCRYPT :
            {
                encrypt() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            case DECRYPT :
            {
                decryptfile() ;
                printf("\nPress any key to continue") ;
                getch() ;

                return 0 ;
                break ;
            }

            default :
            {
                scrclr() ;
                input = FALSE ;

                break ;
            }
        }

    }
}

int userverify()
{
    BOOL flag = FALSE ;
    char username[BUFFER1SIZE] ;
    char password[BUFFER1SIZE] ;
    char c  ;
    int i = 0 ;

    printf("Type the username : ") ;
    scanf("%s",&username) ;

    if(!strcmp(username,"Samuel"))
    {
        flag = TRUE ;
    }

    else
    {
        flag = FALSE ;
        printf("Wrong Username") ;
    }

    if (flag == TRUE)
    {
        printf("Type the password : ") ;

        while ((c = getch())!= '\r')
        {
            password[i] = c ;
            printf("*") ;
            i++ ;

            if (i > BUFFER1SIZE)
            {
                i = 0 ;
            }
        }

        password[i] = '\0' ;

        if (!strcmp(password,"prawsjsw"))
        {
            scrclr() ;
            getoperation() ;
        }

        else
        {
            printf("\nWrong password") ;
            return 0 ;
        }
    }
}

void DisplayHeader()
{
    printf("Welcome to cmd helper v01") ;
    printf("\nType %d to set date and time",DATETIME) ;
    printf("\nType %d to setup wifi hotspot",HOTSPOT) ;
    printf("\nType %d to see the network details",NETWORK) ;
    printf("\nType %d to hack user password",HACK) ;
    printf("\nType %d to see your ip configuration",IPCON) ;
    printf("\nType %d to encrypt a file or folder (BETA)",ENCRYPT) ;
    printf("\nType %d to decrypt a file or folder (BETA) (only file(s))",DECRYPT) ;
    printf("\nOperation : ") ;
    scanf("%d",&op) ;
}

void ipconfig()
{
    scrclr() ;
    system("@ipconfig") ;
}

int datetime()
{
    int op,check ;
    check = FALSE ;

    while (check == FALSE)
    {
        scrclr() ;
        printf("Type 1 to setup date") ;
        printf("\nType 2 to setup time") ;
        printf("\nOption : ") ;
        scanf("%d",&op) ;
        check = TRUE ;

        switch (op)
        {
            case 1 :
            {
                date() ;

                break ;
            }

            case 2 :
            {
                time() ;

                break ;
            }

            default :
            {
                 printf("BAD INPUT") ;
                 check = FALSE ;

                 break ;
            }

        }
    }
}

void date()
{
    scrclr() ;
    system("@date") ;
}

void time()
{
    scrclr() ;
    system("@time") ;
}

void scrclr()
{
    system("@cls") ;
}

void netveiw()
{
    char systemcommand[1024] ;
    char wifiname[64] ;

    scrclr() ;
    printf("DISCLAIMER : THIS WILL SHOW DETAILS OF ONLY PREVIOUSLY CONNECTED NETWORKS") ;
    printf("\nType the name of the wifi network : ") ;
    scanf("%s",&wifiname) ;
    strcpy(systemcommand,"@netsh wlan show profile ") ;
    strcat(systemcommand,wifiname) ;
    strcat(systemcommand," key=clear") ;
    system(systemcommand) ;
}

void wifihotspot()
{
    char ssid[32] ;
    char key[32] ;
    char systemcommand[512] ;
    int op,loop ;

    scrclr() ;
    systemcommand[0] = '\0' ;
    printf("Type the ssid : ") ;
    scanf("%s",&ssid) ;
    printf("Type the Network key : ") ;
    scanf("%s",&key) ;
    strcpy(systemcommand,"@netsh wlan set hostednetwork mode=allow ssid=") ;
    strcat(systemcommand,ssid) ;
    strcat(systemcommand," key=") ;
    strcat(systemcommand,key) ;
    system(systemcommand) ;
    loop = 1 ;

    while(loop == 1)
    {
        scrclr() ;
        printf("Press 1 to START the hosted network\n") ;
        printf("Press 2 to STOP the hosted network\n") ;
        printf("Press 3 to EXIT\n") ;
        printf("Operation : ") ;
        scanf("%d",&op) ;

        switch (op)
        {
            case 1 :
            {
                strcpy(systemcommand,"netsh wlan start hostednetwork") ;

                break ;
            }

            case 2 :
            {
                strcpy(systemcommand,"netsh wlan stop hostednetwork") ;

                break ;
            }

            default :
            {
                printf("\nEXITING...") ;

                return 0 ;
                break ;
            }
        }
        system(systemcommand) ;
        getch() ;
    }
}

int userhack()
{
    char username[32] ;
    char systemcommand[256] ;

    scrclr() ;
    systemcommand[0] = '\0' ;
    printf("Type the name of the user you want to hack : ") ;
    scanf("%s",&username) ;
    strcpy(systemcommand,"@net user ") ;
    strcat(systemcommand,username) ;
    strcat(systemcommand," *") ;
    system(systemcommand) ;
}

int encrypt()
{
    int op, input ;
    input = FALSE ;

    while (input == FALSE)
    {
        input = TRUE ;
        scrclr() ;
        printf("Type 1 to encrypt a single file") ;
        printf("\nType 2 to encrypt a folder") ;
        printf("\nOperation : ") ;
        scanf("%d",&op) ;

        switch (op)
        {
            case 1 :
            {
                encryptfile() ;

                break ;
            }

            case 2 :
            {
                encryptfolder() ;

                break ;
            }

            default :
            {
                input = FALSE ;

                break ;
            }
        }
        printf("\nPress any key to proceed.") ;
        getch() ;
    }
}

void encryptfile()
{
    char dir [2048] ;
    char filename [1024] ;
    char systemcommand[2048] ;

    scrclr() ;
    systemcommand[0] = '\0' ;
    dir[0] = '\0' ;
    filename[0] = '\0' ;
    printf("\nEnter the directory : ") ;
    scanf("%s",&dir) ;
    printf("Enter the file name : ") ;
    scanf("%d",&filename) ;
    strcpy(systemcommand,"@CD ") ;
    strcat(systemcommand,dir) ;
    system(systemcommand) ;
    strcpy(systemcommand,"@cipher /A /E") ;
    strcat(systemcommand,filename) ;
    system(systemcommand) ;
}

void encryptfolder()
{
    char dir[2048] ;
    char systemcommand[2048] ;

    scrclr() ;
    systemcommand[0] = '\0' ;
    dir[0] = '\0' ;
    printf("\nEnter the directory : ") ;
    scanf("%s",&dir) ;
    strcpy(systemcommand,"cipher /E ") ;
    strcat(systemcommand,dir) ;
    system(systemcommand) ;
}

void decryptfile()
{
    char dir [2048] ;
    char filename [1024] ;
    char systemcommand[2048] ;

    scrclr() ;
    systemcommand[0] = '\0' ;
    dir[0] = '\0' ;
    filename[0] = '\0' ;
    printf("\nEnter the directory : ") ;
    scanf("%s",&dir) ;
    printf("Enter the file name : ") ;
    scanf("%d",&filename) ;
    strcpy(systemcommand,"@CD ") ;
    strcat(systemcommand,dir) ;
    system(systemcommand) ;
    strcpy(systemcommand,"@cipher /D ") ;
    strcat(systemcommand,filename) ;
    system(systemcommand) ;
}
