/*
** EPITECH PROJECT, 2024
** Bootstrap-Organized
** File description:
** random_quick_sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            my_swap(&arr[i], &arr[j]);
        }
    }
    my_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int random_partition(int arr[], int low, int high)
{
    int n = high - low + 1;
    int pivot = rand() % n;

    my_swap(&arr[low + pivot], &arr[high]);
    return partition(arr, low, high);
}

void random_quick_sort(int arr[], int low, int high)
{
    int pi = 0;

    if (low < high) {
        pi = random_partition(arr, low, high);
        random_quick_sort(arr, low, pi - 1);
        random_quick_sort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        mini_printf("%d ", arr[i]);
    }
    mini_printf("\n");
}
