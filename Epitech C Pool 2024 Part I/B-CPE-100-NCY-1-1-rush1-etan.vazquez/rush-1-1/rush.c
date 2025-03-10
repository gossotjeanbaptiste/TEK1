/*
** EPITECH PROJECT, 2024
** Rush
** File description:
** 1
*/

void print_char(int x, int y, int sizex, int sizey)
{
    if ((x == 1 || x == sizex) && (y == 1 || y == sizey))
        my_putchar('o');
    if ((x == 1 || x == sizex) && (y != 1 && y != sizey))
        my_putchar('-');
    if ((x != 1 && x != sizex) && (y == 1 || y == sizey))
        my_putchar('|');
    if ((x != 1 && x != sizex) && (y != 1 && y != sizey))
        my_putchar(' ');
}

void rush(int sizey, int sizex)
{
    if (sizex <= 0 || sizey <= 0 || sizex > 2147483647 || sizey > 2147483647) {
        write(2, "Invalid size\n", 13);
        return;
    }
    for (int x = 1; x <= sizex; x++) {
        for (int y = 1; y <= sizey; y++) {
            print_char(x, y, sizex, sizey);
        }
        my_putchar('\n');
    }
}
