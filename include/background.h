/*
** EPITECH PROJECT, 2021
** background
** File description:
** Background structure
*/

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <SFML/Graphics.h>

typedef struct background_s
{
    sfSprite *bg_elem;
    float pos_x;
    float pos_y;
}bg_t;

typedef struct utilities {
    char **map;
    int map_x;
    int map_y;
    sfSprite *map_bg;
}map_t;

#endif /* !BACKGROUND_H_ */
