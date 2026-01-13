/*
** EPITECH PROJECT, 2024
** btree
** File description:
** struct file for binary tree
*/

#ifndef BTREE_H
#define BTREE_H
typedef struct btree {
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;
#endif
