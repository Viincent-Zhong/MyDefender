/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Menu of the defender
*/

#include "my.h"
#include "defender.h"

void change_menu(game_t *game)
{
    sfFloatRect pos_image_glob;
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    pos_image_glob = sfSprite_getGlobalBounds(game->menu->play);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = start_game;
    pos_image_glob = sfSprite_getGlobalBounds(game->menu->menu);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = htp_menu;
    pos_image_glob = sfSprite_getGlobalBounds(game->menu->exit);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = exit_status;
}

void check_mouse_menu(game_t *game)
{
    int focus = sfRenderWindow_hasFocus(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)
    && focus && !game->menu->button_pressed) {
        game->menu->button_pressed = sfTrue;
        change_menu(game);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft)
    && focus && game->menu->button_pressed)
        game->menu->button_pressed = sfFalse;
}

void menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse_pos.x - 48, mouse_pos.y - 60};

    if (game->game_status != start_menu)
        return;
    sfSprite_setPosition(game->drag->drag, pos);
    sfRenderWindow_drawSprite(game->window, game->menu->background, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->play, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->menu, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu->exit, NULL);
    sfRenderWindow_drawSprite(game->window, game->drag->drag, NULL);
    check_mouse_menu(game);
    sfRenderWindow_display(game->window);
}
