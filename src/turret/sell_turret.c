/*
** EPITECH PROJECT, 2021
** sell_turret
** File description:
** Sell a turret
*/

#include "defender.h"

void sell_turret(game_t *game, int i)
{
    int gain = ((game->turret[i]->which + 1) * 50) / 2;

    game->coin += gain;
    update_coin(game->coin, &game->coin_text);
    game->drag->turret_pos[i]->dispo = 0;
    game->turret[i]->exist = false;
    game->turret[i]->s_turr = NULL;
}