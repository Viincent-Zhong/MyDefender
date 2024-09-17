/*
** EPITECH PROJECT, 2021
** pause_menu
** File description:
** Pause menu
*/

#include "my.h"
#include "defender.h"

void change_pause(game_t *game)
{
    sfFloatRect pos_image_glob;
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    pos_image_glob = sfSprite_getGlobalBounds(game->pause->play);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = start_game;
    pos_image_glob = sfSprite_getGlobalBounds(game->pause->menu);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y)) {
        free_all(game);
        initialisation(game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        game->game_status = start_menu;
    }
    pos_image_glob = sfSprite_getGlobalBounds(game->pause->exit);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = exit_status;
}

void check_mouse_pause(game_t *game)
{
    int focus = sfRenderWindow_hasFocus(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && focus
    && !game->pause->button_pressed) {
        game->pause->button_pressed = sfTrue;
        change_pause(game);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && focus &&
    game->pause->button_pressed)
        game->pause->button_pressed = sfFalse;
}

void pause_menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse_pos.x - 48, mouse_pos.y - 60};

    if (game->game_status != menu_pause)
        return;
    sfSprite_setPosition(game->drag->drag, pos);
    sfRenderWindow_drawSprite(game->window, game->pause->background, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause->play, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause->menu, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause->exit, NULL);
    sfRenderWindow_drawSprite(game->window, game->drag->drag, NULL);
    sfRenderWindow_drawText(game->window, game->score->text_score, NULL);
    check_mouse_pause(game);
    sfRenderWindow_display(game->window);
}
