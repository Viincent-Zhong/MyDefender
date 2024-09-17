/*
** EPITECH PROJECT, 2021
** struct_defender
** File description:
** Structures of defender
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef LOOSE_H_
#define LOOSE_H_

typedef struct loose_s
{
    bool button_pressed;
    sfSprite *background;
    sfSprite *menu;
    sfSprite *restart;
    sfSprite *exit;
}loose_t;

#endif
