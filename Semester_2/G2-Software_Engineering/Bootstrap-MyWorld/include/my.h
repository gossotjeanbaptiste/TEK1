/*
** EPITECH PROJECT, 2024
** my header files
** File description:
** declaration of all functions
*/
#include <stddef.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef MY_H
    #define MY_H
int randint(int min, int max);
char **allocate_tab(char *str);
void put_in_array(char *str, char **tab, int k);
void free_word_array(char **array);
int is_delimiter(char c, const char *delim);
char *find_token_end(char *str, const char *delim);
int my_atoi(const char *str);
int number_word(char *str);
void annexe_my_put_hex(int remainder, int is_upper, int nb, int res);
void annexe_my_putn_hex(int remainder, int is_upper, int nb, int res);
void annexe_to_my_sort_int_array(int integer1, int integer2);
int annexe_to_my_strstr(char const *to_find, int size_find, char *str);
int annexe_dos_to_my_strstr(char const *to_find, char *str, int i, int j);
void annexe_to_my_showmem(int i, char const *str, int size);
void annexe_to_my_showmem2(int i, char const *str, int size, char c);
void annexe_to_my_showmem3(int i, char const *str, int size, char c);
int my_putnbr_intmax(intmax_t num);
int annexe_my_putnbr_intmax(intmax_t num, char *buffer, int i);
int at_power(int n, int p);
int is_empty(char const *str);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
int my_isprint(int c);
void my_putchar(char c);
int my_put_float(double nb, int precision);
int second_my_put_float(int dec_part, double dec_multiplier, int precision,
    int current_precision);
int my_put_nbr(int nb);
int my_putn_nbr(int nb, int precision);
void my_puthex2(unsigned char n);
void my_puthex8(int n);
int my_put_hex(unsigned int nb, int is_upper, int precision);
int my_putn_hex(unsigned int nb, int is_upper, int precision);
int my_putstr(char const *str);
int my_putnstr(char const *str, int precision);
int my_put_size_t(size_t nb);
int my_put_long(long nb);
int my_put_long_double(long double nb);
int my_put_long_long(long long nb);
int my_put_short_int(short int nb);
int my_put_ssize_t(ssize_t nb);
int my_put_size_t(size_t nb);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_sort_int_array(int *tab, int size);
char *my_strchr(const char *str, int c);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void my_swap_char(char *a, char *b);
void my_reverse_str(char *str, int len);
int my_convert_num_to_str(unsigned int num, char *str);
int for_my_convert_num_to_str(int i, char *str);
double my_fabs(double num);
void handle_string(const char *format, va_list args);
void handle_integer(const char *format, va_list args);
void handle_char(va_list args);
void handle_hex(va_list args, int uppercase);
void handle_default(char c);
int handle_intmax(va_list args);
void handle_ptrdiff(va_list args);
void handle_hex_precision(va_list args, int is_upper, int precision);
void handle_integer_precision(const char *format, va_list args, int precision);
void handle_string_precision(const char *format, va_list args, int precision);
void handle_precision(const char *format, va_list args, int i);
void handle_precision2(const char *format, va_list args, int i, int precision);
void handle_precision3(const char *format, va_list args, int i, int precision);
void handle_precision_switch_case(const char *format, va_list args, int i,
    int precision);
int handle_unsigned_u(va_list args);
int handle_float_f(va_list args);
int handle_float_f_fraction(int frac_part, char *frac_part_str);
void handle_float_e(va_list args, char specifier);
int handle_float_e_second(char sign, double num, int exponent, char e_char);
int handle_pointer_p(va_list args);
int mini_printf(const char *format, ...);
void mini_printf_handle_string(const char *format, va_list args);
void mini_printf_handle_integer(const char *format, va_list args);
void mini_printf_handle_char(va_list args);
void mini_printf_handle_default(char c);
void mini_printf_handle_long(va_list args);
void mini_printf_verification_switch(const char *format, va_list args, int i);
void mini_vprintf(const char *format, va_list args);
int my_printf(const char *format, ...);
void my_vprintf(const char *format, va_list args);
int error_handler(const char *format, ...);
int count_format_specifiers(const char *format);
int count_arguments(va_list args, const char *format);
int char_to_digit(char c, int use_lowercase);
char digit_to_char(int digit, int use_lowercase);
int to_base_10(char *number, int base, int use_lowercase);
void from_base_10(int number, int base, char *result, int use_lowercase);
void convert_base(char *number, int base_from, int base_to, int use_lowercase);
void swap_index(char *result, int index, int i);
void verification_switch1(const char *format, va_list args, int i);
void verification_switch2(const char *format, va_list args, int i);
void verification_switch3(const char *format, va_list args, int i);
void verification_switch4(const char *format, va_list args, int i);
void verification_switch5(const char *format, va_list args, int i);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char *str);
char *my_strtok(char *str, const char *delim);
int mini_printf_handle_pointer_p(va_list args);
#endif /* !MY_H */
