/*
** EPITECH PROJECT, 2021
** mouse_collision
** File description:
** Mouse collision
*/

#include "defender.h"
#include "filepath.h"

int detect_collision(sfVector2i mouse_pos, int x, int y)
{
    if (mouse_pos.x >= x && mouse_pos.x <= x + 60 &&
    mouse_pos.y >= y && mouse_pos.y <= y + 60)
        return 1;
    return 0;
}

int detect_mouse(sfVector2i mouse_pos, sfVector2f pos, sfVector2f incre)
{
    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + incre.x &&
    mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + incre.y)
        return 1;
    return 0;
}