#include <stdio.h>
#include <conio.h>

#include "password_input.h"


void getHiddenPassword(char password[], int size)
{

    int index = 0;

    char ch;


    printf("Enter Password: ");


    while(1)
    {

        ch = getch();


        // Enter key
        if(ch == '\r')
        {
            break;
        }


        // Backspace key
        else if(ch == '\b')
        {

            if(index > 0)
            {
                index--;

                printf("\b \b");
            }

        }


        // Normal character
        else
        {

            if(index < size-1)
            {
                password[index++] = ch;

                printf("*");
            }

        }

    }


    password[index] = '\0';


    printf("\n");

}