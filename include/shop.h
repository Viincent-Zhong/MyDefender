/*
** EPITECH PROJECT, 2021
** shop
** File description:
** Shop structure
*/

#ifndef SHOP_H_
#define SHOP_H_

#include <SFML/Graphics.h>

typedef struct shop_button_s {
    sfSprite *shop;
    int pos_x;
    int pos_y;
    int incre_x;
    int incre_y;
}but_shop;

typedef struct shop_s {
    but_shop **shop_but;
    sfSprite *board;

    sfSprite *piece;
    sfText *nbr_piece;

    int over;
    int last_sprite;
}shop_t;

#endif /* !SHOP_H_ */