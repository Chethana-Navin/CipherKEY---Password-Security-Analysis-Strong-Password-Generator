#ifndef PASSWORD_REPORT_H
#define PASSWORD_REPORT_H


typedef struct
{
    int strengthScore;

    char strengthLevel[20];

    double entropy;

    double crackTimeYears;

    int isCommonPassword;


    int hasUppercase;
    int hasLowercase;
    int hasNumbers;
    int hasSymbols;

    int hasKeyboardPattern;

    int passwordLength;


} PasswordReport;


#endif