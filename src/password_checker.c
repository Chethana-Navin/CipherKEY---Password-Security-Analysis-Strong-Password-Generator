#include <string.h>
#include <ctype.h>

#include "password_checker.h"


void analyzeStrength(char password[], PasswordReport *report)
{

    int score = 0;


    int length = strlen(password);

    report->passwordLength = length;



    for(int i = 0; password[i] != '\0'; i++)
    {

        if(isupper(password[i]))
        {
            report->hasUppercase = 1;
        }


        else if(islower(password[i]))
        {
            report->hasLowercase = 1;
        }


        else if(isdigit(password[i]))
        {
            report->hasNumbers = 1;
        }


        else
        {
            report->hasSymbols = 1;
        }

    }



    if(length >= 8)
        score++;


    if(length >= 12)
        score++;


    if(report->hasUppercase)
        score++;


    if(report->hasLowercase)
        score++;


    if(report->hasNumbers)
        score++;


    if(report->hasSymbols)
        score++;



    report->strengthScore = score;



    if(score <= 2)
    {
        strcpy(report->strengthLevel,"Weak");
    }


    else if(score <= 4)
    {
        strcpy(report->strengthLevel,"Medium");
    }


    else if(score == 5)
    {
        strcpy(report->strengthLevel,"Strong");
    }


    else
    {
        strcpy(report->strengthLevel,"Very Strong");
    }

}