#include <math.h>
#include <string.h>

#include "crack_time_estimator.h"



void calculateCrackTime(char password[],
                        PasswordReport *report)
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



    double combinations =
        pow(pool, strlen(password));



    double seconds =
        combinations / 10000000000.0;



    report->crackTimeYears =
        seconds / 31536000;

}