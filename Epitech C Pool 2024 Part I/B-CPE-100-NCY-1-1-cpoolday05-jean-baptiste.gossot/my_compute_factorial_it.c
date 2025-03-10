/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it
** File description:
** n!
*/

int my_compute_factorial_it(int nb)
{
    int ans = 1;

    if (nb < 0) {
        return 0;
    }
    for (int i = 1; i <= nb; i++) {
	if (nb > 2147483647)
	    return 0;
        ans *= i;
    }
    return ans;
}
