/*
** EPITECH PROJECT, 2021
** turret_detect_mobs
** File description:
** Turret detect the mobs
*/

#include "defender.h"

void kill_mobs(game_t *game, mobs_s **tmp, int i)
{
    remove_x(&game->mobs, i);
    switch ((*tmp)->atk) {
        case 1:
            game->coin += 3;
            break;
        case 2:
            game->coin += 40;
            break;
        case 3:
            game->coin += 5;
            break;
    }
    update_coin(game->coin, &game->coin_text);
    game->score->score += 1;
    change_score(game->score->score, game->score->text_score);
}

void got_attacked(game_t *game, mobs_s **tmp, turret_t *turret, int i)
{
    (*tmp)->health -= turret->atck;
    if ((*tmp)->speed > 40) {
        (*tmp)->speed -= ((*tmp)->speed * turret->slow) / 100;
        if ((*tmp)->speed <= 40)
            (*tmp)->speed = 40;
    }
    if ((*tmp)->health <= 0) {
        kill_mobs(game, tmp, i);
    }
}

void check_every_mobs(game_t *game, int i)
{
    mobs_s *tmp = game->mobs;
    int range = game->turret[i]->range;

    for (int j = 0, cmp_x, cmp_y; tmp != NULL; j++) {
        cmp_x = game->turret[i]->x - tmp->pos_x;
        cmp_y = game->turret[i]->y - tmp->pos_y;
        if (cmp_y >= -range && cmp_y <= range &&
        cmp_x >= -range && cmp_x <= range) {
            got_attacked(game, &tmp, game->turret[i], j);
            sfMusic_stop(game->turret[i]->attack_sound);
            sfMusic_play(game->turret[i]->attack_sound);
            return;
        }
        tmp = tmp->next;
    }
}

void mobs_in_range(game_t *game)
{
    for (int i = 0; game->turret[i] != NULL; i++)
        if (game->turret[i]->exist == true)
            check_every_mobs(game, i);
}

void turret_attack(game_t *game)
{
    game->timer->turret_as -= game->timer->delta_time;
    if (game->timer->turret_as <= 0) {
        mobs_in_range(game);
        game->timer->turret_as = TURRET_ATT;
    }
}