/*
** EPITECH PROJECT, 2024
** my_print_digits
** File description:
** show digits from 0 to 9 with the ascii table
*/

void my_print_digits(void)
{
    for (int i = '0'; i <= '9'; i++) {
    my_putchar(i);
    }
    my_putchar('\n');
}
