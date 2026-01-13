/*
** EPITECH PROJECT, 2024
** rush1-3
** File description:
** rush 1 c pool 2024
*/

void print_char(int x, int y, int sizex, int sizey)
{
    if ((x == 1) && (y == 1))
        my_putchar('A');
    if ((x == sizex) && (y == sizey))
        my_putchar('C');
    if ((x == sizex) && (y == 1))
        my_putchar('C');
    if ((x == 1) && (y == sizey))
        my_putchar('A');
    if ((x == 1 || x == sizex) && (y != 1 && y != sizey))
        my_putchar('B');
    if ((x != 1 && x != sizex) && (y == 1 || y == sizey))
        my_putchar('B');
    if ((x != 1 && x != sizex) && (y != 1 && y != sizey))
        my_putchar(' ');
}

void print_rush(int sizex, int sizey)
{
    for (int x = 1; x <= sizex; x++) {
        for (int y = 1; y <= sizey; y++) {
            print_char(x, y, sizex, sizey);
        }
        my_putchar('\n');
    }
}

void print_column(int sizex)
{
    for (int i = 0; i < sizex; i++) {
        my_putchar('B');
        my_putchar('\n');
    }
}

void rush(int sizey, int sizex)
{
    if (sizex <= 0 || sizey <= 0 || sizex > 2147483647 || sizey > 2147483647) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (sizex == 1) {
        for (int i = 0; i < sizey; i++)
            my_putchar('B');
        my_putchar('\n');
    } else if (sizey == 1) {
        print_column(sizex);
    } else {
        print_rush(sizex, sizey);
    }
}
