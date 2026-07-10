#include <stdio.h>
#include <string.h>

#include "common_password_checker.h"



void checkCommonPassword(char password[],
                         PasswordReport *report)
{

    FILE *file;

    char line[100];


    file = fopen("common_passwords.txt","r");


    if(file == NULL)
    {
        report->isCommonPassword = 0;
        return;
    }



    while(fgets(line,sizeof(line),file))
    {

        line[strcspn(line,"\n")] = '\0';


        if(strcmp(password,line)==0)
        {

            report->isCommonPassword = 1;

            fclose(file);

            return;
        }

    }


    report->isCommonPassword = 0;


    fclose(file);

}