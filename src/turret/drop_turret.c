/*
** EPITECH PROJECT, 2021
** drop_turret
** File description:
** Drop a turret
*/

#include "defender.h"
#include "cursor_path.h"

void define_turret_stat(turret_t **turret, int speed, int atk, int range)
{
    (*turret)->atck = atk;
    (*turret)->range = range;
    (*turret)->slow = speed;
    (*turret)->exist = true;
    (*turret)->level = 0;
}

void detect_which_turret(game_t *game, int i, int status)
{
    switch (status) {
        case 3:
            define_turret_stat(&game->turret[i], 0, 2, 10);
            game->turret[i]->which = far;
            game->turret[i]->attack_sound =
            sfMusic_createFromFile("sound/far_tower.ogg");
            break;
        case 4:
            define_turret_stat(&game->turret[i], 0, 5, 5);
            game->turret[i]->which = dmg;
            game->turret[i]->attack_sound =
            sfMusic_createFromFile("sound/dmg_tower.ogg");
            break;
        case 5:
            define_turret_stat(&game->turret[i], 20, 0, 5);
            game->turret[i]->attack_sound =
            sfMusic_createFromFile("sound/slow_tower.ogg");
            game->turret[i]->which = slow;
            break;
    }
}

int which_turret(game_t *game, int i)
{
    int status = game->drag->drag_status;

    if (status == 3 && game->coin < 50)
        return 1;
    else if (status == 4 && game->coin < 100)
        return 1;
    if (status == 5 && game->coin < 150)
        return 1;
    if (status == 6 && game->coin < 200)
        return 1;
    if (status == 6) {
        game->turret[i]->which = mix;
        define_turret_stat(&game->turret[i], 10, 3, 5);
        game->turret[i]->attack_sound =
        sfMusic_createFromFile("sound/dmg_tower.ogg");
    }
    detect_which_turret(game, i, status);
    return 0;
}

void define_turret(game_t *game, sfVector2f pos, int i)
{
    int status = game->drag->drag_status;

    if (which_turret(game, i) == 1)
        return;
    game->turret[i]->x = pos.x / 60;
    game->turret[i]->y = pos.y / 60;
    game->coin -= (status - 2) * 50;
    pos.x -= 17;
    pos.y -= 64;
    game->drag->turret_pos[i]->dispo = 1;
    game->turret[i]->s_turr =
    create_sprite(sfTexture_createFromFile(
    set_tower_path[game->drag->drag_status], NULL), pos);
    update_coin(game->coin, &game->coin_text);
}
