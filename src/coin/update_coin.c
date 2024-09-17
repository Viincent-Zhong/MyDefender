/*
** EPITECH PROJECT, 2021
** update_coin
** File description:
** Update coin
*/

#include "defender.h"

char *int_to_str(int nb);

void update_coin(int coin, sfText **coin_text)
{
    char *str = int_to_str(coin);

    sfText_setString((*coin_text), str);
}