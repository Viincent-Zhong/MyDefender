/*
** EPITECH PROJECT, 2021
** attack_base
** File description:
** Attack the base
*/

#include "defender.h"

int is_on_base(game_t *game, mobs_s **tmp)
{
    if (game->map->map[(*tmp)->pos_y][(*tmp)->pos_x] == 'E' &&
        game->base->health_bar.width > 0) {
            return 1;
        }
    return 0;
}

void can_attack(game_t *game, mobs_s **tmp)
{
    game->base->health -= (*tmp)->atk;
    sfMusic_stop(game->base->sound_attack);
    sfMusic_play(game->base->sound_attack);
    game->base->health_bar.width = game->base->health * 3.85;
    if (game->base->health_bar.width <= 0)
        game->base->health_bar.width = 0;
    sfSprite_setTextureRect(game->base->health_bar_bs,
    game->base->health_bar);
}

void attack_base(game_t *game)
{
    mobs_s *tmp = game->mobs;

    for (int i = 0; tmp != NULL; i++, tmp = tmp->next) {
        if (is_on_base(game, &tmp) == 1)
            tmp->attack_speed -= game->timer->delta_time;
        if (tmp->attack_speed > 0)
            continue;
        tmp->attack_speed = AS;
        can_attack(game, &tmp);
        if (game->base->health <= 0) {
            game->game_status = death_menu;
            break;
        }
    }
}
