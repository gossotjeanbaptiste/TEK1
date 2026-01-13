/*
** EPITECH PROJECT, 2024
** mylist
** File description:
** create a structure for my list
*/

#ifndef MYLIST_H
    #define MYLIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif /* MYLIST_H */
