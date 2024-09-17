/*
** EPITECH PROJECT, 2021
** initialise_coin
** File description:
** Intialise the coin
*/

#include "defender.h"

void initialise_coin(int *coin, sfText **text)
{
    sfFont *font = sfFont_createFromFile("image/Font.ttf");
    sfVector2f pos = {1300, 905};

    (*coin) = 500;
    (*text) = sfText_create();
    sfText_setFont((*text), font);
    update_coin((*coin), text);
    sfText_setColor((*text), sfBlack);
    sfText_setCharacterSize((*text), 50);
    sfText_setPosition((*text), pos);
}