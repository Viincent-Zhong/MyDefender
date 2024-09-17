/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init pause
*/

#include "my.h"
#include "defender.h"
#include <stdlib.h>

void initialise_pause(game_t *game)
{
    sfTexture *texture;

    game->pause = malloc(sizeof(pause_t));
    texture = sfTexture_createFromFile("image/Bouton_pause/back.png", NULL);
    game->pause->background = create_sprite(texture, get_position(0, 0));
    texture = sfTexture_createFromFile("image/Bouton_pause/resume.png", NULL);
    game->pause->play = create_sprite(texture, get_position(680, 220));
    texture = sfTexture_createFromFile("image/Bouton_pause/menu.png", NULL);
    game->pause->menu = create_sprite(texture, get_position(680, 420));
    texture = sfTexture_createFromFile("image/Bouton_pause/exit.png", NULL);
    game->pause->exit = create_sprite(texture, get_position(680, 620));
    game->pause->button_pressed = sfFalse;

}
