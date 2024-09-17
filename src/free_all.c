/*
** EPITECH PROJECT, 2021
** free_all
** File description:
** Free all structures
*/

#include "defender.h"

void free_two(game_t *game)
{
    if (game->map != NULL) {
        free_sprite(&game->map->map_bg);
        for (int i = 0; game->map->map[i]; i++)
            free(game->map->map[i]);
        free(game->map);
    }
    if (game->pause != NULL) {
        free_sprite(&game->pause->play);
        free_sprite(&game->pause->menu);
        free_sprite(&game->pause->exit);
        free_sprite(&game->pause->background);
        free(game->pause);
    }
    if (game->s_map != NULL) {
        for (int i = 0; game->s_map[i]; i++) {
            free_sprite(&game->s_map[i]->bg_elem);
            free(game->s_map[i]);
        }
        free(game->s_map);
    }
}

void free_three(game_t *game)
{
    if (game->shop != NULL) {
        free_sprite(&game->shop->board);
        free_sprite(&game->shop->piece);
        for (int i = 0; game->shop->shop_but[i]; i++) {
            free_sprite(&game->shop->shop_but[i]->shop);
            free(game->shop->shop_but[i]);
        }
        free(game->shop);
    }
    if (game->spawner != NULL) {
        for (int i = 0; game->spawner->spawn[i]; i++)
            free(game->spawner->spawn[i]);
        free(game->spawner);
    }
    if (game->timer != NULL) {
        if (game->timer->clock)
            sfClock_destroy(game->timer->clock);
        free(game->timer);
    }
}

void free_four(game_t *game)
{
    if (game->drag != NULL) {
        free_sprite(&game->drag->drag);
        for (int i = 0; game->drag->turret_pos[i]; i++)
            free(game->drag->turret_pos[i]);
        free(game->drag->turret_pos);
        free(game->drag);
    }
    if (game->turret != NULL) {
        for (int i = 0; game->turret[i]; i++) {
            free_sprite(&game->turret[i]->s_turr);
            free_music(&game->turret[i]->attack_sound);
            free(game->turret[i]);
        }
        free(game->turret);
    }
    if (game->mobs != NULL)
        free_list(game->mobs);
}

void free_one(game_t *game)
{
    if (game->menu != NULL) {
        free_sprite(&game->menu->background);
        free_sprite(&game->menu->exit);
        free_sprite(&game->menu->play);
        free_sprite(&game->menu->menu);
        free(game->menu);
    }
    if (game->base != NULL) {
        free_music(&game->base->sound_attack);
        free_sprite(&game->base->health_bar_bs);
        free_sprite(&game->base->health_bar_s);
        free(game->base);
    }
    free_music(&game->bg_music);
}

void free_all(game_t *game)
{
    change_max_score(game->score->max_score, game->score->score);
    free_one(game);
    free_two(game);
    free_three(game);
    free_four(game);
    free_five(game);
}