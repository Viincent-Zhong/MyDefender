/*
** EPITECH PROJECT, 2021
** int_to_str
** File description:
** Convert an int to a string
*/

#include <stdlib.h>

char *my_revstr(char *str)
{
    int i = 0;
    int a = 0;
    int b;
    int stock;

    while (str[i] != '\0') {
        i = i + 1;
    }
    b = i - 1;
    while (b > a) {
        stock = str[a];
        str[a] = str[b];
        str[b] = stock;
        b = b - 1;
        a = a + 1;
    }
    return str;
}

char *int_to_str(int nb)
{
    int res = nb;
    char *str;
    int i = 0;

    if (nb == 0)
        return "0";
    while (res > 0) {
        res = res / 10;
        i += 1;
    }
    str = malloc(sizeof(int) * i + 1);
    for (int nbr = nb, j = 0; nbr > 0; j++, nbr /= 10)
        str[j] = (nbr % 10) + '0';
    str[i] = 0;
    return my_revstr(str);
}
