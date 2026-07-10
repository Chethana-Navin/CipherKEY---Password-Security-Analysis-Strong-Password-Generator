#include <stdio.h>

#include "strength_meter.h"
#include "terminal_colors.h"


void displayStrengthMeter(PasswordReport report)
{

    int percentage;


    /*
       Maximum score is 6

       1. Length >= 8
       2. Length >= 12
       3. Uppercase
       4. Lowercase
       5. Number
       6. Symbol
    */


    percentage =
        (report.strengthScore * 100) / 6;



    int bars =
        percentage / 5;



    printf("\nSecurity Score:\n\n");


    printf("[");



    for(int i = 0; i < 20; i++)
    {

        if(i < bars)
        {

            if(percentage < 40)
                printf(RED "#" RESET);


            else if(percentage < 70)
                printf(YELLOW "#" RESET);


            else
                printf(GREEN "#" RESET);

        }

        else
        {
            printf("-");
        }

    }


    printf("] ");


    if(percentage < 40)
    {
        printf(RED);
    }

    else if(percentage < 70)
    {
        printf(YELLOW);
    }

    else
    {
        printf(GREEN);
    }


    printf("%d%%", percentage);


    printf(RESET "\n");


}