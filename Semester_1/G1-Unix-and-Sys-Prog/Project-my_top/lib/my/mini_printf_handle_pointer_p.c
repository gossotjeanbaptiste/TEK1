/*
** EPITECH PROJECT, 2024
** Project-Organized
** File description:
** mini_printf_handle_pointer_p
*/
#include "my.h"

int mini_printf_handle_pointer_p(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long address = (unsigned long)ptr;
    int printed_chars = 0;

    if (ptr == NULL) {
        printed_chars += my_putstr("(nil)");
        return printed_chars;
    }
    printed_chars += my_putstr("0x");
    printed_chars += my_put_hex((unsigned int)address, 0, 0);
    return printed_chars;
}

void mini_printf_handle_long(va_list args)
{
    long i = va_arg(args, long);

    my_put_long(i);
}
