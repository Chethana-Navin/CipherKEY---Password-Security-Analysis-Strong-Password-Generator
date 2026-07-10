#include <string.h>
#include <math.h>
#include <ctype.h>

#include "entropy_calculator.h"


void calculateEntropy(char password[], PasswordReport *report)
{

    int pool = 0;


    if(report->hasUppercase)
        pool += 26;


    if(report->hasLowercase)
        pool += 26;


    if(report->hasNumbers)
        pool += 10;


    if(report->hasSymbols)
        pool += 32;



    if(pool > 0)
    {

        report->entropy =
            strlen(password) *
            (log(pool)/log(2));

    }

    else
    {
        report->entropy = 0;
    }

}