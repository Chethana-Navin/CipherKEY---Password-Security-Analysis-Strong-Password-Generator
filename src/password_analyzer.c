#include <stdio.h>

#include "password_analyzer.h"
#include "terminal_colors.h"

#include "password_checker.h"
#include "entropy_calculator.h"
#include "crack_time_estimator.h"
#include "common_password_checker.h"
#include "keyboard_pattern_checker.h"
#include "strength_meter.h"


PasswordReport analyzePassword(char password[])
{

    PasswordReport report = {0};


    analyzeStrength(password,&report);


    calculateEntropy(password,&report);


    calculateCrackTime(password,&report);


    checkCommonPassword(password,&report);

    checkKeyboardPatterns(password,&report);


    return report;

}



void displayReport(PasswordReport report)
{

    printf("\n");

    printf(CYAN BOLD);
    printf("========================================\n");
    printf("        CipherKey Security Report\n");
    printf("========================================\n");
    printf(RESET);



    printf("\nPassword Length : %d\n",
            report.passwordLength);



    printf("\nStrength : ");


    if(report.strengthScore >= 5)
    {
        printf(GREEN "%s\n" RESET,
        report.strengthLevel);
    }

    else if(report.strengthScore >= 3)
    {
        printf(YELLOW "%s\n" RESET,
        report.strengthLevel);
    }

    else
    {
        printf(RED "%s\n" RESET,
        report.strengthLevel);
    }

    displayStrengthMeter(report);



    printf("\nEntropy : %.2f bits\n",
            report.entropy);



    printf("Crack Time : %.2f years\n",
            report.crackTimeYears);



    printf("\nCommon Password : ");

    printf("\nKeyboard Pattern : ");

    if(report.hasKeyboardPattern)
    {
        printf(RED "Detected\n" RESET);
    }
    else
    {
        printf(GREEN "Not Detected\n" RESET);
    }

    if(report.isCommonPassword)
    {
        printf(RED "YES\n" RESET);
    }

    else
    {
        printf(GREEN "NO\n" RESET);
    }



    printf("\n========================================\n");

}