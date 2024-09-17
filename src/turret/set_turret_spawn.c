/*
** EPITECH PROJECT, 2021
** set_turret_spawn
** File description:
** Set the turrets spawn
*/

#include "defender.h"

void set_turret_point(game_t *game)
{
    int t = 0;

    game->drag->turret_pos = malloc(sizeof(t_pos *) *
    (game->drag->nbr_turret + 1));
    for (int i = 0, j = 0; game->map->map[i] != NULL; j++) {
        if (game->map->map[i][j] == 'T') {
            game->drag->turret_pos[t] = malloc(sizeof(t_pos));
            game->drag->turret_pos[t]->turret_posx = j * 60;
            game->drag->turret_pos[t]->turret_posy = i * 60;
            game->drag->turret_pos[t]->dispo = 0;
            t++;
        }
        if (game->map->map[i][j] == '\0') {
            i++;
            j = 0;
        }
    }
    game->drag->turret_pos[t] = NULL;
}

void create_turret(game_t *game)
{
    int i = 0;

    game->turret = malloc(sizeof(turret_t *) * (game->drag->nbr_turret + 2));
    for (; i <= game->drag->nbr_turret; i++) {
        game->turret[i] = malloc(sizeof(turret_t));
        game->turret[i]->s_turr = NULL;
        game->turret[i]->exist = false;
        game->turret[i]->which = -1;
        game->turret[i]->attack_sound = NULL;
    }
    game->turret[i] = NULL;
}