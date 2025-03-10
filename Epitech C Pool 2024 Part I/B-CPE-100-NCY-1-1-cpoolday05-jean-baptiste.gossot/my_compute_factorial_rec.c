/*
** EPITECH PROJECT, 2024
** my_compute_factorial_rec
** File description:
** n! but recursive
*/
int my_compute_factorial_rec(int nb)
{
    if (nb < 0)
        return 0;
    if (nb < 1) {
        return 1;
    } else {
        return nb * my_compute_factorial_rec(nb - 1);
    }
}
