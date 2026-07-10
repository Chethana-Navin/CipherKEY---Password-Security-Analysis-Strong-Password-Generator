#ifndef PASSWORD_ANALYZER_H
#define PASSWORD_ANALYZER_H


#include "password_report.h"


PasswordReport analyzePassword(char password[]);


void displayReport(PasswordReport report);


#endif