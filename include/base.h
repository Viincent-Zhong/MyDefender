/*
** EPITECH PROJECT, 2021
** base
** File description:
** Base struct
*/

#ifndef BASE_H_
#define BASE_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct base_s {
    int health;
    int pos_x;
    int pos_y;
    sfIntRect health_bar;
    sfSprite *health_bar_s;
    sfSprite *health_bar_bs;
    sfMusic *sound_attack;
}base_t;

#endif /* !BASE_H_ */