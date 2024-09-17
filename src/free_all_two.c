/*
** EPITECH PROJECT, 2021
** free_all_two
** File description:
** Second file to free everything
*/

#include "defender.h"

void free_five(game_t *game)
{
    if (game->loose != NULL) {
        free_sprite(&game->loose->background);
        free_sprite(&game->loose->exit);
        free_sprite(&game->loose->menu);
        free_sprite(&game->loose->restart);
        free(game->loose);
    }
    if (game->htp != NULL) {
        free_sprite(&game->htp->back);
        free_sprite(&game->htp->background);
        free(game->htp);
    }
}