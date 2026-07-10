#include <stdio.h>
#include <string.h>
#include "password_checker.h"
#include "password_generator.h"
#include "entropy_calculator.h"
#include "crack_time_estimator.h"
#include "common_password_checker.h"
#include "password_analyzer.h"
#include "password_analyzer.h"
#include "password_input.h"
#include "report_exporter.h"

int main()
{
    int choice;
    char password[100];
    PasswordReport lastReport;

    int reportAvailable = 0;

    while(1)
    {
        printf("\n=====================================\n");
        printf("        CipherKey     \n");
        printf(" Password Security Toolkit\n");
        printf("=====================================\n");

        printf("1. Analyze Password\n");
        printf("2. Generate Strong Password\n");
        printf("3. Export Security Report\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        getchar();

        switch(choice)
        {

            case 1:

                getHiddenPassword(password, sizeof(password));


                lastReport = analyzePassword(password);


                reportAvailable = 1;


                displayReport(lastReport);

                break;


            case 2:

                generatePassword();

                break;


            case 3:
            
                if(reportAvailable)
                {
                    exportReport(lastReport);
                }

                else
                {
                    printf("\nNo report available.\n");
                    printf("Analyze a password first.\n");
                }

                break;

            case 4:

                printf("\nThank you for using CipherKey!\n");

                return 0;


            default:

                printf("\nInvalid choice!\n");

        }
    }

    return 0;
}