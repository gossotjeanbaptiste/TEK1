/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** test files for Epi-Template-C
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/shell.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(add, valid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *args[] = {"SENSOR", "Temperature", NULL};

    int result = add(&workshop, args);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("SENSOR n°0 - \"Temperature\" added.\n");
}

Test(add, invalid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *args[] = {"INVALID", "Temperature", NULL};

    int result = add(&workshop, args);
    cr_assert_eq(result, 84);
}

Test(del, valid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *add_args[] = {"SENSOR", "Temperature", NULL};
    char *del_args[] = {"0", NULL};

    add(&workshop, add_args);
    int result = del(&workshop, del_args);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("SENSOR n°0 deleted.\n");
}

Test(del, invalid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *del_args[] = {"0", NULL};

    int result = del(&workshop, del_args);
    cr_assert_eq(result, 84);
    cr_assert_stdout_eq_str("KO: no such hardware.\n");
}

Test(sort, valid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *add_args1[] = {"SENSOR", "Temperature", NULL};
    char *add_args2[] = {"SENSOR", "Pressure", NULL};
    char *sort_args[] = {"name", NULL};

    add(&workshop, add_args1);
    add(&workshop, add_args2);
    int result = sort(&workshop, sort_args);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("SENSOR n°1 - \"Pressure\"\nSENSOR n°0 - \"Temperature\"\n");
}

Test(sort, invalid_input, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *sort_args[] = {"invalid_field", NULL};

    int result = sort(&workshop, sort_args);
    cr_assert_eq(result, 84);
    cr_assert_stdout_eq_str("KO: invalid sort field.\n");
}

Test(disp, empty_workshop, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *disp_args[] = {NULL};

    int result = disp(&workshop, disp_args);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("No hardware to display.\n");
}

Test(disp, non_empty_workshop, .init = redirect_all_std)
{
    workshop_t workshop = {.head = NULL, .next_id = 0};
    char *add_args1[] = {"SENSOR", "Temperature", NULL};
    char *add_args2[] = {"SENSOR", "Pressure", NULL};
    char *disp_args[] = {NULL};

    add(&workshop, add_args1);
    add(&workshop, add_args2);
    int result = disp(&workshop, disp_args);
    cr_assert_eq(result, 0);
    cr_assert_stdout_eq_str("SENSOR n°0 - \"Temperature\"\nSENSOR n°1 - \"Pressure\"\n");
}
