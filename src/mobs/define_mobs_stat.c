/*
** EPITECH PROJECT, 2021
** define_mobs_stat
** File description:
** Define mobs stat
*/

#include "defender.h"

void change_info_mobs_two(mobs_s *new_mobs, int value)
{
    if (value >= 8 && value <= 10) {
        new_mobs->atk = 2;
        new_mobs->health = 40;
        new_mobs->max_health = 40;
        new_mobs->speed = 75;
        new_mobs->rect.left = 540;
    }
}

void change_info_mobs(mobs_s *new_mobs, int value)
{
    if (value == 0 || value == 1 || value == 2) {
        new_mobs->atk = 3;
        new_mobs->health = 20;
        new_mobs->max_health = 20;
        new_mobs->speed = 125;
        new_mobs->rect.left = 0;
    }
    if (value >= 3 && value <= 7) {
        new_mobs->atk = 1;
        new_mobs->health = 10;
        new_mobs->max_health = 10;
        new_mobs->speed = 175;
        new_mobs->rect.left = 360;
    }
    change_info_mobs_two(new_mobs, value);
}