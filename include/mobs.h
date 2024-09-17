/*
** EPITECH PROJECT, 2021
** mobs
** File description:
** Mobs structure
*/

#ifndef MOBS_H_
#define MOBS_H_

#define TIMEOUT_RESET 1.f
#define AS 4.f

#include <SFML/Graphics.h>

typedef struct mobs_structure {
    sfSprite *s_mobs;
    sfIntRect rect;
    int atk;
    int health;
    int max_health;
    float speed;
    float step;
    int pos_x;
    int pos_y;
    struct mobs_structure *next;
    float timeout;
    float attack_speed;
    sfText *txt;
}mobs_s;

typedef struct mobs_spawn_point {
    int **spawn;
}spawn_t;

#endif /* !MOBS_H_ */
