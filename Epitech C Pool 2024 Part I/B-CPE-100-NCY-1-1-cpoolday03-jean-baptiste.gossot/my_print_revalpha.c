/*
** EPITECH PROJECT, 2024
** my_print_revalpha
** File description:
** print reverse alphabet
*/

void my_print_revalpha(void)
{
    for (int i = 122; i >= 97; i--){
        my_putchar(i);
    }
    my_putchar('\n');
}
