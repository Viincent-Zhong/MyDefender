/*
** EPITECH PROJECT, 2021
** initialise_cursor
** File description:
** Initialise the cursor
*/

#include "defender.h"

void set_default_cursor(game_t *game)
{
    sfTexture *texture =
    sfTexture_createFromFile("image/Cursor/default_cursor.png", NULL);

    if (game->drag->drag_status != -1) {
        sfSprite_setTexture(game->drag->drag, texture, sfTrue);
        game->drag->drag_status = -1;
    }
}

void initialise_cursor(game_t *game)
{
    game->drag->drag = sfSprite_create();
    game->drag->last_turret = 0;
    set_default_cursor(game);
}