/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Menu of the defender
*/

#include "my.h"
#include "defender.h"

void change_htp(game_t *game)
{
    sfFloatRect pos_image_glob;
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    pos_image_glob = sfSprite_getGlobalBounds(game->htp->back);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = start_menu;
}

void check_mouse_htp(game_t *game)
{
    int focus = sfRenderWindow_hasFocus(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)
    && focus && !game->htp->button_pressed) {
        game->htp->button_pressed = sfTrue;
        change_htp(game);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft)
    && focus && game->htp->button_pressed)
        game->htp->button_pressed = sfFalse;
}

void htp(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse_pos.x - 48, mouse_pos.y - 60};

    if (game->game_status != htp_menu)
        return;
    sfSprite_setPosition(game->drag->drag, pos);
    sfRenderWindow_drawSprite(game->window, game->htp->background, NULL);
    sfRenderWindow_drawSprite(game->window, game->htp->back, NULL);
    sfRenderWindow_drawText(game->window, game->htp->txt, NULL);
    sfRenderWindow_drawSprite(game->window, game->drag->drag, NULL);
    check_mouse_htp(game);
    sfRenderWindow_display(game->window);
}
