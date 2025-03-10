/*
** EPITECH PROJECT, 2024
** test_my_revstr
** File description:
** test if the string is reversed
*/
#include <criterion/criterion.h>

Test(my_revstr, reverse_a_string)
{
    char destination[] = "abcdefgh";
    
    my_revstr(destination);
    cr_assert_str_eq("hgfedcba", destination);
}

