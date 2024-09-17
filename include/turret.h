/*
** EPITECH PROJECT, 2021
** turret.h
** File description:
** turret structure
*/

#ifndef TURRET_H_
#define TURRET_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef enum turret_which {
    far,
    dmg,
    slow,
    mix
}turret_nbr;

typedef struct turret_s
{
    int atck;
    int range;
    int slow;
    int level;

    int x;
    int y;
    sfSprite *s_turr;
    int which;
    bool exist;
    sfMusic *attack_sound;
}turret_t;

typedef struct turret_pos {
    int turret_posx;
    int turret_posy;
    int dispo;
}t_pos;

typedef struct drag_turret
{
    t_pos **turret_pos;
    sfSprite *drag;
    int nbr_turret;
    int drag_status;
    int over;
    int last_turret;
}drag_t;

#endif /* !TURRET_H_ */
