/*
** EPITECH PROJECT, 2025
** yes
** File description:
** yes
*/

#include "../include/lingo.h"

static char *replace(const char *word, const char *input,
    char *blinded_word, const int i)
{
    for (int j = 0; input[j]; j++) {
        if (word[i] == input[j] && i != j)
            blinded_word[j] = '?';
    }
    return blinded_word;
}

static bool right_len_motus(const char *random_word, const char *guess,
    char *obfuscated_word, size_t round_number)
{
    for (size_t i = 0; random_word[i]; i++)
        obfuscated_word = replace(random_word, guess, obfuscated_word, i);
    for (size_t i = 0; random_word[i]; i++)
        if (random_word[i] == guess[i])
            obfuscated_word[i] = random_word[i];
    printf("%s\n\n", obfuscated_word);
    round_number++;
    if (!strcmp(obfuscated_word, random_word))
        return true;
    return false;
}

bool validate_guess(const char *guess,
    char *obfuscated_word, const char *random_word, size_t round_count)
{
    size_t len_word = strlen(random_word);
    size_t len_input = strlen(guess);

    if (len_word > len_input)
        printf("Word too short. Retry.\n>");
    if (len_word < len_input)
        printf("Word too long. Retry.\n>");
    if (len_word == len_input)
        return right_len_motus(random_word, guess,
            obfuscated_word, round_count);
    return false;
}

bool play_round(const char *random_word, char *obfuscated_word,
    char **guess, size_t round_count)
{
    printf("Round %zu\n>", round_count);
    if (read_guess(guess) != -1) {
        if (validate_guess(*guess, obfuscated_word, random_word, round_count))
            return true;
        else
            return false;
    }
    fprintf(stderr, "Invalid input\n");
    return false;
}
