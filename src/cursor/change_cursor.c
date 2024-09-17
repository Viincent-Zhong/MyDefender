/*
** EPITECH PROJECT, 2021
** change_cursor
** File description:
** Change the cursor
*/

#include "defender.h"
#include "cursor_path.h"

void change_cursor_texture(game_t *game, int detect, char *path)
{
    sfTexture *texture;

    if (game->drag->drag != NULL && (detect < 0 || detect == 2))
        return;
    texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(game->drag->drag, texture, sfTrue);
}

void change_cursor(game_t *game, int detect)
{
    if (detect != -1 && detect != 2 && game->drag->drag_status == -1)
        change_cursor_texture(game, detect, cursor_path[detect]);
    if (game->drag->drag_status == -1)
        game->drag->drag_status = detect;
}