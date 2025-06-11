/*
** EPITECH PROJECT, 2025
** crocus
** File description:
** graphic_art header
*/

#ifndef GRAPHIC_ART_H_
    #define GRAPHIC_ART_H_

typedef struct flag_s {
    char *flag_n;
    char *flag_s;
}flag_t;

int graph_zero(const char c);
int graph_one(const char c);
int graph_two(const char c);
int graph_three(const char c);
int graph_four(const char c);
int graph_five(const char c);
int graph_six(const char c);
int graph_seven(const char c);
int graph_eight(const char c);
int graph_nine(const char c);
void handle_specifier(int ac, char const * const *av,
    flag_t *flags);
#endif /* !GRAPHIC_ART_H_ */
