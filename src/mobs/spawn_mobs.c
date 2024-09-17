/*
** EPITECH PROJECT, 2021
** spawn_mobs
** File description:
** Spawn mobs
*/

#include "defender.h"

void spawn_mobs(game_t *game)
{
    game->timer->spawn_timer -= game->timer->delta_time;
    if (game->timer->spawn_timer <= 0) {
        initialise_mobs(game);
        game->timer->spawn_timer = SPAWN_RESET;
    }
}