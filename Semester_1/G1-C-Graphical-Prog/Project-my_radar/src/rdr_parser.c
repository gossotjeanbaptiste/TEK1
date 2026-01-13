/*
** EPITECH PROJECT, 2025
** Project-my_radar
** File description:
** rdr_parser
*/

#include "../include/my.h"
#include "../include/csfml_include.h"
#include "../include/ansi_color_code.h"
#include "csfml_include.h"

void parse_airplane(char *line, airplane_t **airplanes)
{
    char **array = my_str_to_word_array(line);
    airplane_t *new_airplane = malloc(sizeof(airplane_t));

    new_airplane->x1 = my_getnbr(array[0]);
    new_airplane->y1 = my_getnbr(array[1]);
    new_airplane->x2 = my_getnbr(array[2]);
    new_airplane->y2 = my_getnbr(array[3]);
    new_airplane->speed = my_getnbr(array[4]);
    new_airplane->takeoff_time = my_getnbr(array[5]);
    new_airplane->next = *airplanes;
    *airplanes = new_airplane;
    free(array);
}

void parse_tower(char *line, tower_t **towers)
{
    char **array = my_str_to_word_array(line);
    tower_t *new_tower = malloc(sizeof(tower_t));

    new_tower->x = my_getnbr(array[0]);
    new_tower->y = my_getnbr(array[1]);
    new_tower->radius = my_getnbr(array[2]);
    new_tower->next = *towers;
    *towers = new_tower;
    free(array);
}

void free_everything(airplane_t *airplanes, tower_t *towers)
{
    airplane_t *tmp_airplane;
    tower_t *tmp_tower;

    while (airplanes) {
        tmp_airplane = airplanes;
        airplanes = airplanes->next;
        free(tmp_airplane);
    }
    while (towers) {
        tmp_tower = towers;
        towers = towers->next;
        free(tmp_tower);
    }
}

void call(char *line, airplane_t **airplanes, tower_t **towers)
{
    char airplane_desc = 'A';
    char tower_desc = 'T';

    if (line[0] == airplane_desc)
        parse_airplane(line + 2, airplanes);
    else if (line[0] == tower_desc)
        parse_tower(line + 2, towers);
}

void parse_file(const char *filename, airplane_t **airplanes, tower_t **towers)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (!file) {
        write(2, "Failed to open file", 20);
        return;
    }
    read = getline(&line, &len, file);
    while (read != -1) {
        call(line, airplanes, towers);
        read = getline(&line, &len, file);
    }
    fclose(file);
    if (line)
        free(line);
}
