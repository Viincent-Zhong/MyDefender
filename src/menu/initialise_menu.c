/*
** EPITECH PROJECT, 2021
** My defender
** File description:
** Initialise menu
*/

#include "my.h"
#include "defender.h"
#include <stdlib.h>

sfVector2f get_position(int pos_x, int pos_y)
{
    sfVector2f pos = {pos_x, pos_y};
    return pos;
}

void initialise_htp(game_t *game)
{
    sfTexture *texture;
    sfFont *font = sfFont_createFromFile("image/Font.ttf");

    game->htp = malloc(sizeof(htp_t));
    texture = sfTexture_createFromFile("image/Bouton_menu/back_htp.png", NULL);
    game->htp->background = create_sprite(texture, get_position(0, 0));
    texture = sfTexture_createFromFile("image/Bouton_menu/return.png", NULL);
    game->htp->back = create_sprite(texture, get_position(1750, 50));
    game->htp->txt = sfText_create();
    sfText_setString((game->htp->txt), read_file(".htp.txt"));
    sfText_setFont((game->htp->txt), font);
    sfText_setColor((game->htp->txt), sfBlack);
    sfText_setCharacterSize((game->htp->txt), 40);
    sfText_setPosition((game->htp->txt), get_position(300, 300));
    game->htp->button_pressed = sfFalse;
}

void initialise_menu(game_t *game)
{
    sfTexture *texture;
    sfVector2f pos = {0, 0};

    game->menu = malloc(sizeof(menu_t));
    texture = sfTexture_createFromFile("image/Bouton_menu/back.png", NULL);
    game->menu->background = create_sprite(texture, pos);
    texture = sfTexture_createFromFile("image/Bouton_menu/play.png", NULL);
    game->menu->play = create_sprite(texture, get_position(630, 120));
    texture = sfTexture_createFromFile("image/Bouton_menu/menu.png", NULL);
    game->menu->menu = create_sprite(texture, get_position(630, 440));
    texture = sfTexture_createFromFile("image/Bouton_menu/exit.png", NULL);
    game->menu->exit = create_sprite(texture, get_position(630, 760));
    game->menu->button_pressed = sfFalse;
    initialise_htp(game);
}
