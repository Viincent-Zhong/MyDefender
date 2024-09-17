/*
** EPITECH PROJECT, 2021
** gameloop
** File description:
** Gameloop
*/

#include "defender.h"

void draw_cursor(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {0, 0};

    if (game->drag->drag == NULL)
        return;
    pos.x = mouse_pos.x - 48;
    pos.y = mouse_pos.y - 63;
    sfSprite_setPosition(game->drag->drag, pos);
    sfRenderWindow_drawSprite(game->window, game->drag->drag, NULL);
}

void draw_game_sprite(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->map->map_bg, NULL);
    for (int i = 0; game->s_map[i] != NULL; i++)
        sfRenderWindow_drawSprite(game->window, game->s_map[i]->bg_elem, NULL);
    if (game->mobs != NULL)
        printlist(game->mobs, game->window);
    for (int i = 0; game->turret[i] != NULL; i++)
        if (game->turret[i]->exist == true)
            sfRenderWindow_drawSprite
            (game->window, game->turret[i]->s_turr, NULL);
    sfRenderWindow_drawSprite(game->window, game->shop->board, NULL);
    sfRenderWindow_drawSprite(game->window, game->shop->piece, NULL);
    for (int i = 0; game->shop->shop_but[i] != NULL; i++)
        sfRenderWindow_drawSprite
        (game->window, game->shop->shop_but[i]->shop, NULL);
    sfRenderWindow_drawText(game->window, game->coin_text, NULL);
    sfRenderWindow_drawSprite(game->window, game->base->health_bar_s, NULL);
    sfRenderWindow_drawSprite(game->window, game->base->health_bar_bs, NULL);
    draw_cursor(game);
}

void game_central(game_t *game)
{
    if (game->game_status != start_game)
        return;
    sfRenderWindow_clear(game->window, sfYellow);
    draw_game_sprite(game);
    if (game->mobs != NULL) {
        move_every_mobs(game);
        turret_attack(game);
        attack_base(game);
    }
    spawn_mobs(game);
    sfRenderWindow_display(game->window);
}