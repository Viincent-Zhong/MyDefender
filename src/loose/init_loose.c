/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init pause
*/

#include "my.h"
#include "defender.h"
#include <stdlib.h>

void initialise_loose(game_t *game)
{
    sfTexture *texture;

    game->loose = malloc(sizeof(loose_t));
    texture = sfTexture_createFromFile("image/Bouton_pause/back.png", NULL);
    game->loose->background = create_sprite(texture, get_position(0, 0));
    texture = sfTexture_createFromFile("image/Bouton_pause/menu.png", NULL);
    game->loose->menu = create_sprite(texture, get_position(680, 220));
    texture = sfTexture_createFromFile("image/Bouton_pause/restart.png", NULL);
    game->loose->restart = create_sprite(texture, get_position(680, 420));
    texture = sfTexture_createFromFile("image/Bouton_pause/exit.png", NULL);
    game->loose->exit = create_sprite(texture, get_position(680, 620));
    game->loose->button_pressed = sfFalse;

}
