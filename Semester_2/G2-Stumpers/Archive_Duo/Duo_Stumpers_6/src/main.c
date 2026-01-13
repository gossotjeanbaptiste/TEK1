/*
** EPITECH PROJECT, 2025
** hangman
** File description:
** main
*/

#include "../include/hangman.h"

static bool verify_args(const int ac)
{
    if (ac < 2 || ac > 3)
        return true;
    return false;
}

static bool is_valid_word(const char *word)
{
    for (int i = 0; word[i]; i++)
        if (my_isspace(word[i]))
            return false;
    return true;
}

static bool is_valid_file(FILE *file)
{
    size_t len = 0;
    char *line = NULL;
    bool one_valid_word = false;

    if (!file)
        return true;
    while (getline(&line, &len, file) != -1) {
        if (line[0] != '\n')
            one_valid_word |= true;
        if (!is_valid_word(line))
            return false;
    }
    free(line);
    rewind(file);
    return one_valid_word;            
}

static size_t count_lines(FILE *file)
{
    char *line = NULL;
    size_t len = 0;
    size_t line_count = 0;

    while (getline(&line, &len, file) != -1)
        line_count++;
    free(line);
    return line_count;
}

void loop(const char *random_word, char *obfuscated_word, size_t *tries)
{
     while (verify_word(random_word, obfuscated_word, tries) != true) {
        if (!strcmp(random_word, obfuscated_word)) {
            printf("\nCongratulations!\n");
            break;
            }
        if (*tries == 0) {
            printf("Tries: %zu\n", *tries);
            printf("\nYou lost!\n");
            break;
        }
    }
}

static bool play_hangman(FILE *file, size_t *tries)
{
    size_t line_count = count_lines(file);    
    long random_idx = rand() % line_count;
    char *random_word = NULL;
    char *obfuscated_word = NULL;

    rewind(file);
    random_word = read_line(file, random_idx + 1);
    while (random_word && random_word[0] == '\n') {
        random_idx = rand() % line_count;
        rewind(file);
        random_word = read_line(file, random_idx + 1);
    }
    random_word[strlen(random_word) - 1] = '\0';
    obfuscated_word = obfuscate_word(random_word);
    loop(random_word, obfuscated_word, tries);
    printf("The word is %s and %s\n", random_word, obfuscated_word);
    free(random_word);
    free(obfuscated_word);
    return true;
}

int main(int ac, const char *const av[])
{

    FILE *file = NULL;
    size_t tries = 10;

    if (verify_args(ac))
        return 84;
    file = fopen(av[1], "r");
    if (!is_valid_file(file)) {
        fclose(file);
        return 84;
    }
    srand(time(NULL));
    if (!play_hangman(file, &tries)) {
        fclose(file);
        return 84;
    }
    fclose(file);
    
}
