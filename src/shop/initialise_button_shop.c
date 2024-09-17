/*
** EPITECH PROJECT, 2021
** initialise_button_shop
** File description:
** Intialise the button
*/

#include "defender.h"

sfVector2f shop_button_pos(int posx, int posy)
{
    sfVector2f pos = {posx, posy};
    return pos;
}

but_shop *create_shop_button(sfSprite *sprite,
sfVector2f incre, sfVector2f pos)
{
    but_shop *shop = malloc(sizeof(but_shop));

    shop->shop = sprite;
    shop->incre_x = incre.x;
    shop->incre_y = incre.y;
    shop->pos_x = pos.x;
    shop->pos_y = pos.y;
    return shop;
}