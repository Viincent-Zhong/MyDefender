/*
** EPITECH PROJECT, 2021
** struct_defender
** File description:
** Structures of defender
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef PAUSE_H_
#define PAUSE_H_

typedef struct pause_s
{
    bool button_pressed;
    sfSprite *background;
    sfSprite *play;
    sfSprite *menu;
    sfSprite *exit;
}pause_t;

#endif
