/*
** EPITECH PROJECT, 2024
** Bootstrap-my_top
** File description:
** my_getloadavg
*/

#include "../include/call.h"
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int my_getloadavg(double loadavg[], int nelem,
    struct getloadavg_s *getloadavg_t)
{
    getloadavg_t->line = NULL;
    getloadavg_t->len = 0;
    getloadavg_t->i = 0;
    getloadavg_t->file = fopen("/proc/loadavg", "r");
    if (verif(nelem, getloadavg_t) == -1)
        return -1;
    loop(getloadavg_t, loadavg, nelem);
    fclose(getloadavg_t->file);
    free(getloadavg_t->line);
    getloadavg_t->output = malloc(nelem * sizeof(double));
    if (getloadavg_t->output == NULL)
        return -1;
    for (getloadavg_t->i = 0; getloadavg_t->i < nelem; getloadavg_t->i++) {
        getloadavg_t->output[getloadavg_t->i] = loadavg[getloadavg_t->i];
        printf("Load average %d: %f\n", getloadavg_t->i + 1,
        getloadavg_t->output[getloadavg_t->i]);
    }
    free(getloadavg_t->output);
    return 0;
}

int verif(int nelem, struct getloadavg_s *getloadavg_t)
{
    if (nelem < 1 || nelem > 3 || getloadavg_t->file == NULL)
        return -1;
    getloadavg_t->read = getline(&getloadavg_t->line,
    &getloadavg_t->len, getloadavg_t->file);
    if (getloadavg_t->read == -1) {
        fclose(getloadavg_t->file);
        return -1;
    }
    return 0;
}

void loop(struct getloadavg_s *getloadavg_t, double loadavg[], int nelem)
{
    getloadavg_t->token = strtok(getloadavg_t->line, " ");
    while (getloadavg_t->token != NULL && getloadavg_t->i < nelem) {
        loadavg[getloadavg_t->i] = atof(getloadavg_t->token);
        getloadavg_t->token = strtok(NULL, " ");
        getloadavg_t->i++;
    }
}
