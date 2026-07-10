#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "keyboard_pattern_checker.h"


void checkKeyboardPatterns(char password[],
                           PasswordReport *report)
{

    char lowerPassword[100];


    // Convert password to lowercase
    for(int i = 0; password[i] != '\0'; i++)
    {
        lowerPassword[i] = tolower(password[i]);
    }

    lowerPassword[strlen(password)] = '\0';



    char *patterns[] =
    {
        "qwerty",
        "asdfgh",
        "zxcvbn",
        "123456",
        "654321",
        "abcdef",
        "qwertyui",
        "asdf123",
        "password",
        "admin"
    };


    int totalPatterns =
        sizeof(patterns) / sizeof(patterns[0]);



    for(int i = 0; i < totalPatterns; i++)
    {

        if(strstr(lowerPassword, patterns[i]) != NULL)
        {

            report->hasKeyboardPattern = 1;

            return;
        }

    }


    report->hasKeyboardPattern = 0;

}