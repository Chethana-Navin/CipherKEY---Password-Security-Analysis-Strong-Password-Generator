#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "password_generator.h"

void generatePassword()
{
    int length;

    printf("\nEnter password length (8 - 64): ");
    scanf("%d", &length);

    if(length < 8 || length > 64)
    {
        printf("Invalid length!\n");
        return;
    }

    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()-_=+[]{}<>?/";

    char all[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*()-_=+[]{}<>?/";

    srand(time(NULL));

    char password[65];

    password[0] = uppercase[rand() % 26];
    password[1] = lowercase[rand() % 26];
    password[2] = numbers[rand() % 10];
    password[3] = symbols[rand() % (sizeof(symbols)-1)];

    int total = sizeof(all) - 1;

    for(int i = 4; i < length; i++)
    {
        password[i] = all[rand() % total];
    }

    /* Fisher-Yates Shuffle */
    for(int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0';

    printf("\nGenerated Password:\n");
    printf("%s\n", password);
}