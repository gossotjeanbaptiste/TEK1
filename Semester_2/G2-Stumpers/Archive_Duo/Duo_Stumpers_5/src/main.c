/*
** EPITECH PROJECT, 2025
** TEXT_COUNT
** File description:
** main
*/

#include "../include/text_count.h"

int find_index(const char character, const char_t *text)
{
    for (int i = 0; text[i].character; i++)
        if (text[i].character == character)
            return i;
    return -1;
}

int handle_index_search(const char character, const char_t *text)
{
    int index = find_index(character, text);

    if (index == -1)
        return 0;
    else
        return text[index].count;
}

void swap_str(char **str, const int i)
{
    char temp = 0;

    temp = *str[i - 1];
    *str[i - 1] = *str[i];
    *str[i] = temp;
}

int handle_search_with_t(char **str, const char_t *text)
{
    int first_idx = 0;
    int second_idx = 0;

    for (int i = 1; *str[i]; i++) {
        first_idx = find_index(*str[i - 1], text);
        second_idx = find_index(*str[i], text);
        if (first_idx == -1 && second_idx == -1)
            continue;
        if (first_idx == -1) {
            swap_str(str, i);
            continue;
        }
        if (text[first_idx].count < text[second_idx].count)
            swap_str(str, i);
    }
}

void swap_struct(char_t *text)
{
    unsigned int temp_v = 0;
    char temp_c = 0;

    for (int i = 1; text[i].count; i++) {
        if (text[i].count > text[i - 1].count) {
            temp_v = text[i].count;
            temp_c = text[i].character;
            text[i].count = text[i - 1].count;
            text[i].character = text[i - 1].character;
            text[i - 1].count = temp_v;
            text[i - 1].character = temp_c;
            i = 0;
        }
    }
}

void display_count(const char_t *text, const char *search)
{
    int to_search = search ? 1 : 0;

    if (!to_search)
        for (int i = 0; text[i].count; i++)
            printf("%c:%u\n", text[i].character, text[i].count);
    else {
        for (int i = 0; search[i]; i++)
            printf("%c:%u\n", search[i],
            handle_index_search(search[i], text));
    }       
}

static int verify_in_struct(const char chara, char_t *text)
{
    int i = 0;

    for (; text[i].character; i++) {
        if (chara == text[i].character) {
            text[i].count++;
            return RETURN_SUCCESS;
        }
    }
    text = realloc(text, sizeof(char_t) * (i + 1));
    if (!text)
        return RETURN_ERROR;
    text[i].character = chara;
    text[i].count = 1;
    return RETURN_SUCCESS;
}

static int verify_in_string(const char chara, const char *str, char_t *text)
{
    for (int i = 0; str[i]; i++)
        if (chara == str[i])
            return verify_in_struct(chara, text);
    return 0;
}

static int count_text_classic(const char *arg, args_t *flags)
{
    char_t *text = malloc(sizeof(char_t));

    if (!text)
        return RETURN_ERROR;
    text->character = 0;
    text->count = 0;
    for (int i = 0; arg[i]; i++) {
        verify_in_struct(arg[i], text);
    }
    if (flags)
        if (flags->flag_t)
            swap_struct(text);
    display_count(text, NULL);
    return RETURN_SUCCESS;
}

static int count_text_with_search(const char *arg, char *search, args_t *flags)
{
    char_t *text = malloc(sizeof(char_t));

    if (!text)
        return RETURN_ERROR;
    text->character = 0;
    text->count = 0;
    for (int i = 0; arg[i]; i++) {
        verify_in_string(arg[i], search, text);
    }
    if (flags->flag_t)
        handle_search_with_t(&search, text);
    display_count(text, search);
    return RETURN_SUCCESS;
}

int handle_two_arguments(char *arg)
{
    if (strlen(arg) == 0)
        return RETURN_SUCCESS;
    if (strncmp(arg, "-r", 2) == 0 || strncmp(arg, "-t", 2) == 0)
        return RETURN_SUCCESS;
    return count_text_classic(arg, NULL);
}

int handle_three_arguments(char *av[])
{
    args_t args = {0};

    for (int i = 1; av[i]; i++) {
        if (!strcmp(av[i], "-t")) {
            args.flag_t = 1;
            continue;
        }
        if (!strcmp(av[i], "-r")) {
            args.flag_r = 1;
            continue;
        }
        if (args.flag_t || args.flag_r)
            return count_text_classic(av[i], &args);
        return count_text_with_search(av[i], av[i + 1], &args);         
    }
}

int handle_four_arguments(void)
{
    return 0;
}

int main(int ac, char *av[])
{
    if (ac < 2) {
        fprintf(stderr,
                "Usage: %s [-r] [-t] STR [SEARCHED_CHARACTERS]",
                av[0]);
        return RETURN_ERROR;
    }
    if (ac == 2)
        return handle_two_arguments(av[1]);
    if (ac == 3)
        return handle_three_arguments(av);
    if (ac == 4)
        return handle_four_arguments();
}
