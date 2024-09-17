/*
** EPITECH PROJECT, 2021
** struct_defender
** File description:
** Structures of defender
*/

#ifndef STRUCT_DEFENDER_H_
#define STRUCT_DEFENDER_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "menu.h"
#include "turret.h"
#include "mobs.h"
#include "background.h"
#include "shop.h"
#include "time.h"
#include "base.h"
#include "pause.h"
#include "score.h"
#include "loose.h"
#include "how_to_play.h"

typedef enum game_status {
    start_menu,
    start_game,
    menu_pause,
    htp_menu,
    death_menu,
    win_menu,
    exit_status
}game_stat;

typedef struct game_s
{
    sfRenderWindow *window;
    sfEvent event;

    spawn_t *spawner;
    map_t *map;
    mobs_s *mobs;
    bg_t **s_map;

    drag_t *drag;
    turret_t **turret;
    shop_t *shop;
    time_handle_t *timer;

    menu_t *menu;
    loose_t *loose;

    htp_t *htp;

    pause_t *pause;

    int random_seed;
    int game_status;
    int coin;
    sfText *coin_text;
    base_t *base;
    score_t *score;
    sfMusic *bg_music;
}game_t;

#endif /* !STRUCT_DEFENDER_H_ */
