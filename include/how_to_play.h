/*
** EPITECH PROJECT, 2021
** struct_defender
** File description:
** Structures of defender
*/

#include <SFML/Graphics.h>
#include <stdbool.h>

#ifndef HOW_TO_PLAY_H_
#define HOW_TO_PLAY_H_

typedef struct htp_s
{
    bool button_pressed;
    sfSprite *background;
    sfSprite *back;
    sfText *txt;
}htp_t;

#endif
