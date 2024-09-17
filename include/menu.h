/*
** EPITECH PROJECT, 2021
** struct_defender
** File description:
** Structures of defender
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef MENU_H_
#define MENU_H_

typedef struct menu_s
{
    bool button_pressed;
    sfSprite *background;
    sfSprite *play;
    sfSprite *menu;
    sfSprite *exit;
}menu_t;

#endif
