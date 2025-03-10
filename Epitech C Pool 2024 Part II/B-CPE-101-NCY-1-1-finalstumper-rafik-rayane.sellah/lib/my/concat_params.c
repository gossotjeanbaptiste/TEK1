/*
** EPITECH PROJECT, 2024
** day08
** File description:
** concat
*/

#include <stdlib.h>

int my_strlen2(char const **str)
{
    int i = 0;
    int j = 0;
    int cpt = 0;

    while (str[i] != '\0') {
        j = 0;
        while (str[i][j] != '\0'){
            j++;
        }
        cpt += j;
        i++;
    }
    return (cpt);
}

char concat_params(int argc, char **argv)
{
    int len = my_strlen2(argv);
    int i = 0;
    int j = 0;
    int n = 0;
    char *c = malloc(sizeof(char) * (len + 1) + argc - 1);

    while (argv[i] != NULL) {
        j = 0;
        while (argv[i][j] != 0){
            c[n] = argv[i][j];
            j++;
            n++;
        }
        c[n] = '\n';
        n++;
        i++;
    }
    c[len + argc - 1] = '\0';
    return (c);
}

int main(void)
{
    concat_params(3, "hello world !");
    return 0;
}
