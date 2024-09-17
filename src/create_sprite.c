/*
** EPITECH PROJECT, 2021
** create_sprite
** File description:
** Create sprites
*/

#include "defender.h"
#include "my.h"
#include <stdlib.h>

sfSprite *create_sprite(sfTexture *texture, sfVector2f pos)
{
    sfSprite *new_sprite = sfSprite_create();

    sfSprite_setPosition(new_sprite, pos);
    sfSprite_setTexture(new_sprite, texture, sfTrue);
    return new_sprite;
}