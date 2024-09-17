/*
** EPITECH PROJECT, 2021
** pause_menu
** File description:
** Pause menu
*/

#include "my.h"
#include "defender.h"

void change_loose(game_t *game)
{
    sfFloatRect pos_image_glob;
    sfVector2i pos_mouse = sfMouse_getPosition((sfWindow *)game->window);

    pos_image_glob = sfSprite_getGlobalBounds(game->loose->menu);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y)) {
        free_all(game);
        initialisation(game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        game->game_status = start_menu;
    }
    pos_image_glob = sfSprite_getGlobalBounds(game->loose->restart);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y)) {
        free_all(game);
        initialisation(game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        game->game_status = start_game;
    }
    pos_image_glob = sfSprite_getGlobalBounds(game->loose->exit);
    if (sfFloatRect_contains(&pos_image_glob, pos_mouse.x, pos_mouse.y))
        game->game_status = exit_status;
}

void check_mouse_loose(game_t *game)
{
    int focus = sfRenderWindow_hasFocus(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && focus
    && !game->loose->button_pressed) {
        game->loose->button_pressed = sfTrue;
        change_loose(game);
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft) && focus &&
    game->loose->button_pressed)
        game->loose->button_pressed = sfFalse;
}

void loose_menu(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {mouse_pos.x - 48, mouse_pos.y - 60};

    if (game->game_status != death_menu)
        return;
    sfSprite_setPosition(game->drag->drag, pos);
    sfRenderWindow_drawSprite(game->window, game->loose->background, NULL);
    sfRenderWindow_drawSprite(game->window, game->loose->menu, NULL);
    sfRenderWindow_drawSprite(game->window, game->loose->restart, NULL);
    sfRenderWindow_drawSprite(game->window, game->loose->exit, NULL);
    sfRenderWindow_drawSprite(game->window, game->drag->drag, NULL);
    sfRenderWindow_drawText(game->window, game->score->text_score, NULL);
    check_mouse_loose(game);
    sfRenderWindow_display(game->window);
}
