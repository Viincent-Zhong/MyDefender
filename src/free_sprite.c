/*
** EPITECH PROJECT, 2021
** free_sprite
** File description:
** Free sprite
*/

#include "defender.h"

void free_sprite(sfSprite **sprite)
{
    if ((*sprite) != NULL)
        sfSprite_destroy((*sprite));
}

void free_music(sfMusic **music)
{
    if ((*music) != NULL)
        sfMusic_destroy((*music));
}