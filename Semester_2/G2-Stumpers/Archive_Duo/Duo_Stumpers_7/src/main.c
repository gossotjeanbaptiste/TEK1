/*
** EPITECH PROJECT, 2025
** hangman
** File description:
** main
*/

#include "../include/lingo.h"

static void print_winning_status(const bool win)
{
    if (win == true)
        printf("You won!\n");
    else
        printf("You lost!\n");
}

static char *obfuscate_word(const char *random_word)
{
    char *obfuscated_word = strdup(random_word);

    for (size_t i = 1; obfuscated_word[i]; i++)
        obfuscated_word[i] = '*';
    return obfuscated_word;
}

static void print_instructions(const char *obfuscated_word)
{
    printf("*: invalid letter\n");
    printf("?: incorrectly placed letter\n");
    printf("Will you find the secret word?\n");
    printf("%s\n", obfuscated_word);
}

static char *yes(FILE *file, char *random_word)
{
    if (!file)
        return NULL;
    random_word = get_random_word(file);
    fclose(file);
    if (!random_word)
        return NULL;
    return random_word;
}

static int play_lingo(const char *filepath)
{
    char *random_word = NULL;
    char *obfuscated_word = NULL;
    char *guess = NULL;
    FILE *file = fopen(filepath, "r");
    size_t round_number = 1;
    bool won = false;

    random_word = yes(file, random_word);
    if (!file || random_word == NULL)
        return RETURN_ERROR;
    obfuscated_word = obfuscate_word(random_word);
    print_instructions(obfuscated_word);
    for (; round_number < strlen(random_word); round_number++) {
        won = play_round(random_word, obfuscated_word, &guess, round_number);
        if (won)
            break;
    }
    print_winning_status(won);
    return RETURN_SUCCESS;
}

int main(int ac, const char *const av[])
{
    if (ac != 2)
        return RETURN_ERROR;
    srand(time(NULL));
    if (play_lingo(av[1]))
        return RETURN_ERROR;
    return RETURN_SUCCESS;
}
