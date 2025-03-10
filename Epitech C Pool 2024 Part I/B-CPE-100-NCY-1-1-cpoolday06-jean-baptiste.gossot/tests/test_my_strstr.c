/*
** EPITECH PROJECT, 2024
** test_my_strstr
** File description:
** test if it copy the str in another str
*/
#include <criterion/criterion.h>

Test(my_strstr, copy_a_str_into_another_one)
{
    char str[] = "abcdef";

    my_strstr(str, "def");
    cr_assert_str_eq("def", str);
}
