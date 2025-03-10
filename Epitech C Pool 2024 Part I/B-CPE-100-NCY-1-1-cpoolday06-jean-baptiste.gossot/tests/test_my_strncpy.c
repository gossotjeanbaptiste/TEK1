/*
** EPITECH PROJECT, 2024
** test_my_strncpy
** File description:
** test if the str is well copied in another variable
*/
#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[5] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
