/*
** EPITECH PROJECT, 2021
** drag_and_drop
** File description:
** Drag and drop the turret
*/

#include "defender.h"
#include "cursor_path.h"

void drop_turret(sfVector2i mouse_pos, game_t *game)
{
    sfVector2f pos = {0, 0};
    sfVector2f incre = {60, 60};
    int detect = -1;

    for (int i = 0; game->drag->turret_pos[i] != NULL; i++) {
        pos.x = game->drag->turret_pos[i]->turret_posx;
        pos.y = game->drag->turret_pos[i]->turret_posy;
        detect = detect_mouse(mouse_pos, pos, incre);
        if (detect == 1 &&
        game->drag->turret_pos[i]->dispo == 0
        && game->drag->drag_status >= 3 && game->drag->drag_status <= 6)
            define_turret(game, pos, i);
        else if (detect == 1 && game->drag->turret_pos[i]->dispo == 1
        && game->drag->drag_status == 0)
            upgrade_turret(game, i);
        if (detect == 1 && game->drag->turret_pos[i]->dispo == 1 &&
        game->drag->drag_status == 1)
            sell_turret(game, i);
    }
    set_default_cursor(game);
}

void cursor_cannot(sfVector2i mouse_pos, game_t *game)
{
    sfVector2f incre = {60, 60};
    sfVector2f pos = {
        game->drag->turret_pos[game->drag->last_turret]->turret_posx,
        game->drag->turret_pos[game->drag->last_turret]->turret_posy};

    if (detect_mouse(mouse_pos, pos, incre) == 0) {
        change_cursor_texture(game, game->drag->drag_status,
        cursor_path[game->drag->drag_status]);
        game->drag->over = 0;
    }
}

void cursor_can(game_t *game, int i)
{
    if (game->drag->drag_status >= 0 && game->drag->drag_status <= 2)
        if (game->drag->turret_pos[i]->dispo == 0 ||
        game->turret[i]->level == 3)
            return;
    change_cursor_texture(game, game->drag->drag_status,
    cursor_over_path[game->drag->drag_status]);
    game->drag->last_turret = i;
    game->drag->over = 1;
}

void turret_mouseover(sfVector2i mouse_pos, game_t *game)
{
    sfVector2f pos = {0, 0};
    sfVector2f incre = {60, 60};
    int detect = 0;

    for (int i = 0; game->drag->turret_pos[i] != NULL; i++) {
        pos.x = game->drag->turret_pos[i]->turret_posx;
        pos.y = game->drag->turret_pos[i]->turret_posy;
        detect = detect_mouse(mouse_pos, pos, incre);
        if (detect == 1 && game->drag->over == 0 &&
        game->drag->drag_status >= 0)
            cursor_can(game, i);
        else if (detect == 0 && game->drag->over == 1 &&
        game->drag->drag_status >= 0)
            cursor_cannot(mouse_pos, game);
    }
}