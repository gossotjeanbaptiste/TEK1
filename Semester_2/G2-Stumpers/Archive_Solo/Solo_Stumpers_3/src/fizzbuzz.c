/*
** EPITECH PROJECT, 2025
** solo_stumper3
** File description:
** fizzbuzz
*/
#include "../include/my.h"

void first_case_verif_annexe(int int_1_mod_3, int int_1_mod_5)
{
    if (int_1_mod_3 == 0 && int_1_mod_5 == 0) {
        printf("FizzBuzz\n");
    } else { 
        if (int_1_mod_3 == 0) {
            printf("Fizz\n");
        } else if (int_1_mod_5 == 0) {
            printf("Buzz\n");
        }
    }
}

void first_case_verif(int integer_1)
{
    int int_1_mod_3 = integer_1 % 3;
    int int_1_mod_5 = integer_1 % 5;

    if (int_1_mod_3 != 0 && int_1_mod_5 != 0) {
        printf("%d\n", integer_1);
    } else {
        first_case_verif_annexe(int_1_mod_3, int_1_mod_5);
    }
}

int printer(int integer_1)
{
    int integer_1_mod_3 = integer_1 % 3;
    int integer_1_mod_5 = integer_1 % 5;

    if (integer_1_mod_3 == 0 && integer_1_mod_5 == 0) {
        printf("FizzBuzz\n");
        return 0;
    }
    if (integer_1_mod_3 == 0) {
        printf("Fizz\n");
        return 0;
    }
    if (integer_1_mod_5 == 0) {
        printf("Buzz\n");
        return 0;
    }
    return 1;
}

int fizzbuzz(int i, int j)
{
    int integer_1 = i + 1;
    int integer_2 = j;
    int print = 0;

    first_case_verif(i);
    while (integer_1 <= integer_2) {
        print = printer(integer_1);
        if (print == 1) {
            printf("%d\n", integer_1);
        }
        integer_1++;
    }
    return 0;
}
