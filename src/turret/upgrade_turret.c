/*
** EPITECH PROJECT, 2021
** upgrade_turret
** File description:
** Upgrade a turret
*/

#include "defender.h"
#include "tower_path.h"

void upgrade_turret_stat_two(game_t *game, int i, char **texture_path)
{
    if (game->turret[i]->which == 3) {
        *texture_path = tower_mix_path[game->turret[i]->level];
        game->turret[i]->atck += 2;
        game->turret[i]->range += 1;
    }
}

void upgrade_turret_stat(game_t *game, int i, char **texture_path)
{

    switch (game->turret[i]->which) {
        case 0:
            *texture_path = tower_far_path[game->turret[i]->level];
            game->turret[i]->range += 2;
            game->turret[i]->atck += 1;
            break;
        case 1:
            *texture_path = tower_dmg_path[game->turret[i]->level];
            game->turret[i]->atck += 3;
            break;
        case 2:
            *texture_path = tower_slow_path[game->turret[i]->level];
            game->turret[i]->slow += 10;
            break;
    }
    upgrade_turret_stat_two(game, i, texture_path);
}

void upgrade_turret(game_t *game, int i)
{
    sfTexture *texture;
    char *texture_path = NULL;

    if (game->turret[i]->level == 3 || game->coin < 100)
        return;
    game->turret[i]->level++;
    game->coin -= 100;
    update_coin(game->coin, &game->coin_text);
    upgrade_turret_stat(game, i, &texture_path);
    texture = sfTexture_createFromFile(texture_path, NULL);
    sfSprite_setTexture(game->turret[i]->s_turr, texture, sfTrue);
}
