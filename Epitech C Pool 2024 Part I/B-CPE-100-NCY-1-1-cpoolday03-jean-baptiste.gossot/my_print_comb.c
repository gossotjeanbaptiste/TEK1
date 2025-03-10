/*
** EPITECH PROJECT, 2024
** my_print_comb
** File description:
** task05 day 03
*/

void put_comma(int i, int j, int k)
{
    if (i == '7' && j == '8' && k == '9'){
        my_putchar('\n');
    } else {
        my_putchar(',');
        my_putchar(' ');
    }
}

int incrementation(int i, int j)
{
    for (int k = '2'; k <= '9'; k++) {
        if (i < j && j < k) {
            my_putchar(i);
            my_putchar(j);
            my_putchar(k);
            put_comma(i, j, k);
        }
    }
}

int my_print_comb(void)
{
    for (int i = '0'; i <= '7'; i++) {
        for (int j = '1'; j <= '8'; j++) {
            incrementation(i, j);
        }
    }
}
