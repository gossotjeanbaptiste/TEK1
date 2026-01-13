/*
** EPITECH PROJECT, 2024
** my_print_comb2
** File description:
** display twice two digit number with ascending order
*/
void annexe(int i, int j)
{
    while (j <= 99) {
    my_putchar((i / 10) + '0');
    my_putchar((i % 10) + '0');
    my_putchar(' ');
    my_putchar((j / 10) + '0');
    my_putchar((j % 10) + '0');
    if (i != 99 || j != 99) {
        my_putchar(',');
        my_putchar(' ');
        }
        j++;
    }
}

int my_print_comb2(void)
{
    int i = 0;
    int j;

    while (i <= 99) {
        j = i;
        annexe(i, j);
        i++;
    }
    return 0;
}
