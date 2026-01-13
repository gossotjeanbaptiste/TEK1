/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-bsminiprintf-jean-baptiste.gossot
** File description:
** unit_test
*/

#include "bsprintf.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(sum_numbers, return_sum_numbers)
{
    int ret = sum_numbers(3, 21, 25, -4);
    cr_assert_eq(ret, 42);
}

Test(sum_strings_length, sum_str_length)
{
    int value = sum_strings_length(5, "Hello", "a", "toto", "", "plop");
    cr_assert_eq(value, 14);
}